/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malkilan <malkilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:14:47 by malkilan          #+#    #+#             */
/*   Updated: 2025/12/14 17:14:48 by malkilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
