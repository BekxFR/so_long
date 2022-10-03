/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:56:42 by chillion          #+#    #+#             */
/*   Updated: 2022/10/03 18:48:29 by chillion         ###   ########.fr       */
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

	v->sl2.img = mlx_xpm_file_to_image(v->mlx, "tx/SL2.xpm", &v->sl2.w, &v->sl2.h);
	if (!v->sl2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sl2.ad = mlx_get_data_addr(v->sl2.img, &v->sl2.bpp, &v->sl2.llen, &v->sl2.en);
	v->sr2.img = mlx_xpm_file_to_image(v->mlx, "tx/SR2.xpm", &v->sr2.w, &v->sr2.h);
	if (!v->sr2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sr2.ad = mlx_get_data_addr(v->sr2.img, &v->sr2.bpp, &v->sr2.llen, &v->sr2.en);
	v->sh2.img = mlx_xpm_file_to_image(v->mlx, "tx/SB2.xpm", &v->sh2.w, &v->sh2.h);
	if (!v->sh2.img)
		ft_close_event(v);
	v->ig.addr_use = v->ig.addr_use + 1;
	v->sh2.ad = mlx_get_data_addr(v->sh2.img, &v->sh2.bpp, &v->sh2.llen, &v->sh2.en);
	v->sb2.img = mlx_xpm_file_to_image(v->mlx, "tx/SF2.xpm", &v->sb2.w, &v->sb2.h);
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
}

void	ft_init_data2(t_v *v)
{
	v->m.its = 2;
	v->m.pp = 0;
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

int	ft_anim(t_v *v)
{
	ft_printf("TEST 4 :%d\n", v->frame);
//	sleep (1);
	if (v->frame == 0)
	{
		ft_printf("TEST 5 :%d\n", v->frame);
		v->frame = 1;
		ft_draw_refresh2(v);
	}
	else if (v->frame == 1)
	{
		v->frame = 0;
		ft_draw_refresh1(v);
	}
	str_menu_data(v);
	return (1);
}

int	ft_check_player_up2(t_v *v)
{
	if (v->m.map[v->m.py - 1][v->m.px] == 'E' && v->m.its != v->m.itsf)
		return (2);
	if (v->m.py > 0 && v->m.map[v->m.py - 1][v->m.px] != '1')
	{
		v->m.pp = 3;
		ft_switch_player_image(v, (v->m.py - 1), v->m.px);
		ft_init_draw_sprite(v, v->bg, v->m.px, v->m.py);
		v->m.map[v->m.py - 1][v->m.px] = 'P';
		v->m.map[v->m.py][v->m.px] = '0';
		v->m.py = v->m.py - 1;
		ft_init_draw_sprite(v, v->sh, v->m.px, v->m.py);
		ft_switch_end_game(v, (v->m.py), v->m.px);
		v->key_count = v->key_count + 1;
		ft_printf("Move :%d\n", v->key_count);
		return (1);
	}
	return (0);
}

int	ft_check_player_down2(t_v *v)
{
	if (v->m.map[v->m.py + 1][v->m.px] == 'E' && v->m.its != v->m.itsf)
		return (2);
	if (v->m.py < v->m.w - 1 && v->m.map[v->m.py + 1][v->m.px] != '1')
	{
		v->m.pp = 2;
		ft_switch_player_image(v, (v->m.py + 1), v->m.px);
		ft_init_draw_sprite(v, v->bg, v->m.px, v->m.py);
		v->m.map[v->m.py + 1][v->m.px] = 'P';
		v->m.map[v->m.py][v->m.px] = '0';
		v->m.py = v->m.py + 1;
		ft_init_draw_sprite(v, v->sb, v->m.px, v->m.py);
		ft_switch_end_game(v, (v->m.py), v->m.px);
		v->key_count = v->key_count + 1;
		ft_printf("Move :%d\n", v->key_count);
		return (1);
	}
	return (0);
}

int	ft_check_player_right2(t_v *v)
{
	if (v->m.map[v->m.py][v->m.px + 1] == 'E' && v->m.its != v->m.itsf)
		return (2);
	if (v->m.px < v->m.h - 1 && v->m.map[v->m.py][v->m.px + 1] != '1')
	{
		v->m.pp = 1;
		ft_switch_player_image(v, v->m.py, (v->m.px + 1));
		ft_init_draw_sprite(v, v->bg, v->m.px, v->m.py);
		v->m.map[v->m.py][v->m.px + 1] = 'P';
		v->m.map[v->m.py][v->m.px] = '0';
		v->m.px = v->m.px + 1;
		ft_init_draw_sprite(v, v->sr, v->m.px, v->m.py);
		ft_switch_end_game(v, v->m.py, (v->m.px));
		v->key_count = v->key_count + 1;
		ft_printf("Move :%d\n", v->key_count);
		return (1);
	}
	return (0);
}

int	ft_check_player_left2(t_v *v)
{
	if (v->m.map[v->m.py][v->m.px - 1] == 'E' && v->m.its != v->m.itsf)
		return (2);
	if (v->m.px > 0 && v->m.map[v->m.py][v->m.px - 1] != '1')
	{
		v->m.pp = 0;
		ft_switch_player_image(v, v->m.py, (v->m.px - 1));
		ft_init_draw_sprite(v, v->bg, v->m.px, v->m.py);
		v->m.px = v->m.px - 1;
		ft_switch_end_game(v, v->m.py, (v->m.px));
		v->m.map[v->m.py][v->m.px] = 'P';
		v->m.map[v->m.py][v->m.px + 1] = '0';
		ft_init_draw_sprite(v, v->sl, v->m.px, v->m.py);
		v->key_count = v->key_count + 1;
		ft_printf("Move :%d\n", v->key_count);
		return (1);
	}
	return (0);
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
	ft_init_data2(v);
	ft_draw_map(v);
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
		ft_parsing_map(argv[1], v);
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