/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_data_part_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:11:51 by chillion          #+#    #+#             */
/*   Updated: 2022/10/05 18:12:06 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
v->ex2.img = mlx_xpm_file_to_image(v->mlx, "tx/E2.xpm", &v->ex2.w, &v->ex2.h);
	if (!v->ex2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->ex2.ad = mlx_get_data_addr(v->ex2.img,
			&v->ex2.bpp, &v->ex2.llen, &v->ex2.en);
	v->c12.img = mlx_xpm_file_to_image(v->mlx,
			"tx/C12.xpm", &v->c12.w, &v->c12.h);
	if (!v->c12.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->c12.ad = mlx_get_data_addr(v->c12.img,
			&v->c12.bpp, &v->c12.llen, &v->c12.en);
	v->c22.img = mlx_xpm_file_to_image(v->mlx,
			"tx/C22.xpm", &v->c22.w, &v->c22.h);
	if (!v->c22.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->c22.ad = mlx_get_data_addr(v->c22.img,
			&v->c22.bpp, &v->c22.llen, &v->c22.en);
	v->sl.img = mlx_xpm_file_to_image(v->mlx, "tx/SL.xpm", &v->sl.w, &v->sl.h);
	if (!v->sl.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sl.ad = mlx_get_data_addr(v->sl.img, &v->sl.bpp, &v->sl.llen, &v->sl.en);
}

void	ft_init_sprites_part3(t_v *v)
{
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
	v->sl2.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SL12.xpm", &v->sl2.w, &v->sl2.h);
	if (!v->sl2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sl2.ad = mlx_get_data_addr(v->sl2.img,
			&v->sl2.bpp, &v->sl2.llen, &v->sl2.en);
	v->sr2.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SR12.xpm", &v->sr2.w, &v->sr2.h);
	if (!v->sr2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sr2.ad = mlx_get_data_addr(v->sr2.img,
			&v->sr2.bpp, &v->sr2.llen, &v->sr2.en);
}

void	ft_init_sprites_part4(t_v *v)
{
	v->sh2.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SB12.xpm", &v->sh2.w, &v->sh2.h);
	if (!v->sh2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sh2.ad = mlx_get_data_addr(v->sh2.img,
			&v->sh2.bpp, &v->sh2.llen, &v->sh2.en);
	v->sb.img = mlx_xpm_file_to_image(v->mlx, "tx/SF.xpm", &v->sb.w, &v->sb.h);
	if (!v->sb.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sb.ad = mlx_get_data_addr(v->sb.img, &v->sb.bpp, &v->sb.llen, &v->sb.en);
	v->sb2.img = mlx_xpm_file_to_image(v->mlx,
			"tx/SF12.xpm", &v->sb2.w, &v->sb2.h);
	if (!v->sb2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sb2.ad = mlx_get_data_addr(v->sb2.img,
			&v->sb2.bpp, &v->sb2.llen, &v->sb2.en);
	v->n1.img = mlx_xpm_file_to_image(v->mlx, "tx/N1.xpm", &v->n1.w, &v->n1.h);
	if (!v->n1.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->n1.ad = mlx_get_data_addr(v->n1.img, &v->n1.bpp, &v->n1.llen, &v->n1.en);
}

void	ft_init_sprites_part5(t_v *v)
{
	v->n12.img = mlx_xpm_file_to_image(v->mlx,
			"tx/N12.xpm", &v->n12.w, &v->n12.h);
	if (!v->n12.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->n12.ad = mlx_get_data_addr(v->n12.img,
			&v->n12.bpp, &v->n12.llen, &v->n12.en);
}
