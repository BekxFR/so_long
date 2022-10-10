/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_items_checker_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:31:59 by chillion          #+#    #+#             */
/*   Updated: 2022/10/06 17:17:35 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_control_item(t_v *v, char c)
{
	int	x;
	int	y;
	int	item;

	x = 0;
	y = 0;
	item = 0;
	v->m.itsf = 1;
	while (v->m.map[y])
	{
		x = 0;
		while (v->m.map[y][x])
		{
			if (v->m.map[y][x] == c)
				item += 1;
			x++;
		}
		y++;
	}
	return (item);
}

int	ft_control_its(t_v *v)
{
	int	exit;
	int	player;
	int	conso;

	exit = ft_control_item(v, 'E');
	player = ft_control_item(v, 'P');
	conso = ft_control_item(v, 'C');
	if (exit == 1 && player == 1 && conso >= 1)
	{
		v->m.its = player + exit + conso;
		return (v->m.its);
	}
	if (player != 1 || exit != 1 || conso == 0)
	{
		ft_printf("Error\nITEMS NUMBER NOT VALABLE : Player =");
		ft_printf("%d, Exit = %d, Collectable = %d\n", player, exit, conso);
	}
	return (0);
}

int	ft_invasion_propagation(int x, int y, t_v *v)
{
	ft_west_offensive(x, y, v);
	if (v->m.itsf == v->m.its)
		return (v->m.itsf);
	ft_north_offensive(x, y, v);
	if (v->m.itsf == v->m.its)
		return (v->m.its);
	ft_east_offensive(x, y, v);
	if (v->m.itsf == v->m.its)
		return (v->m.its);
	ft_south_offensive(x, y, v);
	if (v->m.itsf == v->m.its)
		return (v->m.its);
	return (v->m.itsf);
}
