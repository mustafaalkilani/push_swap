/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:13:57 by malkilan          #+#    #+#             */
/*   Updated: 2025/12/14 17:21:17 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	free_and_exit(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (new_node)
		free(new_node);
	if (*stack)
	{
		while ((*stack)->prev)
			*stack = (*stack)->prev;
		while (*stack)
		{
			temp = *stack;
			*stack = (*stack)->next;
			free(temp);
		}
	}
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	handle_repetitions(t_node *stack, int value)
{
	t_node	*current;
	t_node	*temp;

	if (!stack)
		return (0);
	while (stack->prev)
		stack = stack->prev;
	current = stack;
	while (current)
	{
		temp = stack;
		while (temp)
		{
			if (temp->value == value && temp != current)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

static void	add_node_to_stack(t_node **stack, t_node *new_node)
{
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		(*stack)->next = new_node;
		new_node->prev = *stack;
		*stack = new_node;
	}
}

static void	validate_and_add(t_node **stack, t_node *new_node, char *arg)
{
	long	value;

	value = ft_atol(arg);
	if (value == LLONG_MAX || (value > INT_MAX || value < INT_MIN))
		free_and_exit(stack, new_node);
	new_node->value = (int)value;
	if (handle_repetitions(*stack, new_node->value))
		free_and_exit(stack, new_node);
	new_node->next = NULL;
	add_node_to_stack(stack, new_node);
}

void	init_stack(t_node **stack, char **argv)
{
	int		i;
	t_node	*new_node;

	i = -1;
	while (argv[++i])
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		if (!new_node)
			free_and_exit(stack, new_node);
		validate_and_add(stack, new_node, argv[i]);
	}
	put_pointer_at_start_and_asign_indexs(stack);
}
