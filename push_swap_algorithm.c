#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

void	sort_last_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !(*stack) || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		s_stack(stack, "sa");
	else if (a > b && b > c)
	{
		s_stack(stack, "sa");
		r_stack(stack, "rra");
	}
	else if (a > b && a > c)
		r_stack(stack, "ra");
	else if (a < b && b > c && a < c)
	{
		s_stack(stack, "sa");
		r_stack(stack, "ra");
	}
	else if (a < b && b > c && a > c)
		rr_stack(stack, "rra");
}

void	find_target_node(t_node **a, t_node **b)
{
	t_node	*temp_b;
	t_node	*temp_a;
	t_node	*target;
	t_node	*smallest;

	temp_b = *b;
	while (temp_b)
	{
		temp_a = *a;
		target = NULL;
		smallest = *a;
		while (temp_a)
		{
			if (temp_a->value < smallest->value)
				smallest = temp_a;
			if (temp_a->value > temp_b->value && (target == NULL
					|| temp_a->value < target->value))
				target = temp_a;
			temp_a = temp_a->next;
		}
		if (!target)
			target = smallest;
		temp_b->target = target->value;
		temp_b = temp_b->next;
	}
}

void	calculate_total_costs(t_node *b, t_node *a)
{
	t_node	*current_b;
	t_node	*target_in_a;
	int		b_cost;
	int		a_cost;

	current_b = b;
	while (current_b)
	{
		b_cost = current_b->to_top_cost;
		target_in_a = a;
		while (target_in_a && target_in_a->value != current_b->target)
			target_in_a = target_in_a->next;
		if (target_in_a)
		{
			a_cost = target_in_a->to_top_cost;
			if ((b_cost > 0 && a_cost > 0) || (b_cost < 0 && a_cost < 0))
				current_b->final_to_top_cost = ft_fmax(ft_abs(b_cost), ft_abs(a_cost));
			else
				current_b->final_to_top_cost = ft_abs(b_cost) + ft_abs(a_cost);
		}
		current_b = current_b->next;
	}
}

void	final_sort(t_node **a)
{
	t_node	*temp;
	int		smallest_value;
	int		size;

	temp = *a;
	smallest_value = (*a)->value;
	size = get_stack_size(*a);
	while (temp)
	{
		if (temp->value < smallest_value)
			smallest_value = temp->value;
		temp = temp->next;
	}
	while ((*a)->value != smallest_value)
	{
		put_pointer_at_start_and_asign_indexs(a);
		temp = *a;
		while (temp && temp->value != smallest_value)
			temp = temp->next;
		if (temp->index <= size / 2)
			r_stack(a, "ra");
		else
			rr_stack(a, "rra");
	}
}

void	push_swap(t_node **a, t_node **b)
{
	int	size;

	size = get_stack_size(*a);
	if (size == 2)
		s_stack(a, "sa");
	else if (size == 3)
		sort_last_three(a);
	else
	{
		while (get_stack_size(*a) > 3)
			p_stack(b, a, "pb");
		sort_last_three(a);
		while (*b)
		{
			put_pointer_at_start_and_asign_indexs(a);
			put_pointer_at_start_and_asign_indexs(b); 
			find_target_node(a, b);
			to_the_top_cost(a);
			to_the_top_cost(b);
			calculate_total_costs(*b, *a);
			execute_cheapest_move(a, b);
		}
		final_sort(a);
	}
}
// continue this article https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
