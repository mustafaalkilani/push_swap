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
    
    temp_b = *b;
    *target_nodes = NULL;
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
            
        ft_node_add_back(target_nodes, ft_node_new(target->value));
        temp_b = temp_b->next;
    }
    put_pointer_at_start_and_asign_indexs(target_nodes);
}

void    to_the_top_cost(t_node **stack)
{
    int number_of_nodes;
    t_node *temp;

    number_of_nodes = get_stack_size(*stack);
    temp = *stack;
    while (temp)
    {
        if (temp->index <= number_of_nodes / 2)
            temp->to_top_cost = temp->index;
        else
            temp->to_top_cost = (number_of_nodes - temp->index);
        temp = temp->next;
    }
}

void calculate_total_costs(t_node **b, t_node **target_nodes)
{
    t_node *temp_b;
    t_node *temp_target;
    int size_b;
    int size_target;
 
    temp_b = *b;
    temp_target = *target_nodes;
    size_b = get_stack_size(*b);
    size_target = get_stack_size(*target_nodes);
    
    while(temp_b && temp_target)
    {
        int cost_b = temp_b->to_top_cost;
        int cost_target = temp_target->to_top_cost;
        
        // Check if both rotate in same direction
        int both_rotate_up = (temp_b->index <= size_b / 2) && 
                             (temp_target->index <= size_target / 2);
        int both_rotate_down = (temp_b->index > size_b / 2) && 
                               (temp_target->index > size_target / 2);
        
        if (both_rotate_up || both_rotate_down)
        {
            // Can use rr or rrr - cost is the maximum of the two
            temp_b->final_to_top_cost = (cost_b > cost_target) ? cost_b : cost_target;
        }
        else
        {
            // Must rotate separately - cost is the sum
            temp_b->final_to_top_cost = cost_b + cost_target;
        }
        
        temp_b = temp_b->next;
        temp_target = temp_target->next;
    }
}

void final_sort(t_node **a)
{
    t_node *smallest;
    t_node *temp;
    int size;

    smallest = *a;
    temp = *a;
    size = get_stack_size(*a);
    while (temp)
    {
        if (temp->value < smallest->value)
            smallest = temp;
        temp = temp->next;
    }
    while ((*a) != smallest)
    {
        if (smallest->index <= size / 2)
            r_stack(a, "ra");
        else
            rr_stack(a, "rra");
    }
}

void push_swap(t_node **a, t_node **b)
{
    t_node  *target_nodes;

    target_nodes = NULL;
    int size = get_stack_size(*a);

    if (size <= 3)
    {
        sort_last_three(a);
        return;
    }

    while (get_stack_size(*a) > 3)
    {
        p_stack(b, a, "pb");
    }
    while (*b)
    {
        put_pointer_at_start_and_asign_indexs(a);
        put_pointer_at_start_and_asign_indexs(b);
        
        find_target_node(a, b, &target_nodes);
        to_the_top_cost(b);
        to_the_top_cost(&target_nodes);
        calculate_total_costs(b, &target_nodes);
        execute_cheapest_move(a, b, &target_nodes);

        free_stack(&target_nodes);
    }
    final_sort(a);
}

// continue this article https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

