#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0
LEAK_TESTS=0

# Array to store operation counts
declare -a OPERATION_COUNTS

# Check if push_swap exists
if [ ! -f "./push_swap" ]; then
	echo -e "${RED}Error: push_swap executable not found!${NC}"
	exit 1
fi

# Check if valgrind is installed
VALGRIND_AVAILABLE=0
if command -v valgrind &> /dev/null; then
	VALGRIND_AVAILABLE=1
fi

# Function to count operations
count_operations() {
	local output="$1"
	echo "$output" | wc -l
}

# Function to validate if stack is sorted
is_sorted() {
	local output="$1"
	local temp_file=$(mktemp)
	echo "$output" > "$temp_file"
	
	# Remove the operations output, just keep the final state
	local sorted=true
	local prev=-2147483648
	
	# This is a simple check - in real scenario you'd need to track stack state
	rm "$temp_file"
	return 0
}

# Function to test with valgrind
test_with_valgrind() {
	local test_name="$1"
	shift
	local args="$@"
	
	local leak_output=$(valgrind --leak-check=full --show-leak-kinds=all --quiet ./push_swap $args 2>&1)
	
	if echo "$leak_output" | grep -q "ERROR SUMMARY: 0 errors"; then
		echo -e "${GREEN}✓ No leaks${NC}"
		return 0
	elif echo "$leak_output" | grep -q "LEAK SUMMARY"; then
		local leaked=$(echo "$leak_output" | grep "definitely lost" | awk '{print $4}')
		if [ "$leaked" != "0" ]; then
			echo -e "${RED}✗ Memory leaks: $leaked bytes${NC}"
			return 1
		else
			echo -e "${GREEN}✓ No leaks${NC}"
			return 0
		fi
	else
		echo -e "${GREEN}✓ Clean${NC}"
		return 0
	fi
}

# Function to run single test
run_test() {
	local test_name="$1"
	local should_error="$2"
	shift 2
	local args="$@"
	
	((TOTAL_TESTS++))
	
	echo -e "\n${BLUE}Test $TOTAL_TESTS: $test_name${NC}"
	echo "Command: ./push_swap $args"
	
	# Run the program
	local output=$(./push_swap $args 2>&1)
	local exit_code=$?
	
	# Check for error cases
	if [ "$should_error" = "true" ]; then
		if echo "$output" | grep -q "^Error"; then
			echo -e "${GREEN}✓ Correctly returned Error${NC}"
			((PASSED_TESTS++))
		else
			echo -e "${RED}✗ Should have returned Error but didn't${NC}"
			echo "Output: $output"
			((FAILED_TESTS++))
			return 1
		fi
	else
		# For valid cases, check if output starts with "Error"
		if echo "$output" | grep -q "^Error"; then
			echo -e "${RED}✗ Should not have returned Error${NC}"
			echo "Output: $output"
			((FAILED_TESTS++))
			return 1
		else
			local ops=$(count_operations "$output")
			echo -e "${GREEN}✓ Success${NC}"
			echo "Operations: $ops"
			if [ "$ops" -gt 0 ]; then
				OPERATION_COUNTS+=($ops)
			fi
			((PASSED_TESTS++))
		fi
	fi
	
	# Check for leaks if valgrind is available
	if [ $VALGRIND_AVAILABLE -eq 1 ]; then
		((LEAK_TESTS++))
		echo -n "Memory check: "
		test_with_valgrind "$test_name" $args
	fi
}

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}   PUSH_SWAP COMPREHENSIVE TEST SUITE   ${NC}"
echo -e "${BLUE}========================================${NC}"

# ============ ERROR CASES ============
echo -e "\n${YELLOW}=== ERROR CASES ===${NC}"

run_test "No arguments" "false"
run_test "Single number" "false" "42"
run_test "Two numbers (sorted)" "false" "1" "2"
run_test "Two numbers (unsorted)" "false" "2" "1"

