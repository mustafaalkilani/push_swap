#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
    struct s_node   *prev;
}               t_node;

void    init_stack(t_node **a, char ** argv);
void    s_stack(t_node **stack);
void    ss(t_node **a, t_node **b);
#endif