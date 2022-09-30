/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:56:42 by chillion          #+#    #+#             */
/*   Updated: 2022/09/30 19:05:56 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define HEIGHT 800
#define WIDTH 600

typedef struct s_data {
	void	*img;
	char	*addr;
	int		pos;
	int		addr_use;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		color1;
	int		color2;
	int		color3;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		w;
	int		h;
	int		playerx;
	int		playery;
	int		conso;
	int		status;
	int		items;
	int		items_find;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		key_count;
	t_data	img;
	t_data	font;
	t_data	wall;
	t_data	sheepl;
	t_data	sheepr;
	t_data	sheepb;
	t_data	sheeph;
	t_data	conso;
	t_data	conso2;
	t_data	exit;
	t_map	map;
}	t_vars;

void	ft_stop_all(t_vars *vars)
{
	ft_printf("ADDR_USE :%d\n", vars->img.addr_use);
	if (vars->img.addr_use >= 1)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->img.addr_use >= 2)
		mlx_destroy_image(vars->mlx, vars->font.img);
	if (vars->img.addr_use >= 3)
		mlx_destroy_image(vars->mlx, vars->conso.img);
	if (vars->img.addr_use >= 4)
		mlx_destroy_image(vars->mlx, vars->conso2.img);
	if (vars->img.addr_use >= 5)
		mlx_destroy_image(vars->mlx, vars->exit.img);
	if (vars->img.addr_use >= 6)
		mlx_destroy_image(vars->mlx, vars->wall.img);
	if (vars->img.addr_use >= 7)
		mlx_destroy_image(vars->mlx, vars->sheepl.img);
	if (vars->img.addr_use >= 8)
		mlx_destroy_image(vars->mlx, vars->sheepr.img);
	if (vars->img.addr_use >= 9)
		mlx_destroy_image(vars->mlx, vars->sheeph.img);
	if (vars->img.addr_use >= 10)
		mlx_destroy_image(vars->mlx, vars->sheepb.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

void	ft_my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * 4);
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

int	ft_rainbow_color(t_vars *vars, int x)
{
	if (vars->img.color3 != 0 && x == 0)
	{
		vars->img.color3--;
		if (vars->img.color3 == 0)
			x++;
	}
	else if (vars->img.color2 != 255 && x == 1)
		vars->img.color2++;
	else if (vars->img.color1 != 0 && x == 1)
		vars->img.color1--;
	else if (vars->img.color3 != 255 && x == 1)
	{
		vars->img.color3++;
		if (vars->img.color3 == 255)
			x++;
	}
	else if (vars->img.color2 != 0 && x == 2)
		vars->img.color2--;
	else if (vars->img.color1 != 255 && x == 2)
	{
		vars->img.color1++;
		if (vars->img.color1 == 255)
			x = 0;
	}
	return (x);
}

void	ft_font_rainbow(t_vars *vars)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	vars->img.color1 = 255;
	vars->img.color2 = 0;
	vars->img.color3 = 255;
	while (i < ((vars->map.height) * 48))
	{
		while (j < (vars->map.width * 48))
		{
			ft_my_mlx_pixel_put(&vars->img, i, j,
				ft_rgb_to_int(0, vars->img.color1,
					vars->img.color2, vars->img.color3));
			if (j % 250 == 0)
				x = ft_rainbow_color(vars, x);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

int	ft_line_init_size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_fd_error(t_vars *vars)
{
	ft_printf("%s\n", strerror(errno));
	free(vars);
	exit(EXIT_FAILURE);
}

int	ft_size_init_map(char *argv, t_vars *vars)
{
	int		fd;
	int		i;
	int		j;
	char	*str;

	j = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_fd_error(vars);
	i = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (ft_line_init_size(str) > 54)
			j = -1;
		free(str);
		str = get_next_line(fd);
		i++;
	}
	fd = close(fd);
	if (j == -1)
		i = -1;
	return (i);
}

char	**ft_init_map(char *argv, t_vars *vars, int j)
{
	int	fd;
	int	i;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_fd_error(vars);
	i = 0;
	vars->map.map = (char **)malloc(sizeof(char *) * (j + 1));
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
		if (vars->map.map[tmpy][tmpx] == 'C'
			|| vars->map.map[tmpy][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy - 1][tmpx] == 'C'
			|| vars->map.map[tmpy - 1][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy + 1][tmpx] == 'C'
			|| vars->map.map[tmpy + 1][tmpx] == 'E')
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
		if (vars->map.map[tmpy][tmpx] == 'C'
			|| vars->map.map[tmpy][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx - 1] == 'C'
			|| vars->map.map[tmpy][tmpx - 1] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx + 1] == 'C'
			|| vars->map.map[tmpy][tmpx + 1] == 'E')
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
		if (vars->map.map[tmpy][tmpx] == 'C'
			|| vars->map.map[tmpy][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy - 1][tmpx] == 'C'
			|| vars->map.map[tmpy - 1][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy + 1][tmpx] == 'C'
			|| vars->map.map[tmpy + 1][tmpx] == 'E')
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
		if (vars->map.map[tmpy][tmpx] == 'C'
			|| vars->map.map[tmpy][tmpx] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx - 1] == 'C'
			|| vars->map.map[tmpy][tmpx - 1] == 'E')
			vars->map.items_find = vars->map.items_find + 1;
		if (vars->map.map[tmpy][tmpx + 1] == 'C'
			|| vars->map.map[tmpy][tmpx + 1] == 'E')
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
		while (x < vars->map.height - 1)
		{
			if (vars->map.map[y][x] == 'P')
			{
				if ((vars->map.map[y][x - 1] != '1' && vars->map.map[y][x - 1] != 'P')
					|| (vars->map.map[y][x + 1] != '1' && vars->map.map[y][x + 1] != 'P')
						|| (vars->map.map[y - 1][x] != '1' && vars->map.map[y - 1][x] != 'P')
							|| (vars->map.map[y + 1][x] != '1' && vars->map.map[y + 1][x] != 'P'))
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
		while (x < vars->map.height - 1)
		{
			if (vars->map.map[y][x] == 'P' && vars->map.items_find != vars->map.items)
			{
				if (vars->map.map[y][x - 1] != '1' || vars->map.map[y][x + 1] != '1' || vars->map.map[y - 1][x] != '1' || vars->map.map[y + 1][x] != '1')
					vars->map.items_find = ft_invasion_propagation(x, y, vars);
			}
			x++;
		}
		y++;
	}
	if (ft_invasion_checker(vars) != 0
		&& vars->map.items_find != vars->map.items)
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

	vars->map.height = ft_map_height(vars) - 1;
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
	int		j;
	int		k;
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
	if (exit == 1 && player == 1 && conso >= 1)
	{
		vars->map.items = player + exit + conso;
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

int	ft_close_event(t_vars *vars)
{
	ft_stop_all(vars);
	ft_clean_map(vars, 0);
	free(vars);
	ft_printf("Fin du SO_LONG V2!\n");
	exit(0);
}

void	ft_init_draw_player(t_vars *vars, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < 48)
	{
		j = 0;
		while (j < 48)
		{
			color = ft_get_color(&vars->sheepl, j, i);
			ft_my_mlx_pixel_put(&vars->img, j + (x * 48), i + (y * 48), color);
			j++;
		}
		i++;
	}
}

void	ft_draw_player_right(t_vars *vars, int x, int y)
{
	int	i;
	int	j;
	int	color;
	
	i = 0;
	j = 0;
	color = 0;
	while (i < 48)
	{
		j = 0;
		while (j < 48)
		{
			color = ft_get_color(&vars->sheepr, j, i);
			ft_my_mlx_pixel_put(&vars->img, j + (x * 48), i + (y * 48), color);
			j++;
		}
		i++;
	}
}

void	ft_draw_player_down(t_vars *vars, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < 48)
	{
		j = 0;
		while (j < 48)
		{
			color = ft_get_color(&vars->sheepb, j, i);
			ft_my_mlx_pixel_put(&vars->img, j + (x * 48), i + (y * 48), color);
			j++;
		}
		i++;
	}
}

void	ft_draw_player_up(t_vars *vars, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < 48)
	{
		j = 0;
		while (j < 48)
		{
			color = ft_get_color(&vars->sheeph, j, i);
			ft_my_mlx_pixel_put(&vars->img, j + (x * 48), i + (y * 48), color);
			j++;
		}
		i++;
	}
}

void	ft_init_draw_font(t_vars *vars, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < 48)
	{
		j = 0;
		while (j < 48)
		{
			color = ft_get_color(&vars->font, j, i);
			ft_my_mlx_pixel_put(&vars->img, j + (x * 48), i + (y * 48), color);
			j++;
		}
		i++;
	}
}

void	ft_init_draw_wall(t_vars *vars, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < 48)
	{
		j = 0;
		while (j < 48)
		{
			color = ft_get_color(&vars->wall, j, i);
			ft_my_mlx_pixel_put(&vars->img, j + (x * 48), i + (y * 48), color);
			j++;
		}
		i++;
	}
}

void	ft_init_draw_collectable(t_vars *vars, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < 48)
	{
		j = 0;
		while (j < 48)
		{
			color = ft_get_color(&vars->conso, j, i);
			ft_my_mlx_pixel_put(&vars->img, j + (x * 48), i + (y * 48), color);
			j++;
		}
		i++;
	}
}

void	ft_init_draw_collectable2(t_vars *vars, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < 48)
	{
		j = 0;
		while (j < 48)
		{
			color = ft_get_color(&vars->conso2, j, i);
			ft_my_mlx_pixel_put(&vars->img, j + (x * 48), i + (y * 48), color);
			j++;
		}
		i++;
	}
}

void	ft_init_draw_exit(t_vars *vars, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	j = 0;
	color = 0;
	while (i < 48)
	{
		j = 0;
		while (j < 48)
		{
			color = ft_get_color(&vars->exit, j, i);
			ft_my_mlx_pixel_put(&vars->img, j + (x * 48), i + (y * 48), color);
			j++;
		}
		i++;
	}
}

void	ft_draw_map_new(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map.map[y])
	{
		x = 0;
		while (vars->map.map[y][x])
		{
			if (vars->map.map[y][x] == '1')
				ft_init_draw_wall(vars, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	ft_draw_big_sheep(t_vars *vars, int x, int y)
{
	double		i;
	double		j;
	int			color;
	double		ratio;

	j = 0;
	mlx_destroy_image(vars->mlx, vars->sheepb.img);
	vars->sheepb.img = mlx_xpm_file_to_image(vars->mlx, "./textures/SheepYF.xpm", &vars->sheepb.width, &vars->sheepb.height);
	vars->sheepb.addr = mlx_get_data_addr(vars->sheepb.img, &vars->sheepb.bits_per_pixel, &vars->sheepb.line_length, &vars->sheepb.endian);
	ratio = ((double)vars->sheepb.width / (double)(((vars->map.height) * vars->map.width)));
	x = x - (((vars->map.height) * vars->map.width) / 2);
	y = y - (((vars->map.height) * vars->map.width) / 2);
	while (j < (double)((vars->map.height) * vars->map.width))
	{
		i = 0;
		while (i < (double)((vars->map.height) * vars->map.width))
		{
			color = ft_get_color(&vars->sheepb, i * ratio, j * ratio);
			if (color != 0x000000FF)
				ft_my_mlx_pixel_put(&vars->img, (x + i), (y + j), color);
			i++;
		}
		j++;
	}
}

void	ft_init_new_sprites(t_vars *vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "./textures/Tree2.xpm", &vars->wall.width, &vars->wall.height);
	if (!vars->wall.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->wall.addr = mlx_get_data_addr(vars->wall.img, &vars->wall.bits_per_pixel, &vars->wall.line_length, &vars->wall.endian);
	vars->sheepl.img = mlx_xpm_file_to_image(vars->mlx, "./textures/SheepYCL.xpm", &vars->sheepl.width, &vars->sheepl.height);
	if (!vars->sheepl.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->sheepl.addr = mlx_get_data_addr(vars->sheepl.img, &vars->sheepl.bits_per_pixel, &vars->sheepl.line_length, &vars->sheepl.endian);
	vars->sheepr.img = mlx_xpm_file_to_image(vars->mlx, "./textures/SheepYCR.xpm", &vars->sheepr.width, &vars->sheepr.height);
	if (!vars->sheepr.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->sheepr.addr = mlx_get_data_addr(vars->sheepr.img, &vars->sheepr.bits_per_pixel, &vars->sheepr.line_length, &vars->sheepr.endian);
	vars->sheeph.img = mlx_xpm_file_to_image(vars->mlx, "./textures/SheepYCB.xpm", &vars->sheeph.width, &vars->sheeph.height);
	if (!vars->sheeph.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->sheeph.addr = mlx_get_data_addr(vars->sheeph.img, &vars->sheeph.bits_per_pixel, &vars->sheeph.line_length, &vars->sheeph.endian);
	vars->sheepb.img = mlx_xpm_file_to_image(vars->mlx, "./textures/SheepYCF.xpm", &vars->sheepb.width, &vars->sheepb.height);
	if (!vars->sheepb.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->sheepb.addr = mlx_get_data_addr(vars->sheepb.img, &vars->sheepb.bits_per_pixel, &vars->sheepb.line_length, &vars->sheepb.endian);
}

void	ft_switch_player_image(t_vars *vars, int x, int y)
{
	if (vars->map.map[x][y] == 'C')
	{
		vars->map.items = vars->map.items + 1;
		vars->map.map[x][y] = '0';
	}
	if (vars->map.map[x][y] == '2')
	{
		vars->map.items = vars->map.items + 1;
		vars->img.addr_use = 5;
		mlx_destroy_image(vars->mlx, vars->wall.img);
		mlx_destroy_image(vars->mlx, vars->sheepl.img);
		mlx_destroy_image(vars->mlx, vars->sheepr.img);
		mlx_destroy_image(vars->mlx, vars->sheepb.img);
		mlx_destroy_image(vars->mlx, vars->sheeph.img);
		ft_init_new_sprites(vars);
		ft_draw_map_new(vars);
		vars->map.map[x][y] = '0';
	}
}

void	ft_switch_end_game(t_vars *vars, int x, int y)
{
	int	i;
	int	j;

	i = (((vars->map.height) * vars->sheepb.height) / 2);
	j = ((vars->map.width * vars->sheepb.width) / 2);
	if (vars->map.map[x][y] == 'E' && vars->map.items == vars->map.items_find)
	{
		ft_font_rainbow(vars);
		ft_draw_big_sheep(vars, i, j);
		vars->map.status = 1;
	}
}

int	ft_check_player_up(t_vars *vars)
{
	if (vars->map.map[vars->map.playery - 1][vars->map.playerx] == 'E' && vars->map.items != vars->map.items_find)
		return (2);
	if (vars->map.playery > 0 && vars->map.map[vars->map.playery - 1][vars->map.playerx] != '1')
	{
		ft_switch_player_image(vars, (vars->map.playery - 1), vars->map.playerx);
		ft_init_draw_font(vars, vars->map.playerx, vars->map.playery);
		vars->map.playery = vars->map.playery - 1;
		ft_draw_player_up(vars, vars->map.playerx, vars->map.playery);
		ft_switch_end_game(vars, (vars->map.playery), vars->map.playerx);
		vars->key_count = vars->key_count + 1;
		ft_printf("Move :%d\n", vars->key_count);
		return (1);
	}
	return (0);
}

int	ft_check_player_down(t_vars *vars)
{
	if (vars->map.map[vars->map.playery + 1][vars->map.playerx] == 'E' && vars->map.items != vars->map.items_find)
		return (2);
	if (vars->map.playery < vars->map.width - 1 && vars->map.map[vars->map.playery + 1][vars->map.playerx] != '1')
	{
		ft_switch_player_image(vars, (vars->map.playery + 1), vars->map.playerx);
		ft_init_draw_font(vars, vars->map.playerx, vars->map.playery);
		vars->map.playery = vars->map.playery + 1;
		ft_draw_player_down(vars, vars->map.playerx, vars->map.playery);
		ft_switch_end_game(vars, (vars->map.playery), vars->map.playerx);
		vars->key_count = vars->key_count + 1;
		ft_printf("Move :%d\n", vars->key_count);
		return (1);
	}
	return (0);
}

int	ft_check_player_right(t_vars *vars)
{
	if (vars->map.map[vars->map.playery][vars->map.playerx + 1] == 'E' && vars->map.items != vars->map.items_find)
		return (2);
	if (vars->map.playerx < vars->map.height - 1 && vars->map.map[vars->map.playery][vars->map.playerx + 1] != '1')
	{
		ft_switch_player_image(vars, vars->map.playery, (vars->map.playerx + 1));
		ft_init_draw_font(vars, vars->map.playerx, vars->map.playery);
		vars->map.playerx = vars->map.playerx + 1;
		ft_draw_player_right(vars, vars->map.playerx, vars->map.playery);
		ft_switch_end_game(vars, vars->map.playery, (vars->map.playerx));
		vars->key_count = vars->key_count + 1;
		ft_printf("Move :%d\n", vars->key_count);
		return (1);
	}
	return (0);
}

int	ft_check_player_left(t_vars *vars)
{
	if (vars->map.map[vars->map.playery][vars->map.playerx - 1] == 'E' && vars->map.items != vars->map.items_find)
		return (2);
	if (vars->map.playerx > 0 && vars->map.map[vars->map.playery][vars->map.playerx - 1] != '1')
	{
		ft_switch_player_image(vars, vars->map.playery, (vars->map.playerx - 1));
		ft_init_draw_font(vars, vars->map.playerx, vars->map.playery);
		vars->map.playerx = vars->map.playerx - 1;
		ft_init_draw_player(vars, vars->map.playerx, vars->map.playery);
		ft_switch_end_game(vars, vars->map.playery, (vars->map.playerx));
		vars->key_count = vars->key_count + 1;
		ft_printf("Move :%d\n", vars->key_count);
		return (1);
	}
	return (0);
}

void	ft_draw_player(t_vars *vars, int key)
{
	if ((key == 119 || key == 65362) && vars->map.status == 0)
		key = ft_check_player_up(vars);
	if ((key == 115 || key == 65364) && vars->map.status == 0)
		key = ft_check_player_down(vars);
	if ((key == 100 || key == 65363) && vars->map.status == 0)
		key = ft_check_player_right(vars);
	if ((key == 97 || key == 65361) && vars->map.status == 0)
		key = ft_check_player_left(vars);
	if (key == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, vars->map.h, vars->map.w);
}

void	ft_init_draws(t_vars *vars, int x, int y, char c)
{
	if (c == '1')
		ft_init_draw_wall(vars, x, y);
	if (c == 'P')
	{
		vars->map.playerx = x;
		vars->map.playery = y;
		ft_init_draw_player(vars, x, y);
	}
	if (c == '0')
		ft_init_draw_font(vars, x, y);
	if (c == 'C' && vars->map.conso == 0)
	{
		ft_init_draw_collectable(vars, x, y);
		vars->map.map[y][x] = '2';
		vars->map.conso = 1;
	}
	else if (c == 'C')
		ft_init_draw_collectable2(vars, x, y);
	if (c == 'E')
		ft_init_draw_exit(vars, x, y);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, vars->map.h, vars->map.w);
}

int	ft_keypress_event(int key, t_vars *vars)
{
	if (key == 65362 || key == 119)
		ft_draw_player(vars, key);
	if (key == 65364 || key == 115)
		ft_draw_player(vars, key);
	if (key == 65363 || key == 100)
		ft_draw_player(vars, key);
	if (key == 65361 || key == 97)
		ft_draw_player(vars, key);
	if (key == 65307)
		ft_close_event(vars);
	return (0);
}

void	ft_draw_map(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map.map[y])
	{
		x = 0;
		while (vars->map.map[y][x])
		{
			if (vars->map.map[y][x] == '1')
				ft_init_draws(vars, x, y, '1');
			if (vars->map.map[y][x] == 'P')
				ft_init_draws(vars, x, y, 'P');
			if (vars->map.map[y][x] == '0')
				ft_init_draws(vars, x, y, '0');
			if (vars->map.map[y][x] == 'C')
				ft_init_draws(vars, x, y, 'C');
			if (vars->map.map[y][x] == 'E')
				ft_init_draws(vars, x, y, 'E');
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	ft_init_sprites_part1(t_vars *vars)
{
	vars->font.img = mlx_xpm_file_to_image(vars->mlx, "./textures/Grass.xpm", &vars->font.width, &vars->font.height);
	if (!vars->font.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->font.addr = mlx_get_data_addr(vars->font.img, &vars->font.bits_per_pixel, &vars->font.line_length, &vars->font.endian);
	vars->conso.img = mlx_xpm_file_to_image(vars->mlx, "./textures/YCombi.xpm", &vars->conso.width, &vars->conso.height);
	if (!vars->conso.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->conso.addr = mlx_get_data_addr(vars->conso.img, &vars->conso.bits_per_pixel, &vars->conso.line_length, &vars->conso.endian);
	vars->conso2.img = mlx_xpm_file_to_image(vars->mlx, "./textures/BFlowerConso.xpm", &vars->conso2.width, &vars->conso2.height);
	if (!vars->conso2.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->conso2.addr = mlx_get_data_addr(vars->conso2.img, &vars->conso2.bits_per_pixel, &vars->conso2.line_length, &vars->conso2.endian);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "./textures/Shower1.xpm", &vars->exit.width, &vars->exit.height);
	if (!vars->exit.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->exit.addr = mlx_get_data_addr(vars->exit.img, &vars->exit.bits_per_pixel, &vars->exit.line_length, &vars->exit.endian);
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "./textures/Tree.xpm", &vars->wall.width, &vars->wall.height);
	if (!vars->wall.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->wall.addr = mlx_get_data_addr(vars->wall.img, &vars->wall.bits_per_pixel, &vars->wall.line_length, &vars->wall.endian);
}

void	ft_init_sprites_part2(t_vars *vars)
{
	vars->sheepl.img = mlx_xpm_file_to_image(vars->mlx, "./textures/SheepL.xpm", &vars->sheepl.width, &vars->sheepl.height);
	if (!vars->sheepl.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->sheepl.addr = mlx_get_data_addr(vars->sheepl.img, &vars->sheepl.bits_per_pixel, &vars->sheepl.line_length, &vars->sheepl.endian);
	vars->sheepr.img = mlx_xpm_file_to_image(vars->mlx, "./textures/SheepR.xpm", &vars->sheepr.width, &vars->sheepr.height);
	if (!vars->sheepr.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->sheepr.addr = mlx_get_data_addr(vars->sheepr.img, &vars->sheepr.bits_per_pixel, &vars->sheepr.line_length, &vars->sheepr.endian);
	vars->sheeph.img = mlx_xpm_file_to_image(vars->mlx, "./textures/SheepB.xpm", &vars->sheeph.width, &vars->sheeph.height);
	if (!vars->sheeph.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->sheeph.addr = mlx_get_data_addr(vars->sheeph.img, &vars->sheeph.bits_per_pixel, &vars->sheeph.line_length, &vars->sheeph.endian);
	vars->sheepb.img = mlx_xpm_file_to_image(vars->mlx, "./textures/SheepF.xpm", &vars->sheepb.width, &vars->sheepb.height);
	if (!vars->sheepb.img)
		ft_close_event(vars);
	vars->img.addr_use = vars->img.addr_use + 1;
	vars->sheepb.addr = mlx_get_data_addr(vars->sheepb.img, &vars->sheepb.bits_per_pixel, &vars->sheepb.line_length, &vars->sheepb.endian);
}

void	ft_init_data(t_vars *vars)
{
	vars->map.items = 2;
	vars->img.addr_use = 1;
	vars->map.status = 0;
	vars->map.conso = 0;
	vars->key_count = 0;
	ft_init_sprites_part1(vars);
	ft_init_sprites_part2(vars);
}

void	ft_init_window(char *argv, t_vars *vars)
{
	int	j;

	j = 0;
	j = ft_size_init_map(argv, vars);
	vars->map.map = ft_init_map(argv, vars, j);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, ((vars->map.height) * 48), (vars->map.width * 48), "so_long");
	vars->img.img = mlx_new_image(vars->mlx, ((vars->map.height) * 48), (vars->map.width * 48));
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	mlx_hook(vars->win, 2, 1L << 0, ft_keypress_event, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_close_event, vars);
	ft_init_data(vars);
	ft_draw_map(vars);
	mlx_loop(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
}

int	ft_parsing_map(char *argv, t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	j = ft_size_init_map(argv, vars);
	if (j > 28 || j == -1)
	{
		if (j > 28)
			ft_printf("Error\nMAP WIDTH IS TO BIG\n");
		else
			ft_printf("Error\nMAP HEIGHT IS TO BIG\n");
		ft_exit_map(vars, i);
	}
	vars->map.map = ft_init_map(argv, vars, j);
	ft_print_map(vars->map.map);
	i = ft_ctrl_map_size(vars, i);
	if (ft_contour_map_control(vars, i) != 0 || ft_elements_map_control(vars) != 0
		|| ft_control_items(vars) == 0 || ft_invasion_loop(vars) != vars->map.items)
		ft_exit_map(vars, i);
	ft_clean_map(vars, i);
	return (i);
}

int	main(int argc, char **argv)
{
	int		j;
	t_vars	*vars;

	if (argc == 2)
	{
		vars = (t_vars *)malloc(sizeof(t_vars));
		if (!vars)
			return (0);
		ft_printf("Debut du SO_LONG!\n");
		j = ft_parsing_map(argv[1], vars);
		ft_init_window(argv[1], vars);
		ft_clean_map(vars, 0);
		free(vars);
		ft_printf("Fin du SO_LONG! J=%d\n", j);
	}
	return (0);
}
