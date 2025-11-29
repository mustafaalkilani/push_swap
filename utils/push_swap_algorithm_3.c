#include "../push_swap.h"

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
