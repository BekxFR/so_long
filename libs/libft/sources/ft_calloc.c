/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:15:04 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 17:45:48 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb != 0 && (nmemb * size / nmemb) != size)
	{
		return (NULL);
	}
	dest = malloc(nmemb * size);
	if (dest == NULL)
	{
		return (NULL);
	}
	ft_bzero(dest, nmemb * size);
	return (dest);
}
