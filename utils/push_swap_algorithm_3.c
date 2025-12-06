#include "../push_swap.h"
#include "../ft_printf/ft_printf.h"
// Add this debug version of execute_cheapest_move to your code
// Replace your current execute_cheapest_move with this

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
	
	// Rotate B to get cheapest to top
	while ((*b)->value != cheapest->value)
	{
		if (cheapest->index <= get_stack_size(*b) / 2)
			r_stack(b, "rb");
		else
			rr_stack(b, "rrb");
		put_pointer_at_start_and_asign_indexs(b);
	}
	
	// Rotate A to get target to top
	rotate_target_to_top(a, cheapest->target);
	p_stack(a, b, "pa");
}
