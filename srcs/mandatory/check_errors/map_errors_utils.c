/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:09:09 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/14 12:21:11 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

t_engine	*init_engine_data(t_engine *engine)
{
	engine->data->player = 0;
	engine->data->collectible = 0;
	engine->data->exit = 0;
	return (engine);
}

int	is_there_map_error(t_engine *engine)
{
	if (engine->error->map_bad_format == 1)
		return (1);
	else if (engine->error->map_not_close == 1)
		return (1);
	else if (engine->error->no_collectible == 1)
		return (1);
	else if (engine->error->no_exit == 1)
		return (1);
	else if (engine->error->no_player == 1)
		return (1);
	else if (engine->error->too_many_player == 1)
		return (1);
	else if (engine->error->unvalid_char == 1)
		return (1);
	return (0);
}

void	print_map_error(t_engine *engine)
{
	if (engine->error->map_bad_format == 1)
		write(1, "Map format is incorect\n", 23);
	else if (engine->error->map_not_close == 1)
		write(1, "Map is not close\n", 17);
	else if (engine->error->no_collectible == 1)
		write(1, "No collectible inside map\n", 26);
	else if (engine->error->no_exit == 1)
		write(1, "No exit inside map\n", 19);
	else if (engine->error->no_player == 1)
		write(1, "No player inside map\n", 21);
	else if (engine->error->too_many_player == 1)
		write(1, "Too many player inside map\n", 27);
	else if (engine->error->unvalid_char == 1)
		write(1, "Unknow character inside map\n", 29);
}
