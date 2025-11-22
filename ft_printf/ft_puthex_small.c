/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:25:37 by malkilan          #+#    #+#             */
/*   Updated: 2025/09/01 15:18:55 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_small(unsigned int num)
{
	int		mod;
	int		len;
	int		i;
	char	*str;

	len = get_size(num);
	i = len;
	str = malloc(len + 1);
	if (!str)
		return (-1);
	str[i] = 0;
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		mod = num % 16;
		if (mod <= 9)
			str[--i] = mod + '0';
		else
			str[--i] = mod + 'W';
		num /= 16;
	}
	write(1, str, len);
	free(str);
	return (len);
}
