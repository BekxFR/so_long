/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_checker_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:25:18 by chillion          #+#    #+#             */
/*   Updated: 2022/10/10 16:04:10 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_ctrl_map_size(t_v *v, int i)
{
	int	width;
	int	dif;
	int	line_size;

	ft_map_width_height(v);
	dif = 0;
	while (v->m.map[i])
	{
		width = 0;
		while (v->m.map[i][width])
			width++;
		if (i == 0)
			line_size = width;
		else if (width != line_size || width < 4)
			dif += 1;
		i++;
	}
	if (dif != 0 || i == width - 1 || i < 3)
	{
		errno = 22;
		perror("Error\nMAP SIZE NOT CORRECT ");
		ft_exit_map(v, i);
	}
	return (i);
}

int	ft_contour_map_control_len(int j, int k, int len)
{
	if (j == 0)
		len = k;
	return (len);
}

int	ft_contour_map_control(t_v *v, int i)
{
	int	j;
	int	k;
	int	len;
	int	error;

	j = 0;
	error = 0;
	while (v->m.map[j])
	{
		k = 0;
		while (v->m.map[j][k + 1])
		{
			if (v->m.map[0][k] != '1' || v->m.map[i - 1][k] != '1'
				|| v->m.map[j][0] != '1')
				error += 1;
			len = ft_contour_map_control_len(j, k, len);
			if (v->m.map[j][len] != '1')
				error += 1;
			k++;
		}
		j++;
	}
	if (error != 0)
		ft_printf("Error\nMAP NOT ENCLOSE BY WALLS : %s\n", strerror(22));
	return (error);
}

int	ft_elements_map_control(t_v *v)
{
	int		j;
	int		k;
	char	error;

	j = 1;
	error = 0;
	while (v->m.map[j + 1])
	{
		k = 1;
		while (v->m.map[j][k + 1])
		{
			if (v->m.map[j][k] != '1' && v->m.map[j][k] != '0'
				&& v->m.map[j][k] != 'P' && v->m.map[j][k] != 'E'
					&& v->m.map[j][k] != 'C')
			{
				error = v->m.map[j][k];
				break ;
			}
			k++;
		}
		j++;
	}
	if (error != 0)
		ft_printf("Error\nFIND UNKNOWN ELEMENT (%c) ON MAP\n", error);
	return (error);
}
