/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:15:26 by malkilan          #+#    #+#             */
/*   Updated: 2025/12/14 17:15:27 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "./push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || argv[1][0] == '\0')
		return (0);
	init_stack(&a, argv + 1);
	process_instructions(&a, &b);
	return (0);
}
