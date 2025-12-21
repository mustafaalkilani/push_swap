/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:14:10 by malkilan          #+#    #+#             */
/*   Updated: 2025/12/21 14:36:34 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || argv[1][0] == '\0' ||
		(argc == 2 && is_valid_number(argv[1])))
		return (0);
	init_stack(&a, argv + 1);
	if (is_sorted(&a))
		return (0);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
