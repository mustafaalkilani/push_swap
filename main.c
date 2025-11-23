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
    push_swap(&A, &B);
    return (0);
}
