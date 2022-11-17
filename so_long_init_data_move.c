/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_data_move.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:37:37 by chillion          #+#    #+#             */
/*   Updated: 2022/11/17 17:44:19 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress_event(int key, t_v *v)
{
	if (key == 65362 || key == 119)
		ft_draw_player(v, key);
	if (key == 65364 || key == 115)
		ft_draw_player(v, key);
	if (key == 65363 || key == 100)
		ft_draw_player(v, key);
	if (key == 65361 || key == 97)
		ft_draw_player(v, key);
	if (key == 65307)
		ft_close_event(v);
	return (0);
}

void	ft_init_sprites_part1(t_v *v)
{
	v->bg.img = mlx_xpm_file_to_image(v->mlx, "tx/F.xpm", &v->bg.w, &v->bg.h);
	if (!v->bg.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->bg.ad = mlx_get_data_addr(v->bg.img, &v->bg.bpp, &v->bg.llen, &v->bg.en);
	v->c1.img = mlx_xpm_file_to_image(v->mlx, "tx/C1.xpm", &v->c1.w, &v->c1.h);
	if (!v->c1.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->c1.ad = mlx_get_data_addr(v->c1.img, &v->c1.bpp, &v->c1.llen, &v->c1.en);
	v->c2.img = mlx_xpm_file_to_image(v->mlx, "tx/C2.xpm", &v->c2.w, &v->c2.h);
	if (!v->c2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->c2.ad = mlx_get_data_addr(v->c2.img, &v->c2.bpp, &v->c2.llen, &v->c2.en);
	v->ex.img = mlx_xpm_file_to_image(v->mlx, "tx/E1.xpm", &v->ex.w, &v->ex.h);
	if (!v->ex.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->ex.ad = mlx_get_data_addr(v->ex.img, &v->ex.bpp, &v->ex.llen, &v->ex.en);
	v->wa.img = mlx_xpm_file_to_image(v->mlx, "tx/W1.xpm", &v->wa.w, &v->wa.h);
	if (!v->wa.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->wa.ad = mlx_get_data_addr(v->wa.img, &v->wa.bpp, &v->wa.llen, &v->wa.en);
}

void	ft_init_sprites_part2(t_v *v)
{
	v->sl.img = mlx_xpm_file_to_image(v->mlx, "tx/SL.xpm", &v->sl.w, &v->sl.h);
	if (!v->sl.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sl.ad = mlx_get_data_addr(v->sl.img, &v->sl.bpp, &v->sl.llen, &v->sl.en);
	v->sr.img = mlx_xpm_file_to_image(v->mlx, "tx/SR.xpm", &v->sr.w, &v->sr.h);
	if (!v->sr.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sr.ad = mlx_get_data_addr(v->sr.img, &v->sr.bpp, &v->sr.llen, &v->sr.en);
	v->sh.img = mlx_xpm_file_to_image(v->mlx, "tx/SB.xpm", &v->sh.w, &v->sh.h);
	if (!v->sh.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sh.ad = mlx_get_data_addr(v->sh.img, &v->sh.bpp, &v->sh.llen, &v->sh.en);
	v->sb.img = mlx_xpm_file_to_image(v->mlx, "tx/SF.xpm", &v->sb.w, &v->sb.h);
	if (!v->sb.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sb.ad = mlx_get_data_addr(v->sb.img, &v->sb.bpp, &v->sb.llen, &v->sb.en);
}

void	ft_init_data(t_v *v)
{
	v->m.its = 2;
	v->ig.addr_use = 1;
	v->m.status = 0;
	v->m.conso = 0;
	v->key_count = 0;
	ft_init_sprites_part1(v);
	ft_init_sprites_part2(v);
}
