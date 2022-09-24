/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:54:22 by chillion          #+#    #+#             */
/*   Updated: 2022/09/16 14:55:18 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_init(char *src)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!src)
		return (ft_strdup(""));
	j = ft_strlen(src);
	dest = ft_zalloc(j + 1, sizeof * dest);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
