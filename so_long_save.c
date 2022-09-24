/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:56:42 by chillion          #+#    #+#             */
/*   Updated: 2022/09/23 15:04:23 by chillion         ###   ########.fr       */
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
	char	**map2;
	int		height;
	int		width;
	int		items;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_data	pix;
	t_data	tmp;
	t_map	*map;
}	t_vars;

void	ft_stop_all(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->pix.img);
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
	vars->tmp.img = mlx_new_image(vars->mlx, 40, 40);
	vars->tmp.addr = mlx_get_data_addr(vars->tmp.img, &vars->tmp.bits_per_pixel, &vars->tmp.line_length, &vars->tmp.endian);
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
                my_mlx_pixel_put(&vars->tmp, i, j, 0xFFFFFF00);
        }
    }
	my_mlx_pixel_put(&vars->tmp, 0, 20, 0xFFFFFF00);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->tmp.img, 380, 230);
	mlx_destroy_image(vars->mlx, vars->tmp.img);
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

	vars->tmp.img = mlx_new_image(vars->mlx, HEIGHT, WIDTH);
	vars->tmp.addr = mlx_get_data_addr(vars->tmp.img, &vars->tmp.bits_per_pixel, &vars->tmp.line_length, &vars->tmp.endian);
	while(i < HEIGHT)
	{
		while (j < WIDTH)
		{
			my_mlx_pixel_put(&vars->tmp, i, j, ft_rgb_to_int(0, color1, color2, color3));
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
	mlx_put_image_to_window(vars->mlx, vars->win, vars->tmp.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->tmp.img);
}

int ft_render_next_frame(t_vars *vars)
{
	int i = 0, j = 0;
	static int x = 0;
	static int color1 = 255, color2 = 0, color3 = 255;
	vars->tmp.img = mlx_new_image(vars->mlx, HEIGHT, WIDTH);
	vars->tmp.addr = mlx_get_data_addr(vars->tmp.img, &vars->tmp.bits_per_pixel, &vars->tmp.line_length, &vars->tmp.endian);
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
			my_mlx_pixel_put(&vars->tmp, i, j, ft_rgb_to_int(0, color1, color2, color3));
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->tmp.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->tmp.img);
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

	vars->tmp.img = mlx_new_image(vars->mlx, 800, 500); // DRAW 1 IMAGE With FULL LiNE
	vars->tmp.addr = mlx_get_data_addr(vars->tmp.img, &vars->tmp.bits_per_pixel, &vars->tmp.line_length, &vars->tmp.endian);
	while (pixels)
	{
		my_mlx_pixel_put(&vars->tmp, pixelx, pixely, color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->tmp.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->tmp.img);
}

void ft_draw_img_tmp(t_vars *vars, int pos)
{
	int i;
	int j;

	ft_printf("POS :%d\n", pos);
	vars->tmp.img = mlx_new_image(vars->mlx, 800, 25);
	vars->tmp.addr = mlx_get_data_addr(vars->tmp.img, &vars->tmp.bits_per_pixel, &vars->tmp.line_length, &vars->tmp.endian);
	j = 0;
	while (j <= 25)
	{
		i = 0;
		while (i <= 400)
		{
			my_mlx_pixel_put(&vars->tmp, i, j, 0xFFFFFF00);
			i++;
		}
		while (i >= 401 && i <= 800)
		{
			my_mlx_pixel_put(&vars->tmp, i, j, 0xFFFF00FF);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->tmp.img, 0, pos);
	mlx_destroy_image(vars->mlx, vars->tmp.img);
}

void	ft_move_img(t_vars *vars, int key)
{
	int	i;
	
	ft_printf("vars->pix.pos :%d\n", vars->pix.pos);
	if (key == 65364)
	{
		if (vars->pix.pos <= 475){
			vars->pix.pos = vars->pix.pos + 25;
			i = vars->pix.pos;
			if (vars->pix.pos <=500)
				mlx_put_image_to_window(vars->mlx, vars->win, vars->pix.img, 0, i);
		}
	}
	if (key == 65362)
	{
		if (vars->pix.pos >= 25)
		{
			vars->pix.pos = vars->pix.pos - 25;
			i = vars->pix.pos;
			if (vars->pix.pos >= 0)
				ft_draw_img_tmp(vars, vars->pix.pos);
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
			my_mlx_pixel_put(&vars->pix, i, j, 0xFFFF00FF);
			i++;
		}
		while (i >= 401 && i <= 800)
		{
			my_mlx_pixel_put(&vars->pix, i, j, 0xFFFFFF00);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->pix.img, 0, 0);
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

char **ft_init_map(char *argv, t_map map)
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
	map.map = (char **)malloc(sizeof(char *) * 100);
	if (!map.map)
		return (0);
	map.map[i] = get_next_line(fd);
	while (map.map[i])
	{
		i++;
		map.map[i] = get_next_line(fd);
	}
	fd = close(fd);
	return (map.map);
}

void	ft_clean_map(t_map map, int i)
{
	while (--i >= 0)
		ft_free(&map.map[i]);
	free(map.map);
}

void	ft_exit_map(t_map map, int i)
{
	ft_clean_map(map, i);
	exit(EXIT_FAILURE);
}

int	ft_map_height(t_map map)
{
	int	height;

	height = 0;
	while (map.map[0][height])
		height++;
	return (height);
}

int	ft_map_width(t_map map)
{
	int	width;

	width = 0;
	while (map.map[width])
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

int	ft_west_offensive(int x, int y, int items, t_map map)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (map.map[tmpy][tmpx] != '1')
	{
		if (map.map[tmpy][tmpx] == 'C' || map.map[tmpy][tmpx] == 'E')
			items = items + 1;
		if (map.map[tmpy][tmpx] != '1')
			map.map[tmpy][tmpx] = 'P';
		if (map.map[tmpy - 1][tmpx] != '1')
			map.map[tmpy - 1][tmpx] = 'P';
		if (map.map[tmpy + 1][tmpx] != '1')
			map.map[tmpy + 1][tmpx] = 'P';
		tmpx--;
	}
	return (items);
}

int	ft_north_offensive(int x, int y, int items, t_map map)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (map.map[tmpy][tmpx] != '1')
	{
		if (map.map[tmpy][tmpx] == 'C' || map.map[tmpy][tmpx] == 'E')
			items = items + 1;
		if (map.map[tmpy][tmpx] != '1')
			map.map[tmpy][tmpx] = 'P';
		if (map.map[tmpy][tmpx - 1] != '1')
			map.map[tmpy][tmpx - 1] = 'P';
		if (map.map[tmpy][tmpx + 1] != '1')
			map.map[tmpy][tmpx + 1] = 'P';
		tmpy--;
	}
	return (items);
}

int	ft_east_offensive(int x, int y, int items, t_map map)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (map.map[tmpy][tmpx] != '1')
	{
		if (map.map[tmpy][tmpx] == 'C' || map.map[tmpy][tmpx] == 'E')
			items = items + 1;
		if (map.map[tmpy][tmpx] != '1')
			map.map[tmpy][tmpx] = 'P';
		if (map.map[tmpy - 1][tmpx] != '1')
			map.map[tmpy - 1][tmpx] = 'P';
		if (map.map[tmpy + 1][tmpx] != '1')
			map.map[tmpy + 1][tmpx] = 'P';
		tmpx++;
	}
	return (items);
}

int	ft_south_offensive(int x, int y, int items, t_map map)
{
	int	tmpx;
	int	tmpy;

	tmpy = y;
	tmpx = x;
	while (map.map[tmpy][tmpx] != '1')
	{
		if (map.map[tmpy][tmpx] == 'C' || map.map[tmpy][tmpx] == 'E')
			items = items + 1;
		if (map.map[tmpy][tmpx] != '1')
			map.map[tmpy][tmpx] = 'P';
		if (map.map[tmpy][tmpx - 1] != '1')
			map.map[tmpy][tmpx - 1] = 'P';
		if (map.map[tmpy][tmpx + 1] != '1')
			map.map[tmpy][tmpx + 1] = 'P';
		tmpy++;
	}
	return (items);
}

int	ft_invasion_propagation(int x, int y, t_map map)
{
	int	items;
	
	items = 1;
	
	items = ft_west_offensive(x, y, items, map);
	items = ft_north_offensive(x, y, items, map);
	items = ft_east_offensive(x, y, items, map);
	items = ft_south_offensive(x, y, items, map);
//=	ft_print_map(map.map);
/* 	if (items == map.items)
		return (0); */
	return (items);
}

int	ft_invasion_checker(t_map map)
{
	int	x;
	int	y;
	
	y = 1;
	while (y < map.width - 1)
	{
		x = 1;
		while (x < map.height - 2)
		{
			if (map.map[y][x] == 'P')
			{
				if(map.map[y][x - 1] == '0' || map.map[y][x + 1] == '0' || map.map[y - 1][x] == '0' || map.map[y + 1][x] == '0'
				|| map.map[y][x - 1] == 'C' || map.map[y][x + 1] == 'C' || map.map[y - 1][x] == 'C' || map.map[y + 1][x] == 'C')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_invasion_loop(t_map *map)
{
	int	x;
	int	y;
	
	map->height = ft_map_height(*map);
	map->width = ft_map_width(*map);
	y = 1;
	while (y < map->width - 1)
	{
		x = 1;
		while (x < map->height - 2)
		{
			if (map->map[y][x] == 'P')
			{
				if(map->map[y][x - 1] == '0' || map->map[y][x + 1] == '0' || map->map[y - 1][x] == '0' || map->map[y + 1][x] == '0'
				|| map->map[y][x - 1] == 'C' || map->map[y][x + 1] == 'C' || map->map[y - 1][x] == 'C' || map->map[y + 1][x] == 'C')
					ft_invasion_propagation(x, y, *map);
			}
			x++;
		}
		y++;
	}
	if (ft_invasion_checker(*map) != 0)
		return (ft_invasion_loop(map));
}

int	ft_ctrl_map_size(t_map *map, int i)
{
	int	width;
	int	dif;
	int	line_size;

	dif = 0;
	while (map->map[i])
	{
		width = 0;
		while (map->map[i][width])
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
		perror("Error\nTAILLE DE LA MAP ");
		ft_exit_map(*map, i);
	}
	return (i);
}

int	ft_map_control(t_map *map, int i)
{
	int	j;
	int	k;
	int	len;
	int	error;

	j = 0;
	error = 0;
	while (map->map[j])
	{
		k = 0;
		while (map->map[j][k + 1])
		{
			if (map->map[0][k] != '1' || map->map[i - 1][k] != '1' || map->map[j][0] != '1')
				error += 1;
			if (j == 0)
				len = k;
			if (j != 0 && map->map[j][len] != '1')
				error += 1;
			k++;
		}
		j++;
	}
	if (error != 0)
		ft_printf("Error\nFORMAT DE LA MAP : %s\n", strerror(22));
	return (error);
}

int	ft_control_item(t_map *map, char c)
{
	int	x;
	int	y;
	int	item;

	x = 0;
	y = 0;
	item = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == c)
				item += 1;
			x++;
		}
		y++;
	}
	return (item);
}

int	ft_control_items(t_map *map)
{
	int	exit;
	int	player;
	int	conso;

	exit = ft_control_item(map, 'E');
	player = ft_control_item(map, 'P');
	conso = ft_control_item(map, 'C');
	ft_printf("E :%d et P :%d, C :%d\n", exit, player, conso);
	if (exit == 1 && player == 1 && conso >= 1)
	{
		map->items = player + exit + conso;
		ft_printf("MAP ITEMS :%d\n", map->items);
		return (player);
	}
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

int ft_parsing_map(char *argv, t_vars vars)
{
	int		i;
	
	i = 0;
	vars.map = (t_map *)malloc(sizeof(t_map));
	if (!vars.map)
		return (0);
	vars.map->map = NULL;
	vars.map->map = ft_init_map(argv, *vars.map);
	i = ft_ctrl_map_size(vars.map, i);
	if (ft_map_control(vars.map, i) != 0 || ft_control_items(vars.map) == 0)
		ft_exit_map(*vars.map, i);
	ft_invasion_loop(vars.map);
	ft_printf("TEST :%d", vars.map->items);
	ft_print_map(vars.map->map);
	ft_clean_map(*vars.map, i);
	vars.map->map = ft_init_map(argv, *vars.map);
	ft_print_map(vars.map->map);
	ft_clean_map(*vars.map, i);
	free(vars.map);
	return (i);
}

int	main(int argc, char **argv)
{
	int	j;
	t_vars vars;
	
	
	if (argc == 2)
	{
		ft_printf("Debut du SO_LONG!\n");
		j = ft_parsing_map(argv[1], vars);
		ft_printf("Fin du SO_LONG! J=%d\n", j);
	}
	return (0);
}
