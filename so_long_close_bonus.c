/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_close_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:11:19 by chillion          #+#    #+#             */
/*   Updated: 2022/10/05 18:08:43 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_stop_all(t_v *v)
{
	ft_stop_part1(v);
	ft_stop_part2(v);
	if (v->ig.addr_use >= 15 && v->sh2.img)
		mlx_destroy_image(v->mlx, v->sh2.img);
	if (v->ig.addr_use >= 16 && v->sb.img)
		mlx_destroy_image(v->mlx, v->sb.img);
	if ((v->ig.addr_use >= 17 || v->ig.free_status >= 2) && v->sb2.img)
		mlx_destroy_image(v->mlx, v->sb2.img);
	if ((v->ig.addr_use >= 18 || v->ig.free_status >= 2) && v->n1.img)
		mlx_destroy_image(v->mlx, v->n1.img);
	if ((v->ig.addr_use >= 19 || v->ig.free_status >= 2) && v->n12.img)
		mlx_destroy_image(v->mlx, v->n12.img);
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_display(v->mlx);
	free(v->mlx);
}

void	ft_clean_map(t_v *v, int i)
{
	i = 0;
	while (v->m.map[i])
	{
		ft_free(&v->m.map[i]);
		i++;
	}
	free(v->m.map);
}

void	ft_exit_map(t_v *v, int i)
{
	ft_clean_map(v, i);
	free(v);
	exit(EXIT_FAILURE);
}

void	ft_print_map(char **mptr)
{
	int	i;

	i = 0;
	while (mptr[i])
	{
		ft_printf("%s", mptr[i]);
		i++;
	}
}

int	ft_close_event(t_v *v)
{
	ft_stop_all(v);
	ft_clean_map(v, 0);
	free(v);
	exit(0);
}
