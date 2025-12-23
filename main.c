/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:14:10 by malkilan          #+#    #+#             */
/*   Updated: 2025/12/23 13:28:04 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	long	value;

	a = NULL;
	b = NULL;
	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	if (!is_valid_number(argv[1]))
		free_and_exit(&a, NULL);
	if (argc == 2)
	{
		value = ft_atol(argv[1]);
		if (value == LLONG_MAX || value > INT_MAX || value < INT_MIN)
			free_and_exit(&a, NULL);
		return (0);
	}
	init_stack(&a, argv + 1);
	if (is_sorted(&a))
		return (0);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
