/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:34:31 by malkilan          #+#    #+#             */
/*   Updated: 2025/08/31 19:24:01 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	c;
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		len += write(1, "-", 1);
	}
	if (n == 0)
		len += ft_putchar('0');
	if (n > 0)
	{
		if (n >= 10)
			len += ft_putnbr(n / 10);
		c = (n % 10) + '0';
		len += write(1, &c, 1);
	}
	return (len);
}
