/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:56:42 by chillion          #+#    #+#             */
/*   Updated: 2022/09/24 17:56:54 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define HEIGHT 800
#define WIDTH 600

typedef struct s_data {
	void	*img;
	char	*addr;
	int		pos;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		items;
	int		items_find;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	map;
}	t_vars;

void	ft_stop_all(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}
 
int ft_close_event(t_vars *vars)
{
	ft_stop_all(vars);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_circle(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, 40, 40);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	int r = 20;
	int N = 2*r+1;
    int x, y;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            x = i-r;
            y = j-r;
 
            if (x*x + y*y <= r*r+1 )
                my_mlx_pixel_put(&vars->img, i, j, 0xFFFFFF00);
        }
    }
	my_mlx_pixel_put(&vars->img, 0, 20, 0xFFFFFF00);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 380, 230);
	mlx_destroy_image(vars->mlx, vars->img.img);
}

int ft_rgb_to_int(int t, int r, int g, int b)
{
	int color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	color |= t << 24;
	return (color);
}

void ft_font_rainbow(t_vars *vars)
{
	int color1 = 255, color2 = 0, color3 = 255;
	int i = 0;
	int j = 0;
	int x = 0;

	vars->img.img = mlx_new_image(vars->mlx, HEIGHT, WIDTH);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	while(i < HEIGHT)
	{
		while (j < WIDTH)
		{
			my_mlx_pixel_put(&vars->img, i, j, ft_rgb_to_int(0, color1, color2, color3));
			if (j %250 == 0)
			{
				if (color3 != 0 && x == 0)
				{
					color3--;
					if (color3 == 0)
						x++;
				}
				else if (color2 != 255 && x == 1)
					color2++;
				else if (color1 != 0 && x == 1)
					color1--;
				else if (color3 != 255 && x == 1)
				{
					color3++;
					if (color3 == 255)
						x++;
				}
				else if (color2 != 0 && x == 2)
					color2--;
				else if (color1 != 255 && x == 2)
				{
					color1++;
					if (color1 == 255)
						x = 0;
				}
			}
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
}

int ft_render_next_frame(t_vars *vars)
{
	int i = 0, j = 0;
	static int x = 0;
	static int color1 = 255, color2 = 0, color3 = 255;
	vars->img.img = mlx_new_image(vars->mlx, HEIGHT, WIDTH);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	if (color3 != 0 && x == 0)
	{
		color3--;
		if (color3 == 0)
			x++;
	}
	else if (color2 != 255 && x == 1)
		color2++;
	else if (color1 != 0 && x == 1)
		color1--;
	else if (color3 != 255 && x == 1)
	{
		color3++;
		if (color3 == 255)
			x++;
	}
	else if (color2 != 0 && x == 2)
		color2--;
	else if (color1 != 255 && x == 2)
	{
		color1++;
		if (color1 == 255)
			x = 0;
	}
	while(i < HEIGHT)
	{
		while (j < WIDTH)
		{
			my_mlx_pixel_put(&vars->img, i, j, ft_rgb_to_int(0, color1, color2, color3));
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
	return (1);
}

void	ft_draw_line(t_vars *vars, int beginx, int beginy, int endx, int endy, int color)
{
	double deltax = endx - beginx;
	double deltay = endy - beginy;
	double pixelx = beginx;
	double pixely = beginy;
	int pixels = ft_sqrt((deltax * deltax) + (deltay * deltay));

	deltax /= pixels;
	deltay /= pixels;

	vars->img.img = mlx_new_image(vars->mlx, 800, 500); // DRAW 1 IMAGE With FULL LiNE
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	while (pixels)
	{
		my_mlx_pixel_put(&vars->img, pixelx, pixely, color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
}

void ft_draw_img_tmp(t_vars *vars, int pos)
{
	int i;
	int j;

	ft_printf("POS :%d\n", pos);
	vars->img.img = mlx_new_image(vars->mlx, 800, 25);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	j = 0;
	while (j <= 25)
	{
		i = 0;
		while (i <= 400)
		{
			my_mlx_pixel_put(&vars->img, i, j, 0xFFFFFF00);
			i++;
		}
		while (i >= 401 && i <= 800)
		{
			my_mlx_pixel_put(&vars->img, i, j, 0xFFFF00FF);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, pos);
	mlx_destroy_image(vars->mlx, vars->img.img);
}

void	ft_move_img(t_vars *vars, int key)
{
	int	i;
	
	ft_printf("vars->img.pos :%d\n", vars->img.pos);
	if (key == 65364)
	{
		if (vars->img.pos <= 475){
			vars->img.pos = vars->img.pos + 25;
			i = vars->img.pos;
			if (vars->img.pos <=500)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, i);
		}
	}
	if (key == 65362)
	{
		if (vars->img.pos >= 25)
		{
			vars->img.pos = vars->img.pos - 25;
			i = vars->img.pos;
			if (vars->img.pos >= 0)
				ft_draw_img_tmp(vars, vars->img.pos);
		}
	}
}

int	ft_keypress_event(int key, t_vars *vars)
{
	ft_printf("Key = %d\n", key);
	if (key == 65362){ft_move_img(vars, key);} //haut
	if (key == 65364){ft_move_img(vars, key);} //bas
	if (key == 65363){ft_draw_circle(vars);} //droite
	if (key == 65361){ft_draw_line(vars, 800, 500, 0, 0, 0xFFFFFFFF);} //gauche
	if (key == 119){} //w
	if (key == 115){} //s
	if (key == 100){} //d
	if (key == 97){} //a
	if (key == 65307) //echap
		ft_close_event(vars);
	return (0);
}

void ft_draw_img_test(t_vars *vars)
{
	int i;
	int j;

	j = 0;
	while (j <= 25)
	{
		i = 0;
		while (i <= 400)
		{
			my_mlx_pixel_put(&vars->img, i, j, 0xFFFF00FF);
			i++;
		}
		while (i >= 401 && i <= 800)
		{
			my_mlx_pixel_put(&vars->img, i, j, 0xFFFFFF00);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

/* int	main(void)
{
	t_vars	vars;

	ft_printf("0xFF000000 =%d\t0x00FF0000 =%d\t0x0000FF00 =%d\t0x000000FF =%d\t0x1FFFFFFF =%d\n", 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF, 0x70000000);
	ft_printf("0xFFFFFFFF =%d\t0xFFFFFF00 =%d\t0xFFFF0000 =%d\t0x0000FFFF =%d\n", 0xFFFFFFFF, 0xFFFFFF00, 0xFFFF0000, 0x0000FFFF);
	ft_printf("0x00FFFF00 =%d\t0x00FF00FF =%d\t0xFF00FF00 =%d\t0x00FFFFFF =%d\n", 0x00FFFF00, 0x00FF00FF, 0x80000000, 0x7FFFFFFF);
//	ft_printf("color =%d\n", ft_rgb_to_int(255, 0, 0, 0));

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, HEIGHT, WIDTH, "so_long");
	vars.img.img = mlx_new_image(vars.mlx, 80, 50);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	my_mlx_pixel_put(&vars.img, 0, 0, 0xFFFFFFFF);
	my_mlx_pixel_put(&vars.img, 0, 0, 0xFFFFFF00);
	my_mlx_pixel_put(&vars.img, 10, 0, 0x00FFFFFF);
	my_mlx_pixel_put(&vars.img, 20, 10, 0xFF00FFFF);
	my_mlx_pixel_put(&vars.img, 30, 20, 0xFFFF00FF);
	my_mlx_pixel_put(&vars.img, 40, 30, 0xFFFFFF00);
	my_mlx_pixel_put(&vars.img, 50, 40, 0xFFFFFFFF);
	my_mlx_pixel_put(&vars.img, 80, 50, 0xFFFFFFFF);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 300, 200);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 400, 300);
	vars.pix.img = mlx_new_image(vars.mlx, 800, 25);
	vars.pix.pos = 0;
	vars.pix.addr = mlx_get_data_addr(vars.pix.img, &vars.pix.bits_per_pixel, &vars.pix.line_length, &vars.pix.endian);
	ft_draw_img_test(&vars, 800, 500);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 300, 200);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 400, 300);
	mlx_hook(vars.win, 2, 1L<<0, ft_keypress_event, &vars);
	mlx_hook(vars.win, 17, 1L<<17, ft_close_event, &vars);
	ft_font_rainbow(&vars);
	ft_draw_circle(&vars);
	mlx_pixel_put(vars.mlx, vars.win, 400, 250, 0x00000000);
	mlx_loop_hook(vars.mlx, ft_render_next_frame, &vars);
//	ft_render_next_frame(&vars);
	mlx_loop(vars.mlx);
	ft_stop_all(&vars);
	return (0);
} */

