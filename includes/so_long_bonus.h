/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:04:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 19:28:20 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#ifdef __linux__

# define UP_KEY 119
# define DOWN_KEY 115
# define LEFT_KEY 97
# define RIGHT_KEY 100
# define ESC_KEY 65307

#else

# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define ESC_KEY 53

#endif

# include "./mlx/mac_OS/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# define _GNU_SOURCE

typedef struct s_mlx
{
	int				enemy_count;
	int				monster_move_count;
	int				win;
	int				can_be_win;
	char			**map;
	int				move_count;
	int				x_max;
	int				y_max;
	char			*buffer;
	int				win_size_x;
	int				win_size_y;
	void			*mlx_id;
	void			*win_id;
	void			*img_id;
	char			*img_addr;
	int				*img;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	void			*sprite_id;
	void			*sprite_img;
	char			*sprite_addr;
	int				width;
	int				height;
	int				lin;
	int				col;
	int				x_img;
	int				y_img;
}				t_mlx;

typedef struct s_maperr
{
	int		free_count;
	int		x_max;
	int		is_symlink;
	int		is_directory;
	int		file_exist;
	int		empty_name_map;
	int		not_ber_extension;
	int		empty_map;
	int		malloc_failed;
	int		empty_line;
	int		is_valid_char;
	int		no_exit;
	int		no_collectibles;
	int		no_player;
	int		too_many_player;
	int		is_map_open;
	int		map_is_square;
	int		map_too_short;
	int		map_is_not_rectangle;
	int		mlx_init_error;
	int		mlx_wind_error;
	int		mlx_img_error;
}				t_maperr;

typedef struct s_player
{
	int		player;
	int		exit;
	int		collectibles;
}				t_player;

void		enemy_right_move(t_mlx **mlx, int x, int *y);
void		enemy_left_move(t_mlx **mlx, int x, int *y);
int			move_enemy(t_mlx *mlx, int x, int y);
void		free_mlx_and_map(t_mlx mlx);
void		get_monster_sprite(t_mlx mlx, int x, int y);
t_mlx		apply_modif_on_mlx_for_up(t_mlx mlx, int x, int y);
t_mlx		apply_modif_on_mlx_for_down(t_mlx mlx, int x, int y);
t_mlx		apply_modif_on_mlx_for_lef(t_mlx mlx, int x, int y);
t_mlx		apply_modif_on_mlx_for_right(t_mlx mlx, int x, int y);
void		erase_actual_counter_and_print_count(int move, int mlx_move);
void		end_game(t_mlx mlx);
t_mlx		can_be_win(t_mlx mlx, int x, int y);
int			key_hook_bonus(int keycode, t_mlx *mlx);
int			key_hook(int keycode, t_mlx *mlx);
void		get_wall_sprite_bonus(t_mlx mlx, int x, int y);
void		get_floor_sprite(t_mlx mlx, int x, int y);
void		get_char_sprite(t_mlx mlx, int x, int y);
void		my_pixel_put(t_mlx *mlx, int x, int y, char *color);
void		get_map_sprite_bonus(t_mlx mlx, int x, int y, char **map);
void		get_map_sprite(t_mlx mlx, int x, int y, char **map);
void		init_mlx(t_mlx *mlx, t_maperr e, char **map);
void		free_map(char **map, int x_max);
int			unvalid_char(char c);
void		init_data(t_player *data);
t_player	get_data_of_map(char c, t_player data);
t_maperr	is_data_valid(t_maperr e, t_player data);
t_maperr	is_map_closed(t_maperr e, char **map, int x, int x_max);
t_maperr	is_map_rectangle(char **map, t_maperr e, int x, int x_max);
int			map_errors(t_maperr e, int ind);
char		**get_map(char **map, int fd, t_maperr ***e, int count);
char		**init_map(char **map, t_maperr ***e, int fd, int count);
int			file_errors(t_maperr e);
int			check_errors_inside_map(char ****map, char *file, t_maperr **e);
t_maperr	check_file(char *map, t_maperr e);
t_maperr	check_opening_file(char *file, t_maperr error, int fd);
void		init_maperror(t_maperr **error);
int			check_errors_bonus(char ***map, char **av, t_maperr *error);
int			check_errors(char ***map, char **av, t_maperr *error);

#endif