#include "push_swap.h"
#include "ft_printf/ft_printf.h"
int main(void)
{
    char *args[] = {"1", "3", "4", "6", NULL};
    char *args2[] = {"2", "5", "8", "7", NULL};
    t_node *stack_a = NULL;
    t_node *stack_b = NULL;
    init_stack(&stack_a, args);
    init_stack(&stack_b, args2);
    ft_printf("Initial stack:\n");
    for (t_node *current = stack_a; current != NULL; current = current->next)
    {
        ft_printf("%d\n", current->value);
    }
    ft_printf("Performing rotate operation:\n");
    p_stack(&stack_a, &stack_b);
    p_stack(&stack_a, &stack_b);
    ft_printf("After rotate:\n");
    t_node *current = stack_a;
    t_node *current_b = stack_b;
    ft_printf("Stack A:\n");
    while (current != NULL)
    {
        ft_printf("%d\n", current->value);
        t_node *temp = current->next;
        free(current);
        current = temp;
    }
    ft_printf("Stack B:\n");
    while (current_b != NULL)
    {
        ft_printf("%d\n", current_b->value);
        t_node *temp = current_b->next;
        free(current_b);
        current_b = temp;
    }
    return (0);
}