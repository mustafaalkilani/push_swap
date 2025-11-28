#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include "libft/libft.h"

int is_sorted(char **argv)
{
    int i;

    i = 0;
    while (argv[i] && argv[i + 1])
    {
        if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
            return (0);
        i++;
    }
    return (1);
}
void free_stack(t_node **stack)
{
    t_node *temp;

    if (!stack)
        return ;
    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
}
void free_split(char **split)
{
    int i = 0;
    
    if (!split)
        return;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
int main(int argc, char **argv)
{
    int     should_free_argv;
    char    **args;
    t_node  *A;
    t_node  *B;

    A = NULL;
    B = NULL;
    should_free_argv = 0;
    
    if (argc == 1 || argv[1][0] == '\0')
        return (0);
    
    if (argc == 2)
    {
        args = ft_split(argv[1], ' ');
        should_free_argv = 1;
    }
    else
    {
        args = argv + 1;
    }
    
    if (is_sorted(args))
    {
        if (should_free_argv)
            free_split(args);
        return (0);
    }
    
    init_stack(&A, args);
    push_swap(&A, &B);
    free_stack(&A);
    free_stack(&B);
    
    if (should_free_argv)
        free_split(args);
    return (0);
}
