/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:01:44 by chillion          #+#    #+#             */
/*   Updated: 2022/09/16 14:55:36 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read_fd(int fd, char *str)
{
	int		x;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	x = 1;
	while (x > 0)
	{
		x = read(fd, buf, BUFFER_SIZE);
		if (x == -1)
		{
			ft_free (&buf);
			return (NULL);
		}
		buf[x] = '\0';
		tmp = ft_strdup_init(str);
		ft_free(&str);
		str = ft_strjoin_free(tmp, buf);
		if (ft_chr_on_str(str, '\n'))
			break ;
	}
	ft_free(&buf);
	return (str);
}

char	*keep_line(char *str)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (str[y] != '\n' && str[y] != '\0')
		y++;
	if (str[y] == '\n')
		line = ft_zalloc(y + 2, sizeof * line);
	else if (str[y] == '\0')
		line = ft_zalloc(y + 1, sizeof * line);
	if (!line)
		return (NULL);
	x = 0;
	while (str[x] != '\0' && str[x] != '\n')
	{
		line[x] = str[x];
		x++;
	}
	if (str[x] == '\n')
		line[x] = str[x];
	return (line);
}

char	*rest_line(char *str)
{
	char	*rest;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (str[x] != '\n' && str[x] != '\0')
		x++;
	if (!str[x] || !*str)
		return (NULL);
	while (str[y] != '\0')
		y++;
	rest = ft_zalloc(y - x + 1, sizeof * rest);
	if (!rest)
		return (NULL);
	x++;
	y = 0;
	while (str[x])
		rest[y++] = str[x++];
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*str;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_read_fd(fd, str);
	if (!str)
	{
		return (NULL);
	}
	if (!str[0])
	{
		ft_free(&str);
		return (NULL);
	}
	line = keep_line(str);
	tmp = rest_line(str);
	if (str != NULL)
		ft_free(&str);
	str = tmp;
	return (line);
}