char **ft_init_map(char *argv, t_vars *vars)
{
	int	fd;
	int	i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s", strerror(errno));
		exit(EXIT_FAILURE);
	}
	i = 0;
	vars->map.map = (char **)malloc(sizeof(char *) * 100);
	if (!vars->map.map)
		return (0);
	vars->map.map[i] = get_next_line(fd);
	while (vars->map.map[i])
	{
		i++;
		vars->map.map[i] = get_next_line(fd);
	}
	fd = close(fd);
	return (vars->map.map);
}

void	ft_clean_map(t_vars *vars, int i)
{
	i = 0;
	while (vars->map.map[i])
	{
		ft_free(&vars->map.map[i]);
		i++;
	}
	free(vars->map.map);
}

void	ft_exit_map(t_vars *vars, int i)
{
	ft_clean_map(vars, i);
	free(vars);
	exit(EXIT_FAILURE);
}

int	ft_map_height(t_vars *vars)
{
	int	height;

	height = 0;
	while (vars->map.map[0][height])
		height++;
	return (height);
}

int	ft_map_width(t_vars *vars)
{
	int	width;

	width = 0;
	while (vars->map.map[width])
		width++;
	return (width);
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

int	ft_west_offensive(int x, int y, t_vars *vars)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (vars->map.map[tmpy][tmpx] != '1')
	{
		if (vars->map.map[tmpy][tmpx] == 'C' || vars->map.map[tmpy][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy - 1][tmpx] == 'C' || vars->map.map[tmpy - 1][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy + 1][tmpx] == 'C' || vars->map.map[tmpy + 1][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx] != '1')
			vars->map.map[tmpy][tmpx] = 'P';
		if (vars->map.map[tmpy - 1][tmpx] != '1')
			vars->map.map[tmpy - 1][tmpx] = 'P';
		if (vars->map.map[tmpy + 1][tmpx] != '1')
			vars->map.map[tmpy + 1][tmpx] = 'P';
		tmpx--;
	}
	return (vars->map.items_find);
}

