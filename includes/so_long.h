/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:04:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/29 03:11:45 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

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
	int		is_empty_line;
	int		is_valid_char;
	int		no_exit;
	int		no_collectibles;
	int		no_player;
	int		too_many_player;
	int		is_map_open;
	int		map_is_square;
	int		map_too_short;
	int		map_is_not_rectangle;
}				t_maperr;

typedef struct s_player
{
	int		player;
	int		exit;
	int		collectibles;
	int		monster; //peut ne pas servir
}				t_player;

void		free_map(char **map, t_maperr e);
int			unvalid_char(char c);
void		init_data(t_player *data);
t_player	get_player_data(char c, t_player data);
t_maperr	is_data_valid(t_maperr e, t_player data);
int			map_errors(t_maperr e, int ind);
char		**get_map(char **map, int fd, t_maperr *e, int count);
char		**init_map(char **map, t_maperr *e, int fd, int count);
int			file_errors(t_maperr e);
int			check_errors_inside_map_file(char *file, t_maperr e);
t_maperr	check_file(char *map, t_maperr e);
t_maperr	check_opening_file(char *file, t_maperr error, int fd);
void		init_maperror(t_maperr *error);
int			check_errors(char **av);

#endif