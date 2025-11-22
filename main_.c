#include "push_swap.h"
#include "ft_printf/ft_printf.h"
int main(void)
{
    char *args[] = {"1", "3", "4", "6", NULL};
    t_node *stack_a = NULL;
    init_stack(&stack_a, args);
    ft_printf("Initial stack:\n");
    for (t_node *current = stack_a; current != NULL; current = current->next)
    {
        ft_printf("%d\n", current->value);
    }
    ft_printf("Performing rotate operation:\n");
    rr_stack(&stack_a);
    ft_printf("After rotate:\n");
    t_node *current = stack_a;
    while (current != NULL)
    {
        ft_printf("%d\n", current->value);
        t_node *temp = current->next;
        free(current);
        current = temp;
    }
    return (0);
}