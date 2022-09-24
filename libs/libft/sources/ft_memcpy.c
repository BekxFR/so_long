/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:00:30 by chillion          #+#    #+#             */
/*   Updated: 2022/05/10 14:06:34 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*str;

	i = 0;
	dst = (char *)dest;
	str = (const char *)src;
	if (dst == 0 && str == 0)
	{
		return (NULL);
	}
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dest);
}
