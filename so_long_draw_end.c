/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_end.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:33:35 by chillion          #+#    #+#             */
/*   Updated: 2022/10/04 10:13:10 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_big_sheep(t_v *v)
{
	v->ig.addr_use = 9;
	mlx_destroy_image(v->mlx, v->sb.img);
	v->sb.img = mlx_xpm_file_to_image(v->mlx, "tx/SE.xpm", &v->sb.w, &v->sb.h);
	if (!v->sb.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sb.ad = mlx_get_data_addr(v->sb.img, &v->sb.bpp, &v->sb.llen, &v->sb.en);
}

void	ft_draw_big_sheep(t_v *v, int x, int y)
{
	double		i;
	double		j;
	int			color;
	double		ratio;

	j = 0;
	ratio = ((double)v->sb.w / (double)(((v->m.h) * v->m.w)));
	x = x - (((v->m.h) * v->m.w) / 2);
	y = y - (((v->m.h) * v->m.w) / 2);
	while (j < (double)((v->m.h) * v->m.w))
	{
		i = 0;
		while (i < (double)((v->m.h) * v->m.w))
		{
			color = ft_get_color(&v->sb, i * ratio, j * ratio);
			if (color != 0x000000FF)
				ft_my_mlx_pixel_put(&v->ig, (x + i), (y + j), color);
			i++;
		}
		j++;
	}
}

void	ft_init_new_sprites(t_v *v)
{
	v->wa.img = mlx_xpm_file_to_image(v->mlx, "tx/W2.xpm", &v->wa.w, &v->wa.h);
	if (!v->wa.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->wa.ad = mlx_get_data_addr(v->wa.img, &v->wa.bpp, &v->wa.llen, &v->wa.en);
	v->sl.img = mlx_xpm_file_to_image(v->mlx, "tx/SL2.xpm", &v->sl.w, &v->sl.h);
	if (!v->sl.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sl.ad = mlx_get_data_addr(v->sl.img, &v->sl.bpp, &v->sl.llen, &v->sl.en);
	v->sr.img = mlx_xpm_file_to_image(v->mlx, "tx/SR2.xpm", &v->sr.w, &v->sr.h);
	if (!v->sr.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sr.ad = mlx_get_data_addr(v->sr.img, &v->sr.bpp, &v->sr.llen, &v->sr.en);
	v->sh.img = mlx_xpm_file_to_image(v->mlx, "tx/SB2.xpm", &v->sh.w, &v->sh.h);
	if (!v->sh.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sh.ad = mlx_get_data_addr(v->sh.img, &v->sh.bpp, &v->sh.llen, &v->sh.en);
	v->sb.img = mlx_xpm_file_to_image(v->mlx, "tx/SF2.xpm", &v->sb.w, &v->sb.h);
	if (!v->sb.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sb.ad = mlx_get_data_addr(v->sb.img, &v->sb.bpp, &v->sb.llen, &v->sb.en);
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
		v->ig.addr_use = 5;
		mlx_destroy_image(v->mlx, v->wa.img);
		mlx_destroy_image(v->mlx, v->sl.img);
		mlx_destroy_image(v->mlx, v->sr.img);
		mlx_destroy_image(v->mlx, v->sb.img);
		mlx_destroy_image(v->mlx, v->sh.img);
		ft_init_new_sprites(v);
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
		ft_font_rainbow(v);
		ft_init_big_sheep(v);
		ft_draw_big_sheep(v, i, j);
		v->m.status = 1;
	}
}
