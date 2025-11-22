#include "../push_swap.h"

void	rr_stack(t_node **stack)
{
	t_node	*first;
	t_node	*second_last;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	first->prev = last;
	last->next = first;
	last->prev = NULL;
	second_last->next = NULL;
	*stack = last;
}
