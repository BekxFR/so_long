/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:49:33 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 17:41:51 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_char(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		x;
	int		y;
	int		z;
	char	*str;

	if (s1 == 0 || set == 0)
		return (NULL);
	x = 0;
	while (ft_check_char(set, s1[x]) == 1)
		x++;
	y = ft_strlen(s1);
	if (x > y)
		return (NULL);
	while (y > x && ft_check_char(set, s1[y - 1]) == 1)
		y--;
	str = (char *)malloc(sizeof(char) * (y - x + 1));
	if (str == 0)
		return (NULL);
	z = 0;
	while (x < y)
		str[z++] = s1[x++];
	str[z] = '\0';
	return (str);
}
