#include "ft_printf/ft_printf.h"
#include "push_swap.h"
#include "libft/libft.h"

int is_sorted(char **argv) // implement this function later 
{
    ft_printf("Checking if sorted:\n");
    if (argv != NULL)
        return (1);
    return (0);
} 

int main(int argc, char **argv)
{
    t_node  *A;
    t_node  *B;

    A = NULL;
    B = NULL;
    if (argc == 1 || argv[1][0] == '\0')
        return (0);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    if (is_sorted(argv))
        return (0);
    init_stack(&A, argv);
    return (0);
}
