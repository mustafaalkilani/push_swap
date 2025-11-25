#include "../push_swap.h"

t_node  *find_cheapest(t_node *b)
{
    t_node  *cheapest;
    t_node  *temp;

    cheapest = b;
    temp = b;
    while (temp)
    {
        if (temp->final_to_top_cost < cheapest->final_to_top_cost)
            cheapest = temp;
        temp = temp->next;
    }
    return (cheapest);
}

t_node  *get_target_for_node(t_node *node, t_node *target_nodes, t_node *b)
{
    t_node  *temp_target;
    t_node  *temp_b;

    temp_target = target_nodes;
    temp_b = b;
    while (temp_b && temp_target)
    {
        if (temp_b == node)
            return temp_target;
        temp_b = temp_b->next;
        temp_target = temp_target->next;
    }
    return (NULL);
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

void rotate_target_to_top(t_node **a, t_node *target, int size_a)
{
    t_node *target_in_a;
    
    // Find the actual node in stack A with the target value
    target_in_a = *a;
    while (target_in_a && target_in_a->value != target->value)
        target_in_a = target_in_a->next;
    
    if (!target_in_a)
        return;  // Target not found
    
    // Now rotate until target_in_a is at top
    while ((*a) != target_in_a)
    {
        if (target_in_a->index <= size_a / 2)
            r_stack(a, "ra");
        else
            rr_stack(a, "rra");
    }
}

void    execute_cheapest_move(t_node **a, t_node **b, t_node **target_nodes)
{
    t_node  *cheapest;
    t_node  *target;
    int     size_b;

    cheapest = find_cheapest(*b);
    target = get_target_for_node(cheapest, *target_nodes, *b);
    if (!target)
        return;
    size_b = get_stack_size(*b);
    while (cheapest->index <= size_b / 2 && target->index <= get_stack_size(*a) / 2 
           && (*b) != cheapest && (*a) != target)
        rr(a, b);
    while (cheapest->index > size_b / 2 && target->index > get_stack_size(*a) / 2
           && (*b) != cheapest && (*a) != target)
        rrr(a, b);
    while ((*b) != cheapest)
    {
        if (cheapest->index <= size_b / 2)
            r_stack(b, "rb");
        else
            rr_stack(b, "rrb");
    }
    rotate_target_to_top(a, target, get_stack_size(*a));
    p_stack(a, b, "pa");
}
