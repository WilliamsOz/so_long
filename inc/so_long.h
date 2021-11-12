/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:04:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/12 17:10:51 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "./so_long_bonus.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# define _GNU_SOURCE
# define UP_KEY 119
# define DOWN_KEY 115
# define LEFT_KEY 97
# define RIGHT_KEY 100
# define ESC_KEY 65307
# define BONUS 1

void		print_move(t_engine *engine, int count);
int			mouse_and_esc_exit(t_engine *engine);
t_engine	*move_right(t_engine *engine, int x, int y);
t_engine	*move_left(t_engine *engine, int x, int y);
t_engine	*move_down(t_engine *engine, int x, int y);
t_engine	*move_up(t_engine *engine, int x, int y);
t_engine	*move_player(t_engine *engine);
int			key_hook(int keycode, t_engine *engine);
t_engine	*get_all_collectible(t_engine *engine);
t_engine	*get_player_position(t_engine *engine);
void		first_init_image(t_engine *engine, int i, int j, int x_pos);
void		get_monster_sprite(t_engine *engine, int i, int j, int y);
void		my_mlx_pixel_put(t_img *img, int x, int y, char *pixel);
void		get_floor_sprite(t_engine *engine, int i, int j, int y);
void		get_char_sprite(t_engine *engine, int i, int j, int y);
void		get_exit_sprite(t_engine *engine, int i, int j, int y);
void		get_collectible_sprite(t_engine *engine, int i, int j, int y);
void		get_wall_sprite(t_engine *engine, int i, int j, int y);
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