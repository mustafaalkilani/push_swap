#include "../push_swap.h"

t_node *find_cheapest(t_node *b)
{
    t_node  *cheapest;
    t_node  *current;
    int     min_cost;

    if (!b)
        return (NULL);
    
    cheapest = b;
    min_cost = b->final_to_top_cost;  // ✅ Use final_to_top_cost
    current = b->next;
    
    while (current)
    {
        if (current->final_to_top_cost < min_cost)  // ✅ Use final_to_top_cost
        {
            min_cost = current->final_to_top_cost;
            cheapest = current;
        }
        current = current->next;
    }
    
    return (cheapest);
}

int get_stack_size(t_node *stack)
{
    int size = 0;
    t_node *temp = stack;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

void rotate_target_to_top(t_node **a, int target_value)
{
    t_node  *target_node;
    int     a_rotate_up;

    if (!a || !*a)
        return;
    
    if ((*a)->value == target_value)
        return;
    
    // Update indices and find target
    put_pointer_at_start_and_asign_indexs(a);
    
    target_node = *a;
    while (target_node && target_node->value != target_value)
        target_node = target_node->next;
    
    if (!target_node)
        return;
    
    // Determine direction ONCE
    a_rotate_up = (target_node->index <= get_stack_size(*a) / 2);
    
    // Rotate until target is at top
    while ((*a)->value != target_value)
    {
        if (a_rotate_up)
            r_stack(a, "ra");
        else
            rr_stack(a, "rra");
        
        put_pointer_at_start_and_asign_indexs(a);
    }
}
void execute_cheapest_move(t_node **a, t_node **b)
{
    t_node  *cheapest;
    int     cheapest_value;
    int     target_value;
    int     b_rotate_up;
    int     a_rotate_up;

    if (!b || !*b)
        return;
    
    // Find cheapest node ONCE
    cheapest = find_cheapest(*b);
    if (!cheapest)
        return;
    
    cheapest_value = cheapest->value;
    target_value = cheapest->target;
    
    // Update indices
    put_pointer_at_start_and_asign_indexs(a);
    put_pointer_at_start_and_asign_indexs(b);
    
    // Re-find nodes after index update
    cheapest = *b;
    while (cheapest && cheapest->value != cheapest_value)
        cheapest = cheapest->next;
    
    t_node *target_node = *a;
    while (target_node && target_node->value != target_value)
        target_node = target_node->next;
    
    if (!cheapest || !target_node)
        return;
    
    // Determine rotation direction ONCE
    b_rotate_up = (cheapest->index <= get_stack_size(*b) / 2);
    a_rotate_up = (target_node->index <= get_stack_size(*a) / 2);
    
    // Simultaneous rotations upward (rr)
    while (b_rotate_up && a_rotate_up && 
           (*b)->value != cheapest_value && 
           (*a)->value != target_value)
    {
        rr(a, b);
        put_pointer_at_start_and_asign_indexs(a);
        put_pointer_at_start_and_asign_indexs(b);
    }
    
    // Simultaneous rotations downward (rrr)
    while (!b_rotate_up && !a_rotate_up && 
           (*b)->value != cheapest_value && 
           (*a)->value != target_value)
    {
        rrr(a, b);
        put_pointer_at_start_and_asign_indexs(a);
        put_pointer_at_start_and_asign_indexs(b);
    }
    
    // Rotate B to top
    while ((*b)->value != cheapest_value)
    {
        if (b_rotate_up)
            r_stack(b, "rb");
        else
            rr_stack(b, "rrb");
        
        put_pointer_at_start_and_asign_indexs(b);
    }
    
    // Rotate target in A to top
    rotate_target_to_top(a, target_value);
    
    // Push from B to A
    p_stack(a, b, "pa");
}