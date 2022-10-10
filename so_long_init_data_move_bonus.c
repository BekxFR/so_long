/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_data_move_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:37:37 by chillion          #+#    #+#             */
/*   Updated: 2022/10/06 16:55:06 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_init_data(t_v *v)
{
	v->m.its = 2;
	v->m.pp = 0;
	v->m.np = 0;
	v->ig.addr_use = 1;
	v->ig.free_status = 0;
	v->m.status = 0;
	v->m.conso = 0;
	v->key_count = 0;
	v->frame = 1;
	v->render_waiting = 0;
	ft_init_sprites_part1(v);
	ft_init_sprites_part2(v);
	ft_init_sprites_part3(v);
	ft_init_sprites_part4(v);
	ft_init_sprites_part5(v);
}
