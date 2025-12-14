#include "../push_swap.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "./push_swap_bonus.h"

void process_instructions(t_node **a, t_node **b)
{
    char    *read_line;

    read_line = get_next_line(0);
    while (read_line)
    {
        execute_instruction(read_line, a, b);
        free(read_line);
        read_line = get_next_line(0);
    }
    if (is_sorted(a, 0, NULL) && !*b)
        ft_putstr_fd("OK\n", 1);
    else
        ft_putstr_fd("KO\n", 1);
    free_stack(a);
    free_stack(b);
}
