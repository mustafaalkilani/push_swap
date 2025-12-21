/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:15:00 by malkilan          #+#    #+#             */
/*   Updated: 2025/12/21 16:19:01 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

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

void	rrr(t_node **a, t_node **b, int flag)
{
	rr_stack(a, NULL);
	rr_stack(b, NULL);
	if (flag)
	{
		ft_putstr_fd("rrr", 1);
		ft_putchar_fd('\n', 1);
	}
}
