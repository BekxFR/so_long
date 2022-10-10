/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_end_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:33:35 by chillion          #+#    #+#             */
/*   Updated: 2022/10/05 18:10:06 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_big_sheep(t_v *v)
{
	v->ig.addr_use = 15;
	mlx_destroy_image(v->mlx, v->sb.img);
	v->sb.img = mlx_xpm_file_to_image(v->mlx, "tx/SE.xpm", &v->sb.w, &v->sb.h);
	if (!v->sb.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sb.ad = mlx_get_data_addr(v->sb.img, &v->sb.bpp, &v->sb.llen, &v->sb.en);
	mlx_destroy_image(v->mlx, v->sb2.img);
	v->sb2.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SE2.xpm", &v->sb2.w, &v->sb2.h);
	if (!v->sb2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sb2.ad = mlx_get_data_addr(v->sb2.img,
			&v->sb2.bpp, &v->sb2.llen, &v->sb2.en);
}

void	ft_draw_big_sheep(t_v *v, t_data sprite, int x, int y)
{
	double		i;
	double		j;
	int			color;
	double		ratio;

	j = 0;
	ratio = ((double)sprite.w / (double)(((v->m.h) * v->m.w)));
	x = x - (((v->m.h) * v->m.w) / 2);
	y = y - (((v->m.h) * v->m.w) / 2);
	while (j < (double)((v->m.h) * v->m.w))
	{
		i = 0;
		while (i < (double)((v->m.h) * v->m.w))
		{
			color = ft_get_color(&sprite, i * ratio, j * ratio);
			if (color != 0x000000FF)
				ft_my_mlx_pixel_put(&v->ig, (x + i), (y + j), color);
			i++;
		}
		j++;
	}
}

void	ft_init_new_sprites_part3(t_v *v)
{
	if (!v->sh2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sh2.ad = mlx_get_data_addr(v->sh2.img,
			&v->sh2.bpp, &v->sh2.llen, &v->sh2.en);
	v->sb.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SF2.xpm", &v->sb.w, &v->sb.h);
	if (!v->sb.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sb.ad = mlx_get_data_addr(v->sb.img,
			&v->sb.bpp, &v->sb.llen, &v->sb.en);
	v->sb2.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SF22.xpm", &v->sb2.w, &v->sb2.h);
	if (!v->sb2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sb2.ad = mlx_get_data_addr(v->sb2.img,
			&v->sb2.bpp, &v->sb2.llen, &v->sb2.en);
}

void	ft_init_new_sprites_part2(t_v *v)
{
	v->sh.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SB2.xpm", &v->sh.w, &v->sh.h);
	if (!v->sh.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sh.ad = mlx_get_data_addr(v->sh.img, &v->sh.bpp, &v->sh.llen, &v->sh.en);
	v->sl2.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SL22.xpm", &v->sl2.w, &v->sl2.h);
	if (!v->sl2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sl2.ad = mlx_get_data_addr(v->sl2.img,
			&v->sl2.bpp, &v->sl2.llen, &v->sl2.en);
	v->sr2.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SR22.xpm", &v->sr2.w, &v->sr2.h);
	if (!v->sr2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sr2.ad = mlx_get_data_addr(v->sr2.img,
			&v->sr2.bpp, &v->sr2.llen, &v->sr2.en);
	v->sh2.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SB22.xpm", &v->sh2.w, &v->sh2.h);
}

void	ft_init_new_sprites(t_v *v)
{
	v->wa.img = mlx_xpm_file_to_image(v->mlx,
			"tx/W2.xpm", &v->wa.w, &v->wa.h);
	if (!v->wa.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->wa.ad = mlx_get_data_addr(v->wa.img, &v->wa.bpp, &v->wa.llen, &v->wa.en);
	v->sl.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SL2.xpm", &v->sl.w, &v->sl.h);
	if (!v->sl.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sl.ad = mlx_get_data_addr(v->sl.img, &v->sl.bpp, &v->sl.llen, &v->sl.en);
	v->sr.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SR2.xpm", &v->sr.w, &v->sr.h);
	if (!v->sr.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sr.ad = mlx_get_data_addr(v->sr.img, &v->sr.bpp, &v->sr.llen, &v->sr.en);
	ft_init_new_sprites_part2(v);
	ft_init_new_sprites_part3(v);
}