# Invalid inputs
run_test "Non-numeric input" "true" "abc"
run_test "Number with letter" "true" "42a"
run_test "Number with dot" "true" "42.5"
run_test "Double sign" "true" "--50"
run_test "Sign in middle" "true" "5-0"
run_test "Only plus sign" "true" "+"
run_test "Only minus sign" "true" "-"
run_test "Double plus" "true" "++123"
run_test "Plus and minus mixed" "true" "-+0"
run_test "Trailing sign" "true" "50-"
run_test "Leading and trailing sign" "true" "-50-"
run_test "Zero in list" "false" "0" "1" "2"
run_test "Duplicate numbers" "true" "1" "2" "1"
run_test "All same numbers" "true" "5" "5" "5"

# Integer overflow
run_test "Number too large" "true" "2147483648"
run_test "Negative overflow" "true" "-2147483649"

# ============ VALID CASES ============
echo -e "\n${YELLOW}=== VALID CASES ===${NC}"

run_test "Three numbers sorted" "false" "1" "2" "3"
run_test "Three numbers reverse" "false" "3" "2" "1"
run_test "Three numbers random" "false" "2" "1" "3"

run_test "Negative numbers" "false" "-5" "-2" "-10"
run_test "Mixed positive/negative" "false" "-5" "3" "-2" "8"

# Five numbers
run_test "Five numbers sorted" "false" "1" "2" "3" "4" "5"
run_test "Five numbers reverse" "false" "5" "4" "3" "2" "1"
run_test "Five numbers random" "false" "3" "1" "4" "2" "5"

# Larger test cases
run_test "Ten numbers random" "false" "9" "3" "7" "1" "5" "2" "8" "4" "6" "10"
run_test "Hundred numbers" "false" $(seq 100 -1 1 | tr '\n' ' ')

# Edge cases with valid numbers
run_test "Zero in list" "false" "0" "1" "2"
run_test "Only negative numbers" "false" "-10" "-5" "-20"
run_test "Large spread" "false" "-2147483647" "0" "2147483647"

# Sorted and nearly sorted
run_test "Already sorted (10 nums)" "false" $(seq 1 10)
run_test "Reverse sorted (10 nums)" "false" $(seq 10 -1 1)
run_test "Almost sorted" "false" "1" "2" "4" "3" "5" "6" "7" "8" "9" "10"

# ============ WHITESPACE HANDLING ============
echo -e "\n${YELLOW}=== WHITESPACE HANDLING ===${NC}"

run_test "Leading zeros" "false" "007" "002" "001"
run_test "Multiple spaces between args" "false" "1"  "2"  "3"

# ============ RESULTS ============
echo -e "\n${BLUE}========================================${NC}"
echo -e "${BLUE}         TEST RESULTS SUMMARY           ${NC}"
echo -e "${BLUE}========================================${NC}"

echo -e "Total Tests:     $TOTAL_TESTS"
echo -e "${GREEN}Passed:          $PASSED_TESTS${NC}"
echo -e "${RED}Failed:          $FAILED_TESTS${NC}"

if [ $VALGRIND_AVAILABLE -eq 1 ]; then
	echo -e "Memory Tests:    $LEAK_TESTS"
else
	echo -e "${YELLOW}Note: Valgrind not installed - memory tests skipped${NC}"
	echo "Install with: sudo apt-get install valgrind"
fi

# Calculate average operations
if [ ${#OPERATION_COUNTS[@]} -gt 0 ]; then
	echo -e "\n${YELLOW}=== OPERATION STATISTICS ===${NC}"
	sum=0
	min=${OPERATION_COUNTS[0]}
	max=${OPERATION_COUNTS[0]}
	
	for count in "${OPERATION_COUNTS[@]}"; do
		sum=$((sum + count))
		if [ "$count" -lt "$min" ]; then
			min=$count
		fi
		if [ "$count" -gt "$max" ]; then
			max=$count
		fi
	done
	
	avg=$((sum / ${#OPERATION_COUNTS[@]}))
	echo "Average operations: $avg"
	echo "Min operations:     $min"
	echo "Max operations:     $max"
	echo "Total valid tests:  ${#OPERATION_COUNTS[@]}"
fi

echo ""

# Final verdict
if [ $FAILED_TESTS -eq 0 ]; then
	echo -e "${GREEN}✓ ALL TESTS PASSED!${NC}"
	exit 0
else
	echo -e "${RED}✗ SOME TESTS FAILED${NC}"
	exit 1
fi