int	ft_north_offensive(int x, int y, t_vars *vars)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (vars->map.map[tmpy][tmpx] != '1')
	{
		if (vars->map.map[tmpy][tmpx] == 'C' || vars->map.map[tmpy][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx - 1] == 'C' || vars->map.map[tmpy][tmpx - 1] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx + 1] == 'C' || vars->map.map[tmpy][tmpx + 1] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx] != '1')
			vars->map.map[tmpy][tmpx] = 'P';
		if (vars->map.map[tmpy][tmpx - 1] != '1')
			vars->map.map[tmpy][tmpx - 1] = 'P';
		if (vars->map.map[tmpy][tmpx + 1] != '1')
			vars->map.map[tmpy][tmpx + 1] = 'P';
		tmpy--;
	}
	return (vars->map.items_find);
}

int	ft_east_offensive(int x, int y, t_vars *vars)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (vars->map.map[tmpy][tmpx] != '1')
	{
		if (vars->map.map[tmpy][tmpx] == 'C' || vars->map.map[tmpy][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy - 1][tmpx] == 'C' || vars->map.map[tmpy - 1][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy + 1][tmpx] == 'C' || vars->map.map[tmpy + 1][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx] != '1')
			vars->map.map[tmpy][tmpx] = 'P';
		if (vars->map.map[tmpy - 1][tmpx] != '1')
			vars->map.map[tmpy - 1][tmpx] = 'P';
		if (vars->map.map[tmpy + 1][tmpx] != '1')
			vars->map.map[tmpy + 1][tmpx] = 'P';
		tmpx++;
	}
	return (vars->map.items_find);
}

