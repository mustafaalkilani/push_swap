#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
    int             index;
    int             to_top_cost;
    int             final_to_top_cost;
    int             target;
}               t_node;
void free_stack(t_node **stack);
void    init_stack(t_node **a, char ** argv);
void    s_stack(t_node **stack, char *operation);
void    ss(t_node **a, t_node **b);
long	ft_atol(const char *nptr);
void	put_pointer_at_start_and_asign_indexs(t_node **stack);
void    s_stack(t_node **stack, char *operation);
void    r_stack(t_node **stack, char *operation);
void    rr_stack(t_node **stack, char *operation);
void    p_stack(t_node **stack_to, t_node **stack_from, char *operation);
void    rrr(t_node **a, t_node **b);
void    rr(t_node **a, t_node **b);
void	ft_node_add_back(t_node **lst, t_node *new);
t_node	*ft_node_new(int value);
int get_stack_size(t_node *stack);
void execute_cheapest_move(t_node **a, t_node **b);
void push_swap(t_node **a, t_node **b);
#endif