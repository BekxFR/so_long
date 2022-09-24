/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:50:04 by chillion          #+#    #+#             */
/*   Updated: 2022/09/02 17:43:01 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_noword(char *s, char c, int x)
{
	int	j;

	j = 0;
	while (s[j + x] == c && s[j + x] != '\0')
	{
		j++;
	}
	return (j);
}

static int	ft_word(char *s, char c, int x)
{
	int	i;

	i = 0;
	while (s[i + x] != c && s[i + x] != '\0')
	{
		i++;
	}
	return (i);
}

static int	ft_count(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			if (s[i] == '\0')
			{
				return (j);
			}
			i++;
		}
		if (s[i] != c && s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

static char	**ft_split_cpy(char **str, char *src, char c, int i)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	while (x < i)
	{
		if (ft_noword(src, c, y) > 0)
			y = y + ft_noword(src, c, y);
		z = ft_word(src, c, y);
		str[x] = (char *)malloc(sizeof(char) * (z + 1));
		if (str == 0)
			return (NULL);
		ft_bzero(str[x], z + 1);
		str[x] = ft_memcpy(str[x], src + y, z);
		y = y + z + 1;
		x++;
	}
	str[x] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		x;
	char	*news;
	char	**str;

	news = (char *)s;
	x = ft_count(news, c);
	str = (char **)malloc(sizeof(char *) * (x + 1));
	if (str == 0)
	{
		return (NULL);
	}
	if (x == 0)
	{
		str[0] = 0;
		return (str);
	}
	str = ft_split_cpy(str, news, c, x);
	return (str);
}
