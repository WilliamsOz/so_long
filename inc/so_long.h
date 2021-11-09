/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:04:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/09 19:43:54 by wiozsert         ###   ########.fr       */
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
# include "../mlx/linux_OS/mlx.h"

#else

# define UP_KEY 13
# define DOWN_KEY 1
# define LEFT_KEY 0
# define RIGHT_KEY 2
# define ESC_KEY 53
# include "./mlx/mac_OS/mlx.h"

#endif

// # include "./mlx/mac_OS/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# define _GNU_SOURCE
# define BONUS 1

typedef struct s_map_data
{
	int			player;
	int			collectible;
	int			exit;
}				t_map_data;

typedef struct s_error
{
	int			no_file;
	int			fd;
	int			file_bad_format;
	int			malloc_fail;
	int			map_not_close;
	int			map_bad_format;
	int			unvalid_char;
	int			no_exit;
	int			no_collectible;
	int			no_player;
	int			too_many_player;
}				t_error;

typedef struct s_img
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bit_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct  s_engine
{
	int			move_count;
	char		keycode;
	t_img		*img;
	t_img		*sprite;
	t_error		*error;
	t_map_data	*data;
	char		**map;
}				t_engine;

void		get_monster_sprite(t_engine *engine, int i, int j);
void		my_mlx_pixel_put(t_img *img, int x, int y, char *pixel);
void		get_floor_sprite(t_engine *engine, int i, int j);
void		get_char_sprite(t_engine *engine, int i, int j);
void		get_exit_sprite(t_engine *engine, int i, int j);
void		get_collectible_sprite(t_engine *engine, int i, int j);
void		get_wall_sprite(t_engine *engine, int i, int j);
void		free_all_engine(t_engine *engine, int ind);
void		engine_destroyer(t_engine *engine, int ind);
void		engine_error_destroyer(t_engine *engine, int ind);
void		engine_map_destroyer(t_engine *engine, int ind);
void		engine_full_destroyer(t_engine *engine, int ind);
void		engine_mall_failed(void);
void		free_map(t_engine *engine, int x);
int			is_there_map_error(t_engine *engine);
void		print_map_error(t_engine *engine);
t_engine	*is_map_closed(t_engine *engine, int x, int y);
t_engine	*init_engine_data(t_engine *engine);
t_engine	*init_get_check_map(t_engine *engine, char *file);
t_engine	*check_map_errors_case(t_engine *engine, int x, int y);
t_engine	*check_map_error(t_engine engine, char *file);
void		print_file_error(t_engine *engine);
int			is_there_file_error(t_engine *engine);
t_engine	*check_file_error(t_engine *engine, char *file);
t_engine	*check_all_errors(t_engine *engine, char *file);


#endif