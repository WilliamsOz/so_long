/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:15:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/29 03:16:03 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map(char **map, t_maperr e)
{
	int		count;

	count = 0;
	while (e.free_count > 0)
	{
		if (map[count] != NULL)
			free(map[count]);
		count++;
		e.free_count--;
	}
	free(map);
	map = NULL;
}

void	init_maperror(t_maperr *error)
{
	(*error).free_count = 0;
	(*error).x_max = 0;
	(*error).is_symlink = 0;
	(*error).is_directory = 0;
	(*error).file_exist = 0;
	(*error).empty_name_map = 0;
	(*error).not_ber_extension = 0;
	(*error).empty_map = 0;
	(*error).is_empty_line = 0;
	(*error).malloc_failed = 0;
	(*error).is_valid_char = 0;
	(*error).no_exit = 0;
	(*error).no_collectibles = 0;
	(*error).no_player = 0;
	(*error).too_many_player = 0;
	(*error).is_map_open = 0;
	(*error).map_is_square = 0;
	(*error).map_too_short = 0;
	(*error).map_is_not_rectangle = 0;
}
