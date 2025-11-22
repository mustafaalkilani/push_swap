/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:41:06 by malkilan          #+#    #+#             */
/*   Updated: 2025/09/03 15:47:09 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char specifier, va_list args)
{
	int	print_len;

	print_len = 0;
	if (specifier == 'c')
		print_len += ft_putchar(va_arg(args, int));
	if (specifier == 's')
		print_len += ft_putstr(va_arg(args, char *));
	if (specifier == 'd' || specifier == 'i')
		print_len += ft_putnbr(va_arg(args, int));
	if (specifier == 'x')
		print_len += ft_puthex_small(va_arg(args, unsigned int));
	if (specifier == 'X')
		print_len += ft_puthex_caps(va_arg(args, unsigned int));
	if (specifier == 'p')
		print_len += ft_putptr(va_arg(args, unsigned long));
	if (specifier == 'u')
		print_len += ft_put_unsigned_nbr(va_arg(args, unsigned int));
	if (specifier == '%')
		print_len += write(1, "%", 1);
	return (print_len);
}

int	ft_printf(const char *identifier, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	va_start(args, identifier);
	i = 0;
	print_len = 0;
	if (!identifier)
		return (-1);
	while (identifier[i])
	{
		if (identifier[i] == '%')
		{
			print_len += handle_format(identifier[i + 1], args);
			i++;
		}
		else
		{
			write(1, &identifier[i], 1);
			print_len++;
		}
		i++;
	}
	va_end(args);
	return (print_len);
}
