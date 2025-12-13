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
		rr_stack(stack, "rra");
	}
	else if (a > b && a > c && b < c)
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
	t_node	*curr_b;
	t_node	*target_a;
	int		b_dir;
	int		a_dir;

	curr_b = b;
	while (curr_b)
	{
		target_a = find_node_by_value(a, curr_b->target);
		if (target_a)
		{
			set_direction(curr_b, get_stack_size(b), &b_dir);
			set_direction(target_a, get_stack_size(a), &a_dir);
			set_final_cost(curr_b, target_a, b_dir, a_dir);
		}
		curr_b = curr_b->next;
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
