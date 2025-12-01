#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

void	print_stack(t_node *stack, char *stack_name)
{
	t_node	*temp;

	ft_printf("\n=== Stack %s ===\n", stack_name);
	if (!stack)
	{
		ft_printf("(empty)\n");
		return ;
	}
	temp = stack;
	while (temp)
	{
		ft_printf("value: %d | index: %d | to_top_cost: %d | target: %d | final_cost: %d\n",
			temp->value, temp->index, temp->to_top_cost, temp->target, temp->final_to_top_cost);
		temp = temp->next;
	}
}

void	print_cheapest_info(t_node *b, t_node *a)
{
	t_node	*cheapest;
	t_node	*target_node;

	cheapest = find_cheapest(b);
	if (!cheapest)
	{
		ft_printf("No cheapest node found!\n");
		return ;
	}
	ft_printf("\n>>> CHEAPEST NODE <<<\n");
	ft_printf("Value: %d | Index: %d | Cost: %d | Target: %d\n",
		cheapest->value, cheapest->index, cheapest->final_to_top_cost, cheapest->target);
	
	target_node = a;
	while (target_node && target_node->value != cheapest->target)
		target_node = target_node->next;
	
	if (target_node)
		ft_printf("Target found in A: value %d at index %d\n", target_node->value, target_node->index);
	else
		ft_printf("ERROR: Target value %d NOT FOUND in stack A!\n", cheapest->target);
}

void	debug_execute_cheapest_move(t_node **a, t_node **b)
{
	t_node	*cheapest;
	t_node	*target_node;

	print_stack(*a, "A");
	print_stack(*b, "B");
	
	cheapest = find_cheapest(*b);
	if (!b || !*b || !(cheapest))
	{
		ft_printf("ERROR: No cheapest node!\n");
		return ;
	}
	
	put_pointer_at_start_and_asign_indexs(a);
	put_pointer_at_start_and_asign_indexs(b);
	
	target_node = *a;
	while (target_node && target_node->value != cheapest->target)
		target_node = target_node->next;
	
	if (!target_node)
	{
		ft_printf("\n!!! CRITICAL ERROR !!!\n");
		ft_printf("Cheapest node value: %d\n", cheapest->value);
		ft_printf("Cheapest target: %d\n", cheapest->target);
		ft_printf("Stack A contents:\n");
		t_node *temp = *a;
		while (temp)
		{
			ft_printf("  - %d\n", temp->value);
			temp = temp->next;
		}
		ft_printf("Target value %d not found in stack A!\n", cheapest->target);
		return ;
	}
	
	print_cheapest_info(*b, *a);
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
	ft_printf("\n--- After move ---\n");
	print_stack(*a, "A");
	print_stack(*b, "B");
}

void	debug_push_swap(t_node **a, t_node **b)
{
	int	size;
	int	move_count;

	size = get_stack_size(*a);
	move_count = 0;
	ft_printf("\n========== STARTING PUSH_SWAP ==========\n");
	ft_printf("Initial stack size: %d\n", size);
	
	if (size == 2)
		s_stack(a, "sa");
	else if (size == 3)
		sort_last_three(a);
	else
	{
		while (get_stack_size(*a) > 3)
		{
			ft_printf("\n--- PUSH PHASE: Move %d ---\n", ++move_count);
			p_stack(b, a, "pb");
			print_stack(*a, "A");
			print_stack(*b, "B");
		}
		ft_printf("\n--- SORT LAST 3 ---\n");
		sort_last_three(a);
		print_stack(*a, "A");
		
		ft_printf("\n========== PUSHING BACK PHASE ==========\n");
		while (*b)
		{
			ft_printf("\n--- MOVE %d ---\n", ++move_count);
			find_target_node(a, b);
			to_the_top_cost(a);
			to_the_top_cost(b);
			calculate_total_costs(*b, *a);
			debug_execute_cheapest_move(a, b);
		}
		final_sort(a);
	}
	ft_printf("\n========== FINAL RESULT ==========\n");
	print_stack(*a, "A (FINAL)");
}
