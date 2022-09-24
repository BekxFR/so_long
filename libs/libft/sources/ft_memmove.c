/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:00:57 by chillion          #+#    #+#             */
/*   Updated: 2022/05/10 14:07:23 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*str;

	dst = (char *)dest;
	str = (const char *)src;
	if (str < dst)
	{
		while (n--)
		{
			dst[n] = str[n];
		}
	}
	else
	{
		ft_memcpy(dst, str, n);
	}
	return (dest);
}
