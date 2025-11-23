#include "../push_swap.h"

void	s_stack(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	first->prev = second;
	first->next = third;
	second->prev = NULL;
	second->next = first;
	if (third)
		third->prev = first;
	*stack = second;
}

void    ss(t_node **a, t_node **b)
{
    s_stack(a);
    s_stack(b);
}

void	r_stack(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next->next = NULL;
}

void    rr(t_node **a, t_node **b)
{
    r_stack(a);
    r_stack(b);
}

void    p_stack(t_node **stack_one, t_node **stack_two)
{
    t_node *temp;
    
    if (!stack_one || !*stack_one)
        return;
    temp = *stack_one;
    *stack_one = (*stack_one)->next;
    if (*stack_one)
        (*stack_one)->prev = NULL;
    temp->prev = NULL;
    temp->next = *stack_two;
    if (*stack_two)
        (*stack_two)->prev = temp;
    *stack_two = temp;
}
