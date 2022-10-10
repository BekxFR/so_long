/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_attack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:11:11 by chillion          #+#    #+#             */
/*   Updated: 2022/10/06 16:16:50 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_west_offensive(int x, int y, t_v *v)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (v->m.map[tmpy][tmpx] != '1' && v->m.map[tmpy][tmpx] != 'E')
	{
		if (v->m.map[tmpy][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy - 1][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy + 1][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx] != '1'
			&& v->m.map[tmpy][tmpx] != 'E')
			v->m.map[tmpy][tmpx] = 'P';
		if (v->m.map[tmpy - 1][tmpx] != '1'
			&& v->m.map[tmpy - 1][tmpx] != 'E')
			v->m.map[tmpy - 1][tmpx] = 'P';
		if (v->m.map[tmpy + 1][tmpx] != '1'
			&& v->m.map[tmpy + 1][tmpx] != 'E')
			v->m.map[tmpy + 1][tmpx] = 'P';
		tmpx--;
	}
	return (v->m.itsf);
}

int	ft_north_offensive(int x, int y, t_v *v)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (v->m.map[tmpy][tmpx] != '1' && v->m.map[tmpy][tmpx] != 'E')
	{
		if (v->m.map[tmpy][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx - 1] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx + 1] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx] != '1'
			&& v->m.map[tmpy][tmpx] != 'E')
			v->m.map[tmpy][tmpx] = 'P';
		if (v->m.map[tmpy][tmpx - 1] != '1'
			&& v->m.map[tmpy][tmpx - 1] != 'E')
			v->m.map[tmpy][tmpx - 1] = 'P';
		if (v->m.map[tmpy][tmpx + 1] != '1'
			&& v->m.map[tmpy][tmpx + 1] != 'E')
			v->m.map[tmpy][tmpx + 1] = 'P';
		tmpy--;
	}
	return (v->m.itsf);
}

int	ft_east_offensive(int x, int y, t_v *v)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (v->m.map[tmpy][tmpx] != '1' && v->m.map[tmpy][tmpx] != 'E')
	{
		if (v->m.map[tmpy][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy - 1][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy + 1][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx] != '1'
			&& v->m.map[tmpy][tmpx] != 'E')
			v->m.map[tmpy][tmpx] = 'P';
		if (v->m.map[tmpy - 1][tmpx] != '1'
			&& v->m.map[tmpy - 1][tmpx] != 'E')
			v->m.map[tmpy - 1][tmpx] = 'P';
		if (v->m.map[tmpy + 1][tmpx] != '1'
			&& v->m.map[tmpy + 1][tmpx] != 'E')
			v->m.map[tmpy + 1][tmpx] = 'P';
		tmpx++;
	}
	return (v->m.itsf);
}

int	ft_south_offensive(int x, int y, t_v *v)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (v->m.map[tmpy][tmpx] != '1' && v->m.map[tmpy][tmpx] != 'E')
	{
		if (v->m.map[tmpy][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx - 1] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx + 1] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx] != '1'
			&& v->m.map[tmpy][tmpx] != 'E')
			v->m.map[tmpy][tmpx] = 'P';
		if (v->m.map[tmpy][tmpx - 1] != '1'
			&& v->m.map[tmpy][tmpx - 1] != 'E')
			v->m.map[tmpy][tmpx - 1] = 'P';
		if (v->m.map[tmpy][tmpx + 1] != '1'
			&& v->m.map[tmpy][tmpx + 1] != 'E')
			v->m.map[tmpy][tmpx + 1] = 'P';
		tmpy++;
	}
	return (v->m.itsf);
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
