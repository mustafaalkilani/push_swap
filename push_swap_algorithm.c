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

void push_swap(t_node **a, t_node **b)
{
    t_node *temp;

    temp = *a;
    while (temp->next->next->next != NULL)
    {
        p_stack(a, b);
        temp = *a;
    }
    sort_last_three(a);
}

// continue this article https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

