#include "../push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

int	ft_fmax(int a, int b)
{
	if (a > b)
		return (a);
	else if (a < b)
		return (b);
	return (a);
}