int	ft_south_offensive(int x, int y, t_vars *vars)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (vars->map.map[tmpy][tmpx] != '1')
	{
		if (vars->map.map[tmpy][tmpx] == 'C' || vars->map.map[tmpy][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx - 1] == 'C' || vars->map.map[tmpy][tmpx - 1] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx + 1] == 'C' || vars->map.map[tmpy][tmpx + 1] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx] != '1')
			vars->map.map[tmpy][tmpx] = 'P';
		if (vars->map.map[tmpy][tmpx - 1] != '1')
			vars->map.map[tmpy][tmpx - 1] = 'P';
		if (vars->map.map[tmpy][tmpx + 1] != '1')
			vars->map.map[tmpy][tmpx + 1] = 'P';
		tmpy++;
	}
	return (vars->map.items_find);
}

int	ft_invasion_propagation(int x, int y, t_vars *vars)
{
	ft_west_offensive(x, y, vars);
	if (vars->map.items_find == vars->map.items)
		return (vars->map.items_find);
	ft_north_offensive(x, y, vars);
	if (vars->map.items_find == vars->map.items)
		return (vars->map.items);
	ft_east_offensive(x, y, vars);
	if (vars->map.items_find == vars->map.items)
		return (vars->map.items);
	ft_south_offensive(x, y, vars);
	if (vars->map.items_find == vars->map.items)
		return (vars->map.items);
	return (vars->map.items_find);
}

