/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_checker_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:35:23 by chillion          #+#    #+#             */
/*   Updated: 2022/10/05 16:15:36 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_player_up(t_v *v)
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

int	ft_check_player_down(t_v *v)
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

int	ft_check_player_right(t_v *v)
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

int	ft_check_player_left(t_v *v)
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
