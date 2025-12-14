/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:15:05 by malkilan          #+#    #+#             */
/*   Updated: 2025/12/14 17:15:07 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../push_swap.h"

void	s_stack(t_node **stack, char *operation)
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
	if (operation)
	{
		ft_putstr_fd(operation, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ss(t_node **a, t_node **b)
{
	s_stack(a, NULL);
	s_stack(b, NULL);
	ft_putstr_fd("ss", 1);
	ft_putchar_fd('\n', 1);
}

void	r_stack(t_node **stack, char *operation)
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
	if (operation)
	{
		ft_putstr_fd(operation, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	rr(t_node **a, t_node **b)
{
	r_stack(a, NULL);
	r_stack(b, NULL);
	ft_putstr_fd("rr", 1);
	ft_putchar_fd('\n', 1);
}

void	p_stack(t_node **stack_to, t_node **stack_from, char *operation)
{
	t_node	*temp;

	if (!stack_from || !*stack_from)
		return ;
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (*stack_from)
		(*stack_from)->prev = NULL;
	temp->prev = NULL;
	temp->next = *stack_to;
	if (*stack_to)
		(*stack_to)->prev = temp;
	*stack_to = temp;
	if (operation)
	{
		ft_putstr_fd(operation, 1);
		ft_putchar_fd('\n', 1);
	}
}