int	ft_invasion_checker(t_vars *vars)
{
	int	x;
	int	y;
	
	y = 1;
	while (y < vars->map.width - 1)
	{
		x = 1;
		while (x < vars->map.height - 2)
		{
			if (vars->map.map[y][x] == 'P')
			{
				if(vars->map.map[y][x - 1] == '0' || vars->map.map[y][x + 1] == '0' || vars->map.map[y - 1][x] == '0' || vars->map.map[y + 1][x] == '0'
				|| vars->map.map[y][x - 1] == 'C' || vars->map.map[y][x + 1] == 'C' || vars->map.map[y - 1][x] == 'C' || vars->map.map[y + 1][x] == 'C')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_invasion_loop(t_vars *vars)
{
	int	x;
	int	y;

	y = 1;
	while (y < vars->map.width - 1)
	{
		x = 1;
		while (x < vars->map.height - 2)
		{
			if (vars->map.map[y][x] == 'P' && vars->map.items_find != vars->map.items)
			{
				if(vars->map.map[y][x - 1] == '0' || vars->map.map[y][x + 1] == '0' || vars->map.map[y - 1][x] == '0' || vars->map.map[y + 1][x] == '0'
				|| vars->map.map[y][x - 1] == 'C' || vars->map.map[y][x + 1] == 'C' || vars->map.map[y - 1][x] == 'C' || vars->map.map[y + 1][x] == 'C')
					vars->map.items_find = ft_invasion_propagation(x, y, vars);
			}
			x++;
		}
		y++;
	}
	if (ft_invasion_checker(vars) != 0 && vars->map.items_find != vars->map.items)
		return (ft_invasion_loop(vars));
	if (vars->map.items_find != vars->map.items)
		ft_printf("Error\nNO VALABLE PATH - ALL ITEMS CANT BE FIND BY PLAYER\n");
	return (vars->map.items_find);
}

int	ft_ctrl_map_size(t_vars *vars, int i)
{
	int	width;
	int	dif;
	int	line_size;

	vars->map.height = ft_map_height(vars);
	vars->map.width = ft_map_width(vars);
	dif = 0;
	while (vars->map.map[i])
	{
		width = 0;
		while (vars->map.map[i][width])
			width++;
		if (i == 0)
			line_size = width;
		else if (width != line_size || width < 4)
			dif += 1;
		i++;
	}
	if (dif != 0 || i == width - 1 || i < 3)
	{
		errno = 22;
		perror("Error\nMAP SIZE NOT CORRECT ");
		ft_exit_map(vars, i);
	}
	return (i);
}

int	ft_contour_map_control(t_vars *vars, int i)
{
	int	j;
	int	k;
	int	len;
	int	error;

	j = 0;
	error = 0;
	while (vars->map.map[j])
	{
		k = 0;
		while (vars->map.map[j][k + 1])
		{
			if (vars->map.map[0][k] != '1' || vars->map.map[i - 1][k] != '1' || vars->map.map[j][0] != '1')
				error += 1;
			if (j == 0)
				len = k;
			if (vars->map.map[j][len] != '1')
				error += 1;
			k++;
		}
		j++;
	}
	if (error != 0)
		ft_printf("Error\nMAP NOT ENCLOSE BY WALLS : %s\n", strerror(22));
	return (error);
}

int	ft_elements_map_control(t_vars *vars)
{
	int	j;
	int	k;
	char	error;

	j = 1;
	error = 0;
	while (vars->map.map[j + 1])
	{
		k = 1;
		while (vars->map.map[j][k + 1])
		{
			if (vars->map.map[j][k] != '1' && vars->map.map[j][k] != '0' && vars->map.map[j][k] != 'P' && vars->map.map[j][k] != 'E' && vars->map.map[j][k] != 'C')
			{
				error = vars->map.map[j][k];
				break ;
			}
			k++;
		}
		j++;
	}
	if (error != 0)
		ft_printf("Error\nFIND UNKNOWN ELEMENT ON MAP ('%c' is not 'P'layer, 'E'xit, 'C'ollectable or '1'wall)\n", error);
	return (error);
}

int	ft_control_item(t_vars *vars, char c)
{
	int	x;
	int	y;
	int	item;

	x = 0;
	y = 0;
	item = 0;
	vars->map.items_find = 1;
	while (vars->map.map[y])
	{
		x = 0;
		while (vars->map.map[y][x])
		{
			if (vars->map.map[y][x] == c)
				item += 1;
			x++;
		}
		y++;
	}
	return (item);
}

int	ft_control_items(t_vars *vars)
{
	int	exit;
	int	player;
	int	conso;

	exit = ft_control_item(vars, 'E');
	player = ft_control_item(vars, 'P');
	conso = ft_control_item(vars, 'C');
	ft_printf("E :%d et P :%d, C :%d\n", exit, player, conso);
	if (exit == 1 && player == 1 && conso >= 1)
	{
		vars->map.items = player + exit + conso;
		ft_printf("MAP ITEMS :%d\n", vars->map.items);
		return (vars->map.items);
	}
	if (player != 1 || exit != 1 || conso == 0)
		ft_printf("Error\nITEMS NUMBER NOT VALABLE : Player = %d, Exit = %d, Collectable = %d\n", player, exit, conso);
	return (0);
}

char	**ft_strdup_test(char **src)
{
	char	**dest;

	if (!src)
		dest = ft_zalloc(1, sizeof * dest);
	if (!dest)
		return (NULL);
	return (dest);
}

int ft_parsing_map(char *argv, t_vars *vars)
{
	int		i;
	
	i = 0;
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (0);
	vars->map.map = NULL;
	vars->map.map = ft_init_map(argv, vars);
	ft_print_map(vars->map.map); //
	i = ft_ctrl_map_size(vars, i);
	if (ft_contour_map_control(vars, i) != 0 || ft_elements_map_control(vars) != 0
	|| ft_control_items(vars) == 0 || ft_invasion_loop(vars) != vars->map.items)
		ft_exit_map(vars, i);
	ft_print_map(vars->map.map);
	ft_clean_map(vars, i);
	free(vars);
/* 	i = ft_ctrl_map_size(vars, i);
	if (ft_map_control(vars, i) != 0 || ft_control_items(vars) == 0)
		ft_exit_map(vars, i);
	ft_invasion_loop(vars);
	ft_printf("TEST :%d", vars.map.items);
	ft_print_map(vars.map.map);
	ft_clean_map(vars, i);
	vars.map.map = ft_init_map(argv, vars);
	ft_print_map(vars.map.map);
	ft_clean_map(vars, i);
//	free(vars); */
	return (i);
}

int	main(int argc, char **argv)
{
	int	j;
	t_vars *vars;

	vars = NULL;
	if (argc == 2)
	{
		ft_printf("Debut du SO_LONG!\n");
		j = ft_parsing_map(argv[1], vars);
		ft_printf("Fin du SO_LONG! J=%d\n", j);
	}
	return (0);
}
