/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:45:11 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 17:42:56 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strdouble(char *str)
{
	int	x;
	int	y;

	x = 0;
	while (str[x] != '\0')
	{
		y = x + 1;
		while (str[y] != '\0')
		{
			if (str[x] == str[y])
				return (0);
		y++;
		}
	x++;
	}
	return (1);
}
