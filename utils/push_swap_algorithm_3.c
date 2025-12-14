/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:14:39 by malkilan          #+#    #+#             */
/*   Updated: 2025/12/14 17:14:40 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_node_by_value(t_node *stack, int value)
{
	while (stack && stack->value != value)
		stack = stack->next;
	return (stack);
}

void	execute_cheapest_move(t_node **a, t_node **b)
{
	t_node	*cheapest;
	t_node	*target_node;

	cheapest = find_cheapest(*b);
	if (!b || !*b || !(cheapest))
		return ;
	put_pointer_at_start_and_asign_indexs(a);
	put_pointer_at_start_and_asign_indexs(b);
	target_node = *a;
	while (target_node && target_node->value != cheapest->target)
		target_node = target_node->next;
	if (!target_node)
		return ;
	rotate_both_stacks(a, b, cheapest, target_node);
	while ((*b)->value != cheapest->value)
	{
		if (cheapest->index <= get_stack_size(*b) / 2)
			r_stack(b, "rb");
		else
			rr_stack(b, "rrb");
		put_pointer_at_start_and_asign_indexs(b);
	}
	rotate_target_to_top(a, cheapest->target);
	p_stack(a, b, "pa");
}

void	set_final_cost(t_node *curr_b, t_node *target_a, int b_dir, int a_dir)
{
	if (b_dir == a_dir)
		curr_b->final_to_top_cost = ft_fmax(ft_abs(curr_b->to_top_cost),
				ft_abs(target_a->to_top_cost));
	else
		curr_b->final_to_top_cost = ft_abs(curr_b->to_top_cost)
			+ ft_abs(target_a->to_top_cost);
}

void	set_direction(t_node *node, int size, int *direction)
{
	if (node->index <= size / 2)
		*direction = 1;
	else
		*direction = -1;
}

void	put_pointer_at_start_and_asign_indexs(t_node **stack)
{
	int		index;
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	while ((*stack)->prev)
		*stack = (*stack)->prev;
	temp = *stack;
	index = 0;
	while (temp)
	{
		temp->index = index++;
		temp = temp->next;
	}
}
