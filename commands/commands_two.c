#include "../push_swap.h"
#include "../libft/libft.h"

void	rr_stack(t_node **stack, char *operation)
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
	if (operation)
	{
			ft_putstr_fd(operation, 1);
			ft_putchar_fd('\n', 1);
	}
}

void	rrr(t_node **a, t_node **b)
{
	rr_stack(a, NULL);
	rr_stack(b, NULL);
	ft_putstr_fd("rrr", 1);
	ft_putchar_fd('\n', 1);
}
