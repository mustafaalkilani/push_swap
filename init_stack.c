#include "push_swap.h"
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"


void    free_and_return(t_node *new_node)
{
    free(new_node);
    ft_printf("Error\n");
    return;
}

int handle_repetitions(t_node *a, int value)
{
    t_node *current = a;
    while (current != NULL)
    {
        if (current->value == value)
            return (0);
        current = current->prev;
    }
    return (1);
}

void    init_stack(t_node **a, char ** argv)
{
    int i;

    i = -1;
    while (argv[++i])
    {
        t_node *new_node = (t_node *)malloc(sizeof(t_node));
        if (!new_node)
            return (free_and_return(new_node));
        new_node->value = ft_atoi(argv[i]);
        if (!handle_repetitions(*a, new_node->value)) // dont forget to check if you should check for the overflow ??!!
            return (free_and_return(new_node));
        new_node->next = NULL;
        new_node->prev = NULL;
        if (*a == NULL)
            *a = new_node;
        else
        {
            (*a)->next = new_node;
            new_node->prev = *a;
            *a = new_node;
        }
    }
}
