#include "../push_swap.h"
#include "../get_next_line/get_next_line.h"
#include "../libft/libft.h"
#include "./push_swap_bonus.h"

void execute_instruction(char *command, t_node **a, t_node **b)
{
    if (ft_strncmp(command, "sa\n", 3) == 0)
        s_stack(a, NULL);
    else if (ft_strncmp(command, "sb\n", 3) == 0)
        s_stack(b, NULL);
    else if (ft_strncmp(command, "ss\n", 3) == 0)
        ss(a, b);
    else if (ft_strncmp(command, "pa\n", 3) == 0)
        p_stack(a, b, NULL);
    else if (ft_strncmp(command, "pb\n", 3) == 0)
        p_stack(b, a, NULL);
    else if (ft_strncmp(command, "ra\n", 3) == 0)
        r_stack(a, NULL);
    else if (ft_strncmp(command, "rb\n", 3) == 0)
        r_stack(b, NULL);
    else if (ft_strncmp(command, "rr\n", 3) == 0)
        rr(a, b);
    else if (ft_strncmp(command, "rra\n", 4) == 0)
        rr_stack(a, NULL);
    else if (ft_strncmp(command, "rrb\n", 4) == 0)
        rr_stack(b, NULL);
    else if (ft_strncmp(command, "rrr\n", 4) == 0)
        rrr(a, b);
    else
        error_exit();
}
