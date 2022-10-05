/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_anim_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:25:15 by chillion          #+#    #+#             */
/*   Updated: 2022/10/05 16:32:02 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	str_menu_data(t_v *v)
{
	char	*str;

	mlx_string_put(v->mlx, v->win, 2, 12, 0x00000000, "Move :");
	str = ft_itoa(v->key_count);
	mlx_string_put(v->mlx, v->win, 40, 12, 0x00000000, str);
	free(str);
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

void	ft_anim_part1(t_v *v)
{
	if (v->frame == 0 && v->render_waiting == 4000)
	{
		v->render_waiting = 0;
		v->frame = 1;
		ft_draw_refresh2(v);
	}
	else if (v->frame == 1 && v->render_waiting == 4000)
	{
		v->render_waiting = 0;
		v->frame = 0;
		ft_draw_refresh1(v);
	}
	if (v->frame == 3 && v->render_waiting == 4000)
	{
		v->render_waiting = 0;
		v->frame = 4;
		ft_anim_end_game(v, v->sb);
	}
	else if (v->frame == 4 && v->render_waiting == 4000)
	{
		v->render_waiting = 0;
		v->frame = 3;
		ft_anim_end_game(v, v->sb2);
	}
}

int	ft_anim(t_v *v)
{
	v->render_waiting += 1;
	ft_anim_part1(v);
	if (v->frame == 5 && v->render_waiting == 4000)
	{
		v->render_waiting = 0;
		v->frame = 6;
		ft_anim_end_game(v, v->n1);
	}
	else if (v->frame == 6 && v->render_waiting == 4000)
	{
		v->render_waiting = 0;
		v->frame = 5;
		ft_anim_end_game(v, v->n12);
	}
	str_menu_data(v);
	return (1);
}
