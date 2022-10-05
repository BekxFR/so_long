/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_refresh_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:21:27 by chillion          #+#    #+#             */
/*   Updated: 2022/10/05 17:01:42 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_draws2(t_v *v, int x, int y, char c)
{
	if (c == 'P')
	{
		v->m.px = x;
		v->m.py = y;
		if (v->m.pp == 0)
			ft_init_draw_sprite(v, v->sl2, x, y);
		if (v->m.pp == 1)
			ft_init_draw_sprite(v, v->sr2, x, y);
		if (v->m.pp == 2)
			ft_init_draw_sprite(v, v->sb2, x, y);
		if (v->m.pp == 3)
			ft_init_draw_sprite(v, v->sh2, x, y);
	}
	if (c == 'C')
		ft_init_draw_sprite(v, v->c22, x, y);
	if (c == '2')
		ft_init_draw_sprite(v, v->c12, x, y);
	if (c == 'E')
		ft_init_draw_sprite(v, v->ex2, x, y);
	if (c == 'N')
		ft_init_draw_sprite(v, v->n1, x, y);
}

void	ft_init_draws1(t_v *v, int x, int y, char c)
{
	if (c == 'P')
	{
		v->m.px = x;
		v->m.py = y;
		if (v->m.pp == 0)
			ft_init_draw_sprite(v, v->sl, x, y);
		if (v->m.pp == 1)
			ft_init_draw_sprite(v, v->sr, x, y);
		if (v->m.pp == 2)
			ft_init_draw_sprite(v, v->sb, x, y);
		if (v->m.pp == 3)
			ft_init_draw_sprite(v, v->sh, x, y);
	}
	if (c == 'C')
		ft_init_draw_sprite(v, v->c2, x, y);
	if (c == '2')
		ft_init_draw_sprite(v, v->c1, x, y);
	if (c == 'E')
		ft_init_draw_sprite(v, v->ex, x, y);
	if (c == 'N')
		ft_init_draw_sprite(v, v->n12, x, y);
}

void	ft_draw_refresh2(t_v *v)
{
	int	x;
	int	y;

	y = 0;
	while (v->m.map[y])
	{
		x = 0;
		while (v->m.map[y][x])
		{
			if (v->m.map[y][x] == '2')
				ft_init_draws2(v, x, y, '2');
			if (v->m.map[y][x] == 'P')
				ft_init_draws2(v, x, y, 'P');
			if (v->m.map[y][x] == 'C')
				ft_init_draws2(v, x, y, 'C');
			if (v->m.map[y][x] == 'E')
				ft_init_draws2(v, x, y, 'E');
			if (v->m.map[y][x] == 'N')
				ft_init_draws2(v, x, y, 'N');
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
}

void	ft_draw_refresh1(t_v *v)
{
	int	x;
	int	y;

	y = 0;
	while (v->m.map[y])
	{
		x = 0;
		while (v->m.map[y][x])
		{
			if (v->m.map[y][x] == '2')
				ft_init_draws1(v, x, y, '2');
			if (v->m.map[y][x] == 'P')
				ft_init_draws1(v, x, y, 'P');
			if (v->m.map[y][x] == 'C')
				ft_init_draws1(v, x, y, 'C');
			if (v->m.map[y][x] == 'E')
				ft_init_draws1(v, x, y, 'E');
			if (v->m.map[y][x] == 'N')
				ft_init_draws1(v, x, y, 'N');
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
}
