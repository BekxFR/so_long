/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:56:42 by chillion          #+#    #+#             */
/*   Updated: 2022/10/01 18:43:11 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
