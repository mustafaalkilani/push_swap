#include "libft/libft.h"
#include "push_swap.h"

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

static void	free_split(char **split)
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

static int	is_sorted(t_node **stack, int should_free_argv, char **argv)
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

int	main(int argc, char **argv)
{
	int		should_free_argv;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	should_free_argv = 0;
	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		should_free_argv = 1;
	}
	if (!should_free_argv)
		argv++;
	init_stack(&a, argv);
	if (is_sorted(&a, should_free_argv, argv))
		return (0);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	if (should_free_argv)
		free_split(argv);
	return (0);
}
