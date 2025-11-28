#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "push_swap.h"

static void free_and_exit(t_node **stack, t_node *new_node)
{
    t_node *temp;

    if (new_node)
        free(new_node);
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
    ft_printf("Error\n");
    exit(1);
}

static int	handle_repetitions(t_node *stack, int value)
{
	t_node	*current;

	current = stack;
	while (current != NULL)
	{
		if (current->value == value)
        {
			return (0);
        }
		current = current->prev;
	}
	return (1);
}

static int	handle_overflow(long value)
{
	if (value > INT_MAX || value < INT_MIN)
    {
		return (0);
    }
	return (1);
}

void put_pointer_at_start_and_asign_indexs(t_node **stack)
{
    int     index;
    t_node  *temp;

    if (!stack || !*stack)
        return;
    index = 0;    
    while ((*stack)->prev)
        *stack = (*stack)->prev;
    temp = *stack;
    while (temp)
    {
        temp->index = index;
        index++;
        temp = temp->next;
    }    
}

void init_stack(t_node **stack, char **argv)
{
    int     i;
    t_node  *new_node;
    i = -1;
    while (argv[++i])
    {        
        new_node = (t_node *)malloc(sizeof(t_node));
        if (!new_node)
            return (free_and_exit(stack, new_node));
        if (!handle_overflow(ft_atol(argv[i])))
            return (free_and_exit(stack, new_node));
        new_node->value = ft_atoi(argv[i]);        
        if (!handle_repetitions(*stack, new_node->value))
            return (free_and_exit(stack, new_node));        
        new_node->next = NULL;
        new_node->prev = NULL;
        if (*stack == NULL)
            *stack = new_node;
        else
        {
            (*stack)->next = new_node;
            new_node->prev = *stack;
            *stack = new_node;
        }
    }
    put_pointer_at_start_and_asign_indexs(stack);
}
