/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:11:19 by chillion          #+#    #+#             */
/*   Updated: 2022/10/01 18:25:46 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_stop_all(t_v *v)
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
	if (v->ig.addr_use >= 6 && v->wa.img)
		mlx_destroy_image(v->mlx, v->wa.img);
	if (v->ig.addr_use >= 7 && v->sl.img)
		mlx_destroy_image(v->mlx, v->sl.img);
	if (v->ig.addr_use >= 8 && v->sr.img)
		mlx_destroy_image(v->mlx, v->sr.img);
	if (v->ig.addr_use >= 9 && v->sh.img)
		mlx_destroy_image(v->mlx, v->sh.img);
	if (v->ig.addr_use >= 10 && v->sb.img)
		mlx_destroy_image(v->mlx, v->sb.img);
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
	ft_printf("Fin du SO_LONG V2!\n");
	exit(0);
}
