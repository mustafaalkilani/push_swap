#include "libft/libft.h"
#include "push_swap.h"

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
	init_stack(&a, argv);  // Much simpler
	if (is_sorted(&a, should_free_argv, argv))
		return (0);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	if (should_free_argv)
		free_split(argv);
	return (0);
}
