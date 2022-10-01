/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:11:48 by chillion          #+#    #+#             */
/*   Updated: 2022/10/01 18:12:08 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->ad + (y * data->llen + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->ad + (y * data->llen + x * 4);
	return (*(unsigned int *)dst);
}

int	ft_rgb_to_int(int t, int r, int g, int b)
{
	int	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	color |= t << 24;
	return (color);
}

int	ft_rainbow_color(t_v *v, int x)
{
	if (v->ig.color3 != 0 && x == 0)
	{
		v->ig.color3--;
		if (v->ig.color3 == 0)
			x++;
	}
	else if (v->ig.color2 != 255 && x == 1)
		v->ig.color2++;
	else if (v->ig.color1 != 0 && x == 1)
		v->ig.color1--;
	else if (v->ig.color3 != 255 && x == 1)
	{
		v->ig.color3++;
		if (v->ig.color3 == 255)
			x++;
	}
	else if (v->ig.color2 != 0 && x == 2)
		v->ig.color2--;
	else if (v->ig.color1 != 255 && x == 2)
	{
		v->ig.color1++;
		if (v->ig.color1 == 255)
			x = 0;
	}
	return (x);
}

void	ft_font_rainbow(t_v *v)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	v->ig.color1 = 255;
	v->ig.color2 = 0;
	v->ig.color3 = 255;
	while (i < ((v->m.h) * 48))
	{
		while (j < (v->m.w * 48))
		{
			ft_my_mlx_pixel_put(&v->ig, i, j,
				ft_rgb_to_int(0, v->ig.color1,
					v->ig.color2, v->ig.color3));
			if (j % 250 == 0)
				x = ft_rainbow_color(v, x);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->ig.img, 0, 0);
}
