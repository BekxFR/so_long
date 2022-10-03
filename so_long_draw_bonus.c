/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:41:03 by chillion          #+#    #+#             */
/*   Updated: 2022/10/03 17:58:32 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_draw_sprite(t_v *v, t_data sprite, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < 48)
	{
		j = 0;
		while (j < 48)
		{
			color = ft_get_color(&sprite, j, i);
			ft_my_mlx_pixel_put(&v->ig, j + (x * 48), i + (y * 48), color);
			j++;
		}
		i++;
	}
}

void	ft_draw_player(t_v *v, int key)
{
	if ((key == 119 || key == 65362) && v->m.status == 0)
		key = ft_check_player_up(v);
	if ((key == 115 || key == 65364) && v->m.status == 0)
		key = ft_check_player_down(v);
	if ((key == 100 || key == 65363) && v->m.status == 0)
		key = ft_check_player_right(v);
	if ((key == 97 || key == 65361) && v->m.status == 0)
		key = ft_check_player_left(v);
	if (key == 1)
		mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
}

void	ft_init_draws(t_v *v, int x, int y, char c)
{
	if (c == '1')
		ft_init_draw_sprite(v, v->wa, x, y);
	if (c == 'P')
	{
		v->m.px = x;
		v->m.py = y;
		ft_init_draw_sprite(v, v->sl, x, y);
	}
	if (c == '0')
		ft_init_draw_sprite(v, v->bg, x, y);
	if (c == 'C' && v->m.conso == 0)
	{
		ft_init_draw_sprite(v, v->c1, x, y);
		v->m.map[y][x] = '2';
		v->m.conso = 1;
	}
	else if (c == 'C')
		ft_init_draw_sprite(v, v->c2, x, y);
	if (c == 'E')
		ft_init_draw_sprite(v, v->ex, x, y);
	mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
}

void	ft_draw_map(t_v *v)
{
	int	x;
	int	y;

	y = 0;
	while (v->m.map[y])
	{
		x = 0;
		while (v->m.map[y][x])
		{
			if (v->m.map[y][x] == '1')
				ft_init_draws(v, x, y, '1');
			if (v->m.map[y][x] == 'P')
				ft_init_draws(v, x, y, 'P');
			if (v->m.map[y][x] == '0')
				ft_init_draws(v, x, y, '0');
			if (v->m.map[y][x] == 'C')
				ft_init_draws(v, x, y, 'C');
			if (v->m.map[y][x] == 'E')
				ft_init_draws(v, x, y, 'E');
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
}

void	ft_draw_map_new(t_v *v)
{
	int	x;
	int	y;

	y = 0;
	while (v->m.map[y])
	{
		x = 0;
		while (v->m.map[y][x])
		{
			if (v->m.map[y][x] == '1')
				ft_init_draw_sprite(v, v->wa, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
}
