/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_init_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:21:46 by chillion          #+#    #+#             */
/*   Updated: 2022/10/03 17:31:47 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_line_init_size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_fd_error(t_v *v)
{
	ft_printf("%s\n", strerror(errno));
	free(v);
	exit(EXIT_FAILURE);
}

int	ft_size_init_map(char *argv, t_v *v)
{
	int		fd;
	int		i;
	int		j;
	char	*str;

	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_fd_error(v);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (ft_line_init_size(str) > 54)
			j = -1;
		free(str);
		str = get_next_line(fd);
		i++;
	}
	fd = close(fd);
	if (j == -1)
		i = -1;
	return (i);
}

char	**ft_init_map(char *argv, t_v *v, int j)
{
	int	fd;
	int	i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_fd_error(v);
	i = 0;
	v->m.map = (char **)malloc(sizeof(char *) * (j + 1));
	if (!v->m.map)
		return (0);
	v->m.map[i] = get_next_line(fd);
	while (v->m.map[i])
	{
		i++;
		v->m.map[i] = get_next_line(fd);
	}
	fd = close(fd);
	return (v->m.map);
}

void	ft_map_width_height(t_v *v)
{
	int	width;
	int	height;

	width = 0;
	while (v->m.map[width])
		width++;
	v->m.w = width;
	height = 0;
	while (v->m.map[0][height])
		height++;
	v->m.h = height - 1;
}
