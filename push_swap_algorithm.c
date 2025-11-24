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
        sa(stack);
    else if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if (a > b && a > c)
        ra(stack);
    else if (a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if (a < b && b > c && a > c)
        rra(stack);
}

t_node  *find_target_node(t_node *a, int value_from_b)
{
    t_node  *target;
    t_node  *temp;
    
    target = NULL;
    temp = a;
    
    while (temp)
    {
        if (temp->value > value_from_b)
        {
            if (target == NULL || temp->value < target->value)
                target = temp;
        }
        temp = temp->next;
    }
    return (target);
}

void push_swap(t_node **a, t_node **b)
{
    t_node *temp;
    t_node *target_nodes;

    temp = *a;
    target_nodes = NULL;
    while (temp->next->next->next != NULL)
    {
        p_stack(a, b);
        temp = *a;
    }
    sort_last_three(a);
    find_the_target_node(a, b, &target_nodes);
}

// continue this article https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

