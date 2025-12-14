#include "../push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
int	is_sorted(t_node **stack, int should_free_argv, char **argv)
{
	t_node	*current;

	if (!stack || !*stack)
		return (1);
	current = *stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	if (should_free_argv)
		free_split(argv);
	return (1);
}
