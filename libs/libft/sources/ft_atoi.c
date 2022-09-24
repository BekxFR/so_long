/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:15:59 by chillion          #+#    #+#             */
/*   Updated: 2022/09/20 16:51:48 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	x;
	int	y;
	int	nb;

	x = 0;
	y = 1;
	nb = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == ' ')
		x++;
	if (nptr[x] == '+' || nptr[x] == '-')
	{
		if (nptr[x] == '-')
		{
			y *= -1;
		}
		x++;
	}
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		nb = nb * 10 + (nptr[x] - 48);
		x++;
	}
	return (nb * y);
}
