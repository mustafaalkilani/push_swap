#include "../push_swap.h"

t_node	*find_cheapest(t_node *b)
{
	t_node	*cheapest;
	t_node	*current;
	int		min_cost;

	if (!b)
		return (NULL);
	cheapest = b;
	min_cost = b->final_to_top_cost;
	current = b->next;
	while (current)
	{
		if (current->final_to_top_cost < min_cost)
		{
			min_cost = current->final_to_top_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}

void	to_the_top_cost(t_node **stack)
{
	t_node	*current;
	int		size;
	int		cost;

	if (!stack || !*stack)
		return ;
	current = *stack;
	size = get_stack_size(*stack);
	while (current)
	{
		if (current->index <= size / 2)
			cost = current->index;
		else
			cost = size - current->index;  // ← FIXED: was (current->index - size)
		current->to_top_cost = cost;
		current = current->next;
	}
}

int	get_stack_size(t_node *stack)
{
	int		size;
	t_node	*temp;

	size = 0;
	temp = stack;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

void	rotate_target_to_top(t_node **a, int target_value)
{
	t_node	*target_node;
	int		a_rotate_up;

	if (!a || !*a)
		return ;
	if ((*a)->value == target_value)
		return ;
	put_pointer_at_start_and_asign_indexs(a);
	target_node = *a;
	while (target_node && target_node->value != target_value)
		target_node = target_node->next;
	if (!target_node)
		return ;
	a_rotate_up = (target_node->index <= get_stack_size(*a) / 2);
	while ((*a)->value != target_value)
	{
		if (a_rotate_up)
			r_stack(a, "ra");
		else
			rr_stack(a, "rra");
		put_pointer_at_start_and_asign_indexs(a);
	}
}

void	rotate_both_stacks(t_node **a, t_node **b, t_node *cheapest,
		t_node *target_node)
{
	int	b_rotate_up;
	int	a_rotate_up;

	b_rotate_up = (cheapest->index <= get_stack_size(*b) / 2);
	a_rotate_up = (target_node->index <= get_stack_size(*a) / 2);
	while (b_rotate_up && a_rotate_up && (*b)->value != cheapest->value
		&& (*a)->value != target_node->value)
	{
		rr(a, b);
		put_pointer_at_start_and_asign_indexs(a);
		put_pointer_at_start_and_asign_indexs(b);
	}
	while (!b_rotate_up && !a_rotate_up && (*b)->value != cheapest->value
		&& (*a)->value != target_node->value)
	{
		rrr(a, b);
		put_pointer_at_start_and_asign_indexs(a);
		put_pointer_at_start_and_asign_indexs(b);
	}
}
