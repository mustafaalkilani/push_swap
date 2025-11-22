#include "push_swap.h"
#include "ft_printf/ft_printf.h"
int main(void)
{
    char *args[] = {"2", "3", "4", NULL};
    t_node *stack_a = NULL;
    init_stack(&stack_a, args);
    for(t_node *current = stack_a; current != NULL; current = current->prev)
    {
        ft_printf("%d\n", current->value);
        free(current);
    }
    return (0);
}