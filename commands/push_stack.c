#include "../push_swap.h"

void    p_stack(t_node **stack_one, t_node **stack_two)
{
    t_node *temp;
    
    if (!stack_one || !*stack_one)
        return;
    temp = *stack_one;
    *stack_one = (*stack_one)->next;
    if (*stack_one)
        (*stack_one)->prev = NULL;
    temp->prev = NULL;
    temp->next = *stack_two;
    if (*stack_two)
        (*stack_two)->prev = temp;
    *stack_two = temp;
}
