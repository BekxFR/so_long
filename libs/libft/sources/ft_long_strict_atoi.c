/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_strict_atoi.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:59 by chillion          #+#    #+#             */
/*   Updated: 2022/09/20 15:20:34 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_long_strict_atoi(const char *nptr)
{
	int			x;
	int			y;
	long int	nb;

	x = 0;
	y = 1;
	nb = 0;
	if (nptr[x] == '-')
			y = -1;
	if (nptr[x] == '+' || nptr[x] == '-')
		x++;
	if (!nptr[x])
		return (999999999999);
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		if (nptr[x + 1] == '.' && nptr[x + 2] == '.')
			return (999999999999);
		nb = nb * 10 + (nptr[x] - 48);
		x++;
	}
	if ((nb * y > INT_MAX) || (nb * y < INT_MIN)
		|| (!nptr[0]) || (nptr[x] && nptr[x] != '.'))
		return (999999999999);
	return (nb * y);
}
