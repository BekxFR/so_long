/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chillion <chillion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:30:49 by chillion          #+#    #+#             */
/*   Updated: 2022/10/10 11:26:20 by chillion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "libs/libft/includes/libft.h"
# include "libs/libft/includes/ft_printf.h"
# include "libs/libft/includes/get_next_line.h"
# include "libs/minilibx-linux/mlx.h"

typedef struct s_data {
	void	*img;
	char	*ad;
	int		pos;
	int		addr_use;
	int		free_status;
	int		bpp;
	int		llen;
	int		en;
	int		w;
	int		h;
	int		color1;
	int		color2;
	int		color3;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		w;
	int		h;
	int		px;
	int		py;
	int		nx;
	int		ny;
	int		conso;
	int		status;
	int		pp;
	int		np;
	int		its;
	int		itsf;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		key_count;
	int		render_waiting;
	int		frame;
	t_data	ig;
	t_data	bg;
	t_data	wa;
	t_data	sl;
	t_data	sr;
	t_data	sb;
	t_data	sh;
	t_data	sl2;
	t_data	sr2;
	t_data	sb2;
	t_data	sh2;
	t_data	c1;
	t_data	c12;
	t_data	c2;
	t_data	c22;
	t_data	ex;
	t_data	ex2;
	t_data	n1;
	t_data	n12;
	t_data	n2;
	t_data	n22;
	t_map	m;
}	t_v;

/* so_long_close */
void			ft_stop_all(t_v *v);
void			ft_clean_map(t_v *v, int i);
void			ft_exit_map(t_v *v, int i);
void			ft_print_map(char **mptr);
int				ft_close_event(t_v *v);

/* so_long_close */
void			ft_stop_part1(t_v *v);
void			ft_stop_part2(t_v *v);

/* so_long_color */
void			ft_my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	ft_get_color(t_data *data, int x, int y);
int				ft_rgb_to_int(int t, int r, int g, int b);
int				ft_rainbow_color(t_v *v, int x);
void			ft_font_rainbow(t_v *v);

/* so_long_map_init */
void			ft_map_width_height(t_v *v);
int				ft_line_init_size(char *str);
void			ft_fd_error(t_v *v);
int				ft_size_init_map(char *argv, t_v *v);
char			**ft_init_map(char *argv, t_v *v, int j);

/* so_long_attack */
int				ft_west_offensive(int x, int y, t_v *v);
int				ft_north_offensive(int x, int y, t_v *v);
int				ft_east_offensive(int x, int y, t_v *v);
int				ft_south_offensive(int x, int y, t_v *v);
int				ft_invasion_propagation(int x, int y, t_v *v);

/* so_long_path_checker */
int				ft_invasion_checker_condition(t_v *v, int x, int y);
int				ft_invasion_checker(t_v *v);
void			ft_invasion_loop_checker(t_v *v, int x, int y);
int				ft_check_exit(t_v *v);
int				ft_invasion_loop(t_v *v);

/* so_long_map_checker */
int				ft_ctrl_map_size(t_v *v, int i);
int				ft_contour_map_control_len(int j, int k, int len);
int				ft_contour_map_control(t_v *v, int i);
int				ft_elements_map_control(t_v *v);

/* so_long_items_checker */
int				ft_control_item(t_v *v, char c);
int				ft_control_its(t_v *v);

/* so_long_draw */
void			ft_init_draw_sprite(t_v *v, t_data sprite, int x, int y);
void			ft_draw_player(t_v *v, int key);
void			ft_init_draws(t_v *v, int x, int y, char c);
void			ft_draw_map(t_v *v);
void			ft_draw_map_new(t_v *v);

/* so_long_draw_end */
void			ft_init_big_sheep(t_v *v);
void			ft_draw_big_sheep(t_v *v, t_data sprite, int x, int y);
void			ft_init_new_sprites(t_v *v);
void			ft_switch_player_image(t_v *v, int x, int y);
void			ft_switch_end_game(t_v *v, int x, int y);

void			ft_init_new_sprites_part2(t_v *v);

/* so_long_move_checker */
int				ft_check_player_up(t_v *v);
int				ft_check_player_down(t_v *v);
int				ft_check_player_right(t_v *v);
int				ft_check_player_left(t_v *v);

/* so_long_init_data_move */
int				ft_keypress_event(int key, t_v *v);
void			ft_init_sprites_part1(t_v *v);
void			ft_init_sprites_part2(t_v *v);
void			ft_init_sprites_part3(t_v *v);
void			ft_init_sprites_part4(t_v *v);
void			ft_init_sprites_part5(t_v *v);
void			ft_init_data(t_v *v);

void			ft_switch_bad_end_game(t_v *v, t_data sprite);
void			ft_init_draws1(t_v *v, int x, int y, char c);
void			ft_init_draws2(t_v *v, int x, int y, char c);
void			ft_draw_refresh1(t_v *v);
void			ft_draw_refresh2(t_v *v);

void			str_menu_data(t_v *v);
void			ft_anim_end_game(t_v *v, t_data sprite);
void			ft_anim_part1(t_v *v);
int				ft_anim(t_v *v);

void			ft_init_big_cat(t_v *v);
void			ft_switch_bad_end_game(t_v *v, t_data sprite);
int				ft_offensive_ally(int tmpx, int tmpy, t_v *v);
void			ft_init_ennemy(t_v *v);

#endif