#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

void sort_last_three(t_node **stack)
{
    int a;
    int b;
    int c;

    if (!stack || !(*stack) || !(*stack)->next || !(*stack)->next->next)
        return;
    a = (*stack)->value;
    b = (*stack)->next->value;
    c = (*stack)->next->next->value;
    if (a > b && b < c && a < c)
        s_stack(stack, "sa");
    else if (a > b && b > c)
    {
        s_stack(stack, "sa");
        r_stack(stack, "rra");
    }
    else if (a > b && a > c)
        r_stack(stack, "ra");
    else if (a < b && b > c && a < c)
    {
        s_stack(stack, "sa");
        r_stack(stack, "ra");
    }
    else if (a < b && b > c && a > c)
        rr_stack(stack, "rra");
}

void find_target_node(t_node **a, t_node **b, t_node **target_nodes)
{
    t_node  *temp_b;
    t_node  *temp_a;
    t_node  *target;
    t_node  *smallest;
    
    (void)target_nodes;  // We won't use this anymore
    
    temp_b = *b;
    
    while (temp_b)
    {
        temp_a = *a;
        target = NULL;
        smallest = *a;
        
        while (temp_a)
        {
            if (temp_a->value < smallest->value)
                smallest = temp_a;
                
            if (temp_a->value > temp_b->value)
            {
                if (target == NULL || temp_a->value < target->value)
                    target = temp_a;
            }
            temp_a = temp_a->next;
        }
        
        if (!target)
            target = smallest;
        
        // Store the target VALUE in B's node
        temp_b->target = target->value;
        
        temp_b = temp_b->next;
    }
}

void to_the_top_cost(t_node **stack)
{
    t_node  *current;
    int     size;
    int     cost;

    if (!stack || !*stack)
        return;
    
    current = *stack;
    size = get_stack_size(*stack);
    
    while (current)
    {
        // Cost to rotate this element to the top
        if (current->index <= size / 2)
        {
            // Closer to top: rotate up (positive cost)
            cost = current->index;
        }
        else
        {
            // Closer to bottom: rotate down (negative cost)
            cost = current->index - size;
        }
        
        current->to_top_cost = cost;
        current = current->next;
    }
}

t_node *find_node_by_value(t_node *stack, int value)
{
    while (stack)
    {
        if (stack->value == value)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void calculate_total_costs(t_node *b, t_node *a)  // Pass A instead of target_nodes!
{
    t_node  *current_b;
    t_node  *target_in_a;
    int     b_cost;
    int     a_cost;
    int     total_cost;

    current_b = b;
    
    while (current_b)
    {
        b_cost = current_b->to_top_cost;
        
        // Find the actual target node in A by value
        target_in_a = a;
        while (target_in_a && target_in_a->value != current_b->target)
            target_in_a = target_in_a->next;
        
        if (!target_in_a)
        {
            current_b = current_b->next;
            continue;
        }
        
        a_cost = target_in_a->to_top_cost;
        
        // Check if both rotations are in the same direction
        if ((b_cost > 0 && a_cost > 0) || (b_cost < 0 && a_cost < 0))
        {
            // Same direction: simultaneous rotations
            if (abs(b_cost) > abs(a_cost))
                total_cost = abs(b_cost);
            else
                total_cost = abs(a_cost);
        }
        else
        {
            // Opposite directions: separate rotations
            total_cost = abs(b_cost) + abs(a_cost);
        }
        
        current_b->final_to_top_cost = total_cost;
        current_b = current_b->next;
    }
}

void final_sort(t_node **a)
{
    t_node *temp;
    int smallest_value;
    int size;

    temp = *a;
    smallest_value = (*a)->value;
    size = get_stack_size(*a);
    
    // Find smallest value
    while (temp)
    {
        if (temp->value < smallest_value)
            smallest_value = temp->value;
        temp = temp->next;
    }
    
    // Rotate until smallest is at top
    while ((*a)->value != smallest_value)
    {
        put_pointer_at_start_and_asign_indexs(a);  // Update indexes!
        temp = *a;
        
        // Find smallest node again
        while (temp && temp->value != smallest_value)
            temp = temp->next;
            
        if (temp->index <= size / 2)
            r_stack(a, "ra");
        else
            rr_stack(a, "rra");
    }
}

void push_swap(t_node **a, t_node **b)
{
    t_node  *target_nodes;
    int     size;

    target_nodes = NULL;
    size = get_stack_size(*a);
    
    if (size == 2)
        s_stack(a, "sa");
    else if (size == 3)
        sort_last_three(a);
    else
    {
        // CORRECT: Keep 3 elements in A, push the rest to B
        while (get_stack_size(*a) > 3)  // ✅ Stop when 3 elements remain!
            p_stack(b, a, "pb");
        
        // Sort the 3 remaining elements in A
        sort_last_three(a);
        
        // Now push back from B to A optimally
        while (*b)
        {
            find_target_node(a, b, &target_nodes);
            to_the_top_cost(a);
            to_the_top_cost(b);
            calculate_total_costs(*b, *a);  // ✅ Pass actual stack A, not target_nodes!
            execute_cheapest_move(a, b);
        }
        
        // Final rotation to get smallest at top
        final_sort(a);
    }
}
// continue this article https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

