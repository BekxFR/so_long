/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_attack_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:11:11 by chillion          #+#    #+#             */
/*   Updated: 2022/10/06 16:50:54 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_offensive_ally(int tmpx, int tmpy, t_v *v)
{
	if (v->m.map[tmpy][tmpx] != '1'
		&& v->m.map[tmpy][tmpx] != 'N' && v->m.map[tmpy][tmpx] != 'E')
		return (1);
	return (0);
}

int	ft_west_offensive(int x, int y, t_v *v)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (ft_offensive_ally(tmpx, tmpy, v))
	{
		if (v->m.map[tmpy][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy - 1][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy + 1][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx] != '1'
		&& v->m.map[tmpy][tmpx] != 'N' && v->m.map[tmpy][tmpx] != 'E')
			v->m.map[tmpy][tmpx] = 'P';
		if (v->m.map[tmpy - 1][tmpx] != '1'
		&& v->m.map[tmpy - 1][tmpx] != 'N' && v->m.map[tmpy - 1][tmpx] != 'E')
			v->m.map[tmpy - 1][tmpx] = 'P';
		if (v->m.map[tmpy + 1][tmpx] != '1'
		&& v->m.map[tmpy + 1][tmpx] != 'N' && v->m.map[tmpy + 1][tmpx] != 'E')
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
	while (ft_offensive_ally(tmpx, tmpy, v))
	{
		if (v->m.map[tmpy][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx - 1] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx + 1] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx] != '1'
		&& v->m.map[tmpy][tmpx] != 'N' && v->m.map[tmpy][tmpx] != 'E')
			v->m.map[tmpy][tmpx] = 'P';
		if (v->m.map[tmpy][tmpx - 1] != '1'
		&& v->m.map[tmpy][tmpx - 1] != 'N' && v->m.map[tmpy][tmpx - 1] != 'E')
			v->m.map[tmpy][tmpx - 1] = 'P';
		if (v->m.map[tmpy][tmpx + 1] != '1'
		&& v->m.map[tmpy][tmpx + 1] != 'N' && v->m.map[tmpy][tmpx + 1] != 'E')
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
	while (ft_offensive_ally(tmpx, tmpy, v))
	{
		if (v->m.map[tmpy][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy - 1][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy + 1][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx] != '1'
		&& v->m.map[tmpy][tmpx] != 'N' && v->m.map[tmpy][tmpx] != 'E')
			v->m.map[tmpy][tmpx] = 'P';
		if (v->m.map[tmpy - 1][tmpx] != '1'
		&& v->m.map[tmpy - 1][tmpx] != 'N' && v->m.map[tmpy - 1][tmpx] != 'E')
			v->m.map[tmpy - 1][tmpx] = 'P';
		if (v->m.map[tmpy + 1][tmpx] != '1'
		&& v->m.map[tmpy + 1][tmpx] != 'N' && v->m.map[tmpy + 1][tmpx] != 'E')
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
	while (ft_offensive_ally(tmpx, tmpy, v))
	{
		if (v->m.map[tmpy][tmpx] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx - 1] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx + 1] == 'C')
			v->m.itsf = v->m.itsf + 1;
		if (v->m.map[tmpy][tmpx] != '1'
		&& v->m.map[tmpy][tmpx] != 'N' && v->m.map[tmpy][tmpx] != 'E')
			v->m.map[tmpy][tmpx] = 'P';
		if (v->m.map[tmpy][tmpx - 1] != '1'
		&& v->m.map[tmpy][tmpx - 1] != 'N' && v->m.map[tmpy][tmpx - 1] != 'E')
			v->m.map[tmpy][tmpx - 1] = 'P';
		if (v->m.map[tmpy][tmpx + 1] != '1'
		&& v->m.map[tmpy][tmpx + 1] != 'N' && v->m.map[tmpy][tmpx + 1] != 'E')
			v->m.map[tmpy][tmpx + 1] = 'P';
		tmpy++;
	}
	return (v->m.itsf);
}
