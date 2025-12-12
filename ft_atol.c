#include "libft/libft.h"
#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	is_valid_number(const char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	has_digit = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		has_digit = 1;
		i++;
	}
	if (str[i] != '\0' || !has_digit)
		return (0);
	return (1);
}

long	ft_atol(const char *nptr)
{
	long	num;
	int		i;
	int		sign;

	if (!is_valid_number(nptr))
		error_exit();
	num = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + (nptr[i++] - '0');
	return (sign * num);
}
