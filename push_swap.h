#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
}               t_node;

void    init_stack(t_node **a, char ** argv);
void    s_stack(t_node **stack);
void    ss(t_node **a, t_node **b);
long	ft_atol(const char *nptr);
void	put_pointer_at_start(t_node **stack);
void    s_stack(t_node **stack);
void    r_stack(t_node **stack);
void    rr_stack(t_node **stack);
void    p_stack(t_node **stack_to, t_node **stack_from);
#endif