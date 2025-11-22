/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:35:18 by malkilan          #+#    #+#             */
/*   Updated: 2025/09/01 15:21:25 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *identifier, ...);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_puthex_small(unsigned int num);
int	ft_puthex_caps(unsigned int num);
int	get_size(unsigned long num);
int	ft_putptr(unsigned long ptr);
int	ft_put_unsigned_nbr(unsigned int n);
#endif