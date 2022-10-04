/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:56:42 by chillion          #+#    #+#             */
/*   Updated: 2022/10/04 18:51:09 by chillion         ###   ########.fr       */
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
	{
		if (v->m.np == 0)
			ft_init_draw_sprite(v, v->n1, x, y);
		if (v->m.np == 1)
			ft_init_draw_sprite(v, v->n2, x, y);
	}
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
	{
		if (v->m.np == 0)
			ft_init_draw_sprite(v, v->n12, x, y);
		if (v->m.np == 1)
			ft_init_draw_sprite(v, v->n22, x, y);
	}
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

void	ft_init_sprites_part3(t_v *v)
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

	v->sl2.img = mlx_xpm_file_to_image(v->mlx, "tx/SL12.xpm", &v->sl2.w, &v->sl2.h);
	if (!v->sl2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sl2.ad = mlx_get_data_addr(v->sl2.img, &v->sl2.bpp, &v->sl2.llen, &v->sl2.en);
	v->sr2.img = mlx_xpm_file_to_image(v->mlx, "tx/SR12.xpm", &v->sr2.w, &v->sr2.h);
	if (!v->sr2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sr2.ad = mlx_get_data_addr(v->sr2.img, &v->sr2.bpp, &v->sr2.llen, &v->sr2.en);
	v->sh2.img = mlx_xpm_file_to_image(v->mlx, "tx/SB12.xpm", &v->sh2.w, &v->sh2.h);
	if (!v->sh2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sh2.ad = mlx_get_data_addr(v->sh2.img, &v->sh2.bpp, &v->sh2.llen, &v->sh2.en);
	v->sb2.img = mlx_xpm_file_to_image(v->mlx, "tx/SF12.xpm", &v->sb2.w, &v->sb2.h);
	if (!v->sb2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sb2.ad = mlx_get_data_addr(v->sb2.img, &v->sb2.bpp, &v->sb2.llen, &v->sb2.en);

	v->ex2.img = mlx_xpm_file_to_image(v->mlx, "tx/E2.xpm", &v->ex2.w, &v->ex2.h);
	if (!v->ex2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->ex2.ad = mlx_get_data_addr(v->ex2.img, &v->ex2.bpp, &v->ex2.llen, &v->ex2.en);
	v->c12.img = mlx_xpm_file_to_image(v->mlx, "tx/C12.xpm", &v->c12.w, &v->c12.h);
	if (!v->c12.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->c12.ad = mlx_get_data_addr(v->c12.img, &v->c12.bpp, &v->c12.llen, &v->c12.en);
	v->c22.img = mlx_xpm_file_to_image(v->mlx, "tx/C22.xpm", &v->c22.w, &v->c22.h);
	if (!v->c22.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->c22.ad = mlx_get_data_addr(v->c22.img, &v->c22.bpp, &v->c22.llen, &v->c22.en);

	v->n1.img = mlx_xpm_file_to_image(v->mlx, "tx/N1.xpm", &v->n1.w, &v->n1.h);
	if (!v->n1.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->n1.ad = mlx_get_data_addr(v->n1.img, &v->n1.bpp, &v->n1.llen, &v->n1.en);
	v->n12.img = mlx_xpm_file_to_image(v->mlx, "tx/N12.xpm", &v->n12.w, &v->n12.h);
	if (!v->n12.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->n12.ad = mlx_get_data_addr(v->n12.img, &v->n12.bpp, &v->n12.llen, &v->n12.en);
	v->n2.img = mlx_xpm_file_to_image(v->mlx, "tx/N2.xpm", &v->n2.w, &v->n2.h);
	if (!v->n2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->n2.ad = mlx_get_data_addr(v->n2.img, &v->n2.bpp, &v->n2.llen, &v->n2.en);
	v->n22.img = mlx_xpm_file_to_image(v->mlx, "tx/N22.xpm", &v->n22.w, &v->n22.h);
	if (!v->n22.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->n22.ad = mlx_get_data_addr(v->n22.img, &v->n22.bpp, &v->n22.llen, &v->n22.en);
}

void	ft_init_data2(t_v *v)
{
	v->m.its = 2;
	v->m.pp = 0;
	v->m.np = 0;
	v->ig.addr_use = 1;
	v->m.status = 0;
	v->m.conso = 0;
	v->key_count = 0;
	v->frame = 1;
	ft_init_sprites_part1(v);
	ft_init_sprites_part3(v);
}

void	str_menu_data(t_v *v)
{
	mlx_string_put(v->mlx, v->win, 2, 12, 0x00000000, "Move :");
	mlx_string_put(v->mlx, v->win, 40, 12, 0x00000000, ft_itoa(v->key_count));
}

void	ft_anim_end_game(t_v *v, t_data sprite)
{
	int	i;
	int	j;

	i = (((v->m.h) * v->sb.h) / 2);
	j = ((v->m.w * v->sb.w) / 2);
	ft_font_rainbow(v);
	ft_draw_big_sheep(v, sprite, i, j);
	mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
}

int	ft_anim(t_v *v)
{
	v->render_waiting += 1; 
	if (v->frame == 0 && v->render_waiting == 10000)
	{
		v->render_waiting = 0;
		v->frame = 1;
		ft_draw_refresh2(v);
	}
	else if (v->frame == 1 && v->render_waiting == 10000)
	{
		v->render_waiting = 0;
		v->frame = 0;
		ft_draw_refresh1(v);
	}
	if (v->frame == 3 && v->render_waiting == 10000)
	{
		v->render_waiting = 0;
		v->frame = 4;
		ft_anim_end_game(v, v->sl);
	}
	else if (v->frame == 4 && v->render_waiting == 10000)
	{
		v->render_waiting = 0;
		v->frame = 3;
		ft_anim_end_game(v, v->sl2);
	}
	if (v->frame == 5 && v->render_waiting == 10000)
	{
		v->render_waiting = 0;
		v->frame = 6;
		ft_anim_end_game(v, v->n1);
	}
	else if (v->frame == 6 && v->render_waiting == 10000)
	{
		v->render_waiting = 0;
		v->frame = 5;
		ft_anim_end_game(v, v->n12);
	}
	str_menu_data(v);
	return (1);
}

int	ft_check_cat_up2(t_v *v)
{
	if (v->m.map[v->m.ny - 1][v->m.px] == 'E' && v->m.its != v->m.itsf)
		return (2);
	if (v->m.map[v->m.ny - 1][v->m.px] == 'N')
		return (3);
	if (v->m.ny > 0 && v->m.map[v->m.ny - 1][v->m.px] != '1')
	{
		ft_switch_player_image(v, (v->m.ny - 1), v->m.px);
		ft_init_draw_sprite(v, v->bg, v->m.px, v->m.ny);
		v->m.ny = v->m.ny - 1;
		v->m.map[v->m.ny][v->m.px] = 'P';
		v->m.map[v->m.ny + 1][v->m.px] = '0';
		if (v->m.np == 0)
			ft_init_draw_sprite(v, v->n1, v->m.nx, v->m.ny);
		else
			ft_init_draw_sprite(v, v->n2, v->m.nx, v->m.ny);
		return (1);
	}
	return (0);
}

int	ft_check_cat_down2(t_v *v)
{
	if (v->m.map[v->m.ny + 1][v->m.nx] == 'E' && v->m.its != v->m.itsf)
		return (2);
	if (v->m.map[v->m.ny + 1][v->m.nx] == 'N')
		return (3);
	if (v->m.ny < v->m.w - 1 && v->m.map[v->m.ny + 1][v->m.nx] != '1')
	{
		ft_switch_player_image(v, (v->m.ny + 1), v->m.nx);
		ft_init_draw_sprite(v, v->bg, v->m.nx, v->m.ny);
		v->m.ny = v->m.ny + 1;
		v->m.map[v->m.ny][v->m.nx] = 'P';
		v->m.map[v->m.ny - 1][v->m.nx] = '0';
		if (v->m.np == 0)
			ft_init_draw_sprite(v, v->n1, v->m.nx, v->m.ny);
		else
			ft_init_draw_sprite(v, v->n2, v->m.nx, v->m.ny);
		return (1);
	}
	return (0);
}

int	ft_check_cat_right2(t_v *v)
{
	if (v->m.map[v->m.ny][v->m.nx + 1] == 'E')
		return (2);
	if (v->m.map[v->m.ny][v->m.nx + 1] == 'P')
		return (3);
	if (v->m.nx < v->m.h - 1 && v->m.map[v->m.ny][v->m.nx + 1] != '1')
	{
		v->m.np = 1;
		ft_switch_player_image(v, v->m.ny, (v->m.nx + 1));
		ft_init_draw_sprite(v, v->bg, v->m.nx, v->m.ny);
		v->m.nx = v->m.nx + 1;
		v->m.map[v->m.ny][v->m.nx] = 'N';
		v->m.map[v->m.ny][v->m.nx - 1] = '0';
		ft_init_draw_sprite(v, v->n2, v->m.nx, v->m.ny);
		return (1);
	}
	return (0);
}

int	ft_check_cat_left2(t_v *v)
{
	if (v->m.map[v->m.ny][v->m.nx - 1] == 'E')
		return (2);
	if (v->m.map[v->m.ny][v->m.nx - 1] == 'N')
		return (3);
	if (v->m.nx > 0 && v->m.map[v->m.ny][v->m.nx - 1] != '1')
	{
		v->m.np = 0;
		ft_switch_player_image(v, v->m.ny, (v->m.nx - 1));
		ft_init_draw_sprite(v, v->bg, v->m.nx, v->m.ny);
		v->m.nx = v->m.nx - 1;
		v->m.map[v->m.ny][v->m.nx] = 'N';
		v->m.map[v->m.ny][v->m.nx + 1] = '0';
		ft_init_draw_sprite(v, v->n1, v->m.nx, v->m.ny);
		return (1);
	}
	return (0);
}

int	ft_check_player_up2(t_v *v)
{
	if (v->m.map[v->m.py - 1][v->m.px] == 'E' && v->m.its != v->m.itsf)
		return (2);
	if (v->m.map[v->m.py - 1][v->m.px] == 'N')
		return (3);
	if (v->m.py > 0 && v->m.map[v->m.py - 1][v->m.px] != '1')
	{
		v->m.pp = 3;
		ft_switch_player_image(v, (v->m.py - 1), v->m.px);
		ft_init_draw_sprite(v, v->bg, v->m.px, v->m.py);
		v->m.py = v->m.py - 1;
		ft_switch_end_game(v, (v->m.py), v->m.px);
		if (v->m.status != 1)
		{
			v->m.map[v->m.py][v->m.px] = 'P';
			v->m.map[v->m.py + 1][v->m.px] = '0';
			ft_init_draw_sprite(v, v->sh, v->m.px, v->m.py);
		}
		v->key_count = v->key_count + 1;
		return (1);
	}
	return (0);
}

int	ft_check_player_down2(t_v *v)
{
	if (v->m.map[v->m.py + 1][v->m.px] == 'E' && v->m.its != v->m.itsf)
		return (2);
	if (v->m.map[v->m.py + 1][v->m.px] == 'N')
		return (3);
	if (v->m.py < v->m.w - 1 && v->m.map[v->m.py + 1][v->m.px] != '1')
	{
		v->m.pp = 2;
		ft_switch_player_image(v, (v->m.py + 1), v->m.px);
		ft_init_draw_sprite(v, v->bg, v->m.px, v->m.py);
		v->m.py = v->m.py + 1;
		ft_switch_end_game(v, (v->m.py), v->m.px);
		if (v->m.status != 1)
		{
			v->m.map[v->m.py][v->m.px] = 'P';
			v->m.map[v->m.py - 1][v->m.px] = '0';
			ft_init_draw_sprite(v, v->sb, v->m.px, v->m.py);
		}
		v->key_count = v->key_count + 1;
		return (1);
	}
	return (0);
}

int	ft_check_player_right2(t_v *v)
{
	if (v->m.map[v->m.py][v->m.px + 1] == 'E' && v->m.its != v->m.itsf)
		return (2);
	if (v->m.map[v->m.py][v->m.px + 1] == 'N')
		return (3);
	if (v->m.px < v->m.h - 1 && v->m.map[v->m.py][v->m.px + 1] != '1')
	{
		v->m.pp = 1;
		ft_switch_player_image(v, v->m.py, (v->m.px + 1));
		ft_init_draw_sprite(v, v->bg, v->m.px, v->m.py);
		v->m.px = v->m.px + 1;
		ft_switch_end_game(v, v->m.py, (v->m.px));
		if (v->m.status != 1)
		{
			v->m.map[v->m.py][v->m.px] = 'P';
			v->m.map[v->m.py][v->m.px - 1] = '0';
			ft_init_draw_sprite(v, v->sr, v->m.px, v->m.py);
		}
		v->key_count = v->key_count + 1;
		return (1);
	}
	return (0);
}

int	ft_check_player_left2(t_v *v)
{
	if (v->m.map[v->m.py][v->m.px - 1] == 'E' && v->m.its != v->m.itsf)
		return (2);
	if (v->m.map[v->m.py][v->m.px - 1] == 'N')
		return (3);
	if (v->m.px > 0 && v->m.map[v->m.py][v->m.px - 1] != '1')
	{
		v->m.pp = 0;
		ft_switch_player_image(v, v->m.py, (v->m.px - 1));
		ft_init_draw_sprite(v, v->bg, v->m.px, v->m.py);
		v->m.px = v->m.px - 1;
		ft_switch_end_game(v, v->m.py, (v->m.px));
		if (v->m.status != 1)
		{
			v->m.map[v->m.py][v->m.px] = 'P';
			v->m.map[v->m.py][v->m.px + 1] = '0';
			ft_init_draw_sprite(v, v->sl, v->m.px, v->m.py);
		}
		v->key_count = v->key_count + 1;
		return (1);
	}
	return (0);
}

void	ft_init_big_cat(t_v *v)
{
	v->ig.addr_use = 9;
	mlx_destroy_image(v->mlx, v->n1.img);
	v->n1.img = mlx_xpm_file_to_image(v->mlx, "tx/NF1.xpm", &v->n1.w, &v->n1.h);
	if (!v->n1.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->n1.ad = mlx_get_data_addr(v->n1.img, &v->n1.bpp, &v->n1.llen, &v->n1.en);
	mlx_destroy_image(v->mlx, v->n12.img);
	v->n12.img = mlx_xpm_file_to_image(v->mlx, "tx/NF2.xpm", &v->n12.w, &v->n12.h);
	if (!v->n12.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->n12.ad = mlx_get_data_addr(v->n12.img, &v->n12.bpp, &v->n12.llen, &v->n12.en);
}

void	ft_switch_bad_end_game(t_v *v, t_data sprite)
{
	int	i;
	int	j;

	i = (((v->m.h) * v->sb.h) / 2);
	j = ((v->m.w * v->sb.w) / 2);
	v->frame = 5;
	ft_font_rainbow(v);
	ft_init_big_cat(v);
	ft_draw_big_sheep(v, sprite, i, j);
	v->m.status = 1;
}

void	ft_draw_player2(t_v *v, int key)
{
	if ((key == 119 || key == 65362) && v->m.status == 0)
		key = ft_check_player_up2(v);
	if ((key == 115 || key == 65364) && v->m.status == 0)
		key = ft_check_player_down2(v);
	if ((key == 100 || key == 65363) && v->m.status == 0)
		key = ft_check_player_right2(v);
	if ((key == 97 || key == 65361) && v->m.status == 0)
		key = ft_check_player_left2(v);
	if (key == 1)
		mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
	if (key == 3)
	{
		ft_switch_bad_end_game(v, v->n1);
		mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
	}
}

int	ft_keypress_event2(int key, t_v *v)
{
	if (key == 65362 || key == 119)
		ft_draw_player2(v, key);
	if (key == 65364 || key == 115)
		ft_draw_player2(v, key);
	if (key == 65363 || key == 100)
		ft_draw_player2(v, key);
	if (key == 65361 || key == 97)
		ft_draw_player2(v, key);
	if (key == 65307)
		ft_close_event(v);
	return (0);
}

void	ft_init_window(char *argv, t_v *v)
{
	int	j;

	j = 0;
	j = ft_size_init_map(argv, v);
	v->m.map = ft_init_map(argv, v, j);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, ((v->m.h) * 48), (v->m.w * 48), "so_long");
	v->ig.img = mlx_new_image(v->mlx, ((v->m.h) * 48), (v->m.w * 48));
	v->ig.ad = mlx_get_data_addr(v->ig.img, &v->ig.bpp, &v->ig.llen, &v->ig.en);
	mlx_hook(v->win, 2, 1L << 0, ft_keypress_event2, v);
	mlx_hook(v->win, 17, 1L << 17, ft_close_event, v);
	ft_printf("TEST ULT1\n");
	ft_init_data2(v);
	ft_printf("TEST ULT2\n");
	ft_draw_map(v);
	ft_printf("TEST ULT3\n");
	mlx_loop_hook(v->mlx, ft_anim, v);
	mlx_loop(v->mlx);
	mlx_destroy_image(v->mlx, v->ig.img);
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_display(v->mlx);
	free(v->mlx);
}

int	ft_parsing_map(char *argv, t_v *v)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	j = ft_size_init_map(argv, v);
	if (j > 28 || j == -1)
	{
		if (j > 28)
			ft_printf("Error\nMAP WIDTH IS TO BIG\n");
		else
			ft_printf("Error\nMAP HEIGHT IS TO BIG\n");
		free(v);
		exit(EXIT_FAILURE);
	}
	v->m.map = ft_init_map(argv, v, j);
	i = ft_ctrl_map_size(v, i);
	if (ft_contour_map_control(v, i) != 0 || ft_elements_map_control(v) != 0
		|| ft_control_its(v) == 0 || ft_invasion_loop(v) != v->m.its)
		ft_exit_map(v, i);
	ft_clean_map(v, i);
	return (i);
}

int	main(int argc, char **argv)
{
	t_v		*v;

	if (argc == 2)
	{
		v = (t_v *)malloc(sizeof(t_v));
		if (!v)
			return (0);
		ft_printf("TEST ULTA\n");
		ft_parsing_map(argv[1], v);
		ft_printf("TEST ULTB\n");
		ft_init_window(argv[1], v);
		ft_clean_map(v, 0);
		free(v);
	}
	return (0);
}
/* 
void	ft_init_window(char *argv, t_v *v)
{
	int	j;

	j = 0;
	j = ft_size_init_map(argv, v);
	v->m.map = ft_init_map(argv, v, j);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, ((v->m.h) * 48), (v->m.w * 48), "so_long");
	v->ig.img = mlx_new_image(v->mlx, ((v->m.h) * 48), (v->m.w * 48));
	v->ig.ad = mlx_get_data_addr(v->ig.img, &v->ig.bpp, &v->ig.llen, &v->ig.en);
	mlx_hook(v->win, 2, 1L << 0, ft_keypress_event, v);
	mlx_hook(v->win, 17, 1L << 17, ft_close_event, v);
	ft_init_data(v);
	ft_draw_map(v);
	mlx_loop(v->mlx);
	mlx_destroy_image(v->mlx, v->ig.img);
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_display(v->mlx);
	free(v->mlx);
}

int	ft_parsing_map(char *argv, t_v *v)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	j = ft_size_init_map(argv, v);
	if (j > 28 || j == -1)
	{
		if (j > 28)
			ft_printf("Error\nMAP WIDTH IS TO BIG\n");
		else
			ft_printf("Error\nMAP HEIGHT IS TO BIG\n");
		free(v);
		exit(EXIT_FAILURE);
	}
	v->m.map = ft_init_map(argv, v, j);
	i = ft_ctrl_map_size(v, i);
	if (ft_contour_map_control(v, i) != 0 || ft_elements_map_control(v) != 0
		|| ft_control_its(v) == 0 || ft_invasion_loop(v) != v->m.its)
		ft_exit_map(v, i);
	ft_clean_map(v, i);
	return (i);
}

int	main(int argc, char **argv)
{
	t_v		*v;

	if (argc == 2)
	{
		v = (t_v *)malloc(sizeof(t_v));
		if (!v)
			return (0);
		ft_parsing_map(argv[1], v);
		ft_init_window(argv[1], v);
		ft_clean_map(v, 0);
		free(v);
	}
	return (0);
}
 */