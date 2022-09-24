/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:24:23 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 18:10:34 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_zalloc(size_t nmemb, size_t size)
{
	void			*dest;
	unsigned char	*pdest;
	size_t			total;
	size_t			i;

	if (nmemb != 0 && (nmemb * size / nmemb) != size)
		return (NULL);
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	i = 0;
	total = nmemb * size;
	pdest = (unsigned char *)dest;
	while (i < total)
	{
		pdest[i] = '\0';
		i++;
	}
	return (dest);
}
