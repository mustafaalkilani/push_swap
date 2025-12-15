*This project has been created as part of the 42 curriculum by malkilan.*

# push_swap

## Description

`push_swap` is a sorting algorithm optimization project that challenges you to sort data on a stack with a limited set of operations, using the fewest moves possible.

### Goal

The objective is to write a program that sorts a random list of integers using two stacks (a and b) and a minimal number of operations. This project emphasizes algorithmic efficiency, memory management, and understanding sorting strategies under constraints.

### How It Works

The program receives a list of integers as arguments and must sort them in ascending order in stack `a`, using only the following operations:

**Stack Operations:**
- `sa` / `sb` / `ss` — Swap (exchange the first two elements)
- `pa` / `pb` — Push (move the first element from one stack to the other)
- `ra` / `rb` / `rr` — Rotate (move the first element to the end)
- `rra` / `rrb` / `rrr` — Reverse rotate (move the last element to the top)

The algorithm implementation uses the **Turk Algorithm**, a sophisticated approach that calculates the cost of moving each element and selects the most efficient moves to minimize total operations.

### Key Features

- Handles edge cases: duplicate detection, range validation (INT_MIN to INT_MAX)
- Implements the Turk algorithm for optimal cost calculation
- Performance benchmarks: sorts 100 numbers in <1,500 operations, 500 numbers in <5,500 operations
- Full compliance with 42 School coding norm (25-line function limit, strict style rules)
- Memory-safe: no leaks, proper cleanup with error handling
- Bonus: includes a checker program to validate sorting correctness

---

## Instructions

### Compilation

```bash
make
```

This compiles the program using a Makefile with the following rules:
- `make` — Compiles the push_swap executable
- `make clean` — Removes object files
- `make fclean` — Removes all generated files
- `make re` — Recompiles from scratch

### Execution

```bash
./push_swap [list of integers]
```

**Examples:**

```bash
./push_swap 3 2 1
./push_swap 5 4 3 2 1
./push_swap 100 -50 42 0
```

The program outputs a sequence of operations that will sort the stack.

### Running the Checker (Bonus)

```bash
make bonus
./checker [list of integers]
```

After compilation of the checker, you can pipe the output of push_swap to validate it:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```
---

### Algorithm: The Turk Strategy

The implementation uses a cost-based approach to sorting:

1. **Target Assignment** — For each element in stack b, find its target position in stack a
2. **Cost Calculation** — Calculate the cost (number of operations) to move each element, considering both stacks
3. **Cheapest Move Selection** — Select the element with the lowest total cost
4. **Execution** — Perform optimized rotations and pushes
5. **Final Sort** — Apply specialized sorting for the last 3 elements

This greedy algorithm ensures near-optimal sorting with minimal operations.

---

## Resources

### Classic References

- **Sorting Algorithms**: 
  - Introduction to Algorithms (CLRS) — Chapter 2 (Getting Started)
  - [GeeksforGeeks: Sorting Algorithms](https://www.geeksforgeeks.org/sorting-algorithms/)

- **Stack Data Structures**:
  - [Wikipedia: Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
  - [Cplusplus.com: Stack](https://www.cplusplus.com/reference/stack/stack/)

- **Algorithm Optimization**:
  - [Big O Notation Explained](https://www.bigocheatsheet.com/)
  - [Stack-Based Sorting Strategies](https://en.wikipedia.org/wiki/Sorting_algorithm)

- **42 School Resources**:
  - [42 Curriculum Documentation](https://42.fr)
  - [42 Intranet](https://intra.42.fr)

---

## AI Usage

AI was utilized in the following capacities during this project:

### Tasks and Components

1. **Debugging**
2 .**Creating this README.md**
**Important Note**: While AI provided guidance and debugging assistance, all core algorithm logic, implementation, and problem-solving was done independently. AI served as a learning tool and reference for verification, not as a primary development resource.

---

## Building and Testing

### Quick Start

```bash
# Compile the project
make

# Test with a small list
./push_swap 3 2 1

# Validate with the checker
./push_swap 3 2 1 | ./checker 3 2 1

# Test for memory leaks
valgrind --leak-check=full ./push_swap 3 2 1

# Performance test (100 random numbers)
ARG=$(shuf -i 1-100 -n 100); ./push_swap $ARG | wc -l
```

### Performance Benchmarks

- **3 numbers**: < 3 operations
- **5 numbers**: < 12 operations
- **100 numbers**: < 1,500 operations
- **500 numbers**: < 5,500 operations

---

## 42 School Compliance

This project strictly adheres to 42's coding standards:

- **Norm**: Functions ≤ 25 lines
- **Variables**: Declared at the start of blocks
- **Memory**: No leaks, proper error handling
- **Style**: Consistent formatting, meaningful names
- **Makefile**: Relinks only when necessary

---

## Author

**malkilan** — Networks and Information Security Engineering Student, Princess Sumaya University for Technology (PSUT)

---

*Last Updated: December 2025*