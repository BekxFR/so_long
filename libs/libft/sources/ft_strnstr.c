/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:07:27 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 17:41:57 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (little[x] == '\0')
	{
		return ((char *)big);
	}
	while (big[x] != '\0' && x < len)
	{
		y = 0;
		while (big[x + y] == little[y] && len > x + y)
		{
			y++;
			if (little[y] == '\0')
			{
				return ((char *)(big + x));
			}
		}
		x++;
	}
	return (0);
}
