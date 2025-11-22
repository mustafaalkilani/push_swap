/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:34:37 by malkilan          #+#    #+#             */
/*   Updated: 2025/08/31 21:49:49 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long num)
{
	int		mod;
	int		len;
	int		i;
	char	*str;

	mod = 0;
	len = get_size(num);
	i = len;
	str = malloc(len + 1);
	if (!str)
		return (-1);
	str[i] = '\0';
	while (num > 0)
	{
		mod = num % 16;
		if (mod >= 0 && mod <= 9)
			str[i - 1] = mod + '0';
		else
			str[i - 1] = mod + 'W';
		num /= 16;
		i--;
	}
	write(1, str, len);
	free(str);
	return (len);
}

int	ft_putptr(unsigned long ptr)
{
	int	len;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len = 2;
	len += ft_puthex(ptr);
	return (len);
}
