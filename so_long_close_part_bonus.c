/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_close_part_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:08:30 by chillion          #+#    #+#             */
/*   Updated: 2022/10/05 18:10:20 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_stop_part1(t_v *v)
{
	if (v->ig.addr_use >= 1 && v->ig.img)
		mlx_destroy_image(v->mlx, v->ig.img);
	if (v->ig.addr_use >= 2 && v->bg.img)
		mlx_destroy_image(v->mlx, v->bg.img);
	if (v->ig.addr_use >= 3 && v->c1.img)
		mlx_destroy_image(v->mlx, v->c1.img);
	if (v->ig.addr_use >= 4 && v->c2.img)
		mlx_destroy_image(v->mlx, v->c2.img);
	if (v->ig.addr_use >= 5 && v->ex.img)
		mlx_destroy_image(v->mlx, v->ex.img);
	if (v->ig.addr_use >= 6 && v->ex2.img)
		mlx_destroy_image(v->mlx, v->ex2.img);
	if (v->ig.addr_use >= 7 && v->c12.img)
		mlx_destroy_image(v->mlx, v->c12.img);
}

void	ft_stop_part2(t_v *v)
{
	if (v->ig.addr_use >= 8 && v->c22.img)
		mlx_destroy_image(v->mlx, v->c22.img);
	if (v->ig.addr_use >= 9 && v->wa.img)
		mlx_destroy_image(v->mlx, v->wa.img);
	if (v->ig.addr_use >= 10 && v->sl.img)
		mlx_destroy_image(v->mlx, v->sl.img);
	if (v->ig.addr_use >= 11 && v->sr.img)
		mlx_destroy_image(v->mlx, v->sr.img);
	if (v->ig.addr_use >= 12 && v->sh.img)
		mlx_destroy_image(v->mlx, v->sh.img);
	if (v->ig.addr_use >= 13 && v->sl2.img)
		mlx_destroy_image(v->mlx, v->sl2.img);
	if (v->ig.addr_use >= 14 && v->sr2.img)
		mlx_destroy_image(v->mlx, v->sr2.img);
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

void	ft_switch_player_image(t_v *v, int x, int y)
{
	if (v->m.map[x][y] == 'C')
	{
		v->m.its = v->m.its + 1;
		v->m.map[x][y] = '0';
	}
	if (v->m.map[x][y] == '2')
	{
		v->m.its = v->m.its + 1;
		v->ig.addr_use = 8;
		v->ig.free_status = 2;
		mlx_destroy_image(v->mlx, v->wa.img);
		mlx_destroy_image(v->mlx, v->sl.img);
		mlx_destroy_image(v->mlx, v->sr.img);
		mlx_destroy_image(v->mlx, v->sh.img);
		mlx_destroy_image(v->mlx, v->sb.img);
		mlx_destroy_image(v->mlx, v->sl2.img);
		mlx_destroy_image(v->mlx, v->sr2.img);
		mlx_destroy_image(v->mlx, v->sh2.img);
		mlx_destroy_image(v->mlx, v->sb2.img);
		ft_init_new_sprites(v);
		v->ig.addr_use = v->ig.addr_use + 2;
		ft_draw_map_new(v);
		v->m.map[x][y] = '0';
	}
}

void	ft_switch_end_game(t_v *v, int x, int y)
{
	int	i;
	int	j;

	i = (((v->m.h) * v->sb.h) / 2);
	j = ((v->m.w * v->sb.w) / 2);
	if (v->m.map[x][y] == 'E' && v->m.its == v->m.itsf)
	{
		v->frame = 3;
		ft_font_rainbow(v);
		ft_init_big_sheep(v);
		ft_draw_big_sheep(v, v->sb, i, j);
		v->m.status = 1;
	}
}
