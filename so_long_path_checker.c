/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_path_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:22:57 by chillion          #+#    #+#             */
/*   Updated: 2022/10/03 17:59:15 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_invasion_checker_condition(t_v *v, int x, int y)
{
	if ((v->m.map[y][x - 1] != '1' && v->m.map[y][x - 1] != 'P')
		|| (v->m.map[y][x + 1] != '1' && v->m.map[y][x + 1] != 'P')
			|| (v->m.map[y - 1][x] != '1' && v->m.map[y - 1][x] != 'P')
				|| (v->m.map[y + 1][x] != '1' && v->m.map[y + 1][x] != 'P'))
		return (1);
	return (0);
}

int	ft_invasion_checker(t_v *v)
{
	int	x;
	int	y;

	y = 1;
	while (y < v->m.w - 1)
	{
		x = 1;
		while (x < v->m.h - 1)
		{
			if (v->m.map[y][x] == 'P')
			{
				if (ft_invasion_checker_condition(v, x, y) == 1)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_invasion_loop_checker(t_v *v, int x, int y)
{
	if (v->m.map[y][x - 1] != '1'
		|| v->m.map[y][x + 1] != '1'
			|| v->m.map[y - 1][x] != '1'
				|| v->m.map[y + 1][x] != '1')
		v->m.itsf = ft_invasion_propagation(x, y, v);
}

int	ft_invasion_loop(t_v *v)
{
	int	x;
	int	y;

	y = 1;
	while (y < v->m.w - 1)
	{
		x = 1;
		while (x < v->m.h - 1)
		{
			if (v->m.map[y][x] == 'P' && v->m.itsf != v->m.its)
				ft_invasion_loop_checker(v, x, y);
			x++;
		}
		y++;
	}
	if (ft_invasion_checker(v) != 0 && v->m.itsf != v->m.its)
		return (ft_invasion_loop(v));
	if (v->m.itsf != v->m.its)
		ft_printf("Error\nNO VALABLE PATH - ALL ITEMS CANT BE FIND BY PLAYER\n");
	return (v->m.itsf);
}
