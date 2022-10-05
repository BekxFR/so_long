/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_close_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:11:19 by chillion          #+#    #+#             */
/*   Updated: 2022/10/05 16:02:54 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_stop_part1(t_v *v)
{
	if (v->ig.addr_use >= 1 && v->ig.img)
		mlx_destroy_image(v->mlx, v->ig.img);
	if (v->ig.addr_use >= 2 && v->bg.img)
		mlx_destroy_image(v->mlx, v->bg.img);
	if (v->ig.addr_use >= 3 && v->c1.img)
		mlx_destroy_image(v->mlx, v->c1.img);
	if (v->ig.addr_use >= 4 && v->c2.img)
		mlx_destroy_image(v->mlx, v->c2.img);
	if (v->ig.addr_use >= 5 && v->ex.img)
		mlx_destroy_image(v->mlx, v->ex.img);
	if (v->ig.addr_use >= 6 && v->ex2.img)
		mlx_destroy_image(v->mlx, v->ex2.img);
	if (v->ig.addr_use >= 7 && v->c12.img)
		mlx_destroy_image(v->mlx, v->c12.img);
}

void	ft_stop_part2(t_v *v)
{
	if (v->ig.addr_use >= 8 && v->c22.img)
		mlx_destroy_image(v->mlx, v->c22.img);
	if (v->ig.addr_use >= 9 && v->wa.img)
		mlx_destroy_image(v->mlx, v->wa.img);
	if (v->ig.addr_use >= 10 && v->sl.img)
		mlx_destroy_image(v->mlx, v->sl.img);
	if (v->ig.addr_use >= 11 && v->sr.img)
		mlx_destroy_image(v->mlx, v->sr.img);
	if (v->ig.addr_use >= 12 && v->sh.img)
		mlx_destroy_image(v->mlx, v->sh.img);
	if (v->ig.addr_use >= 13 && v->sl2.img)
		mlx_destroy_image(v->mlx, v->sl2.img);
	if (v->ig.addr_use >= 14 && v->sr2.img)
		mlx_destroy_image(v->mlx, v->sr2.img);
}

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
