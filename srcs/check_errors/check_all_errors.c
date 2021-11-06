/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:42:10 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/06 19:00:16 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	init_error_struct(t_engine *engine)
{
	engine->error->no_file = 0;
	engine->error->file_bad_format = 0;
	engine->error->malloc_fail = 0;
	engine->error->map_bad_format = 0;
	engine->error->map_not_close = 0;
	engine->error->no_collectible = 0;
	engine->error->no_exit = 0;
	engine->error->no_player = 0;
	engine->error->too_many_player = 0;
	engine->error->unvalid_char = 0;
}

int	is_there_map_error(t_engine engine)
{
	if (engine.error->map_bad_format == 1)
		return (1);
	else if (engine.error->map_not_close == 1)
		return (1);
	else if (engine.error->no_collectible == 1)
		return (1);
	else if (engine.error->no_exit == 1)
		return (1);
	else if (engine.error->no_player == 1)
		return (1);
	else if (engine.error->too_many_player == 1)
		return (1);
	else if (engine.error->unvalid_char == 1)
		return (1);
	return (0);
}

void		print_map_error(t_engine engine)
{
	if (engine.error->map_bad_format == 1)
		write(1, "Map format is incorect\n", 23);
	else if (engine.error->map_not_close == 1)
		write(1, "Map is not close\n", 20);
	else if (engine.error->no_collectible == 1)
		write(1, "No collectible inside map\n", 26);
	else if (engine.error->no_exit == 1)
		write(1, "No exit inside map\n", 19);
	else if (engine.error->no_player == 1)
		write(1, "No player inside map\n", 21);
	else if (engine.error->too_many_player == 1)
		write(1, "Too many player inside map\n", 27);
	else if (engine.error->unvalid_char == 1)
		write(1, "Unknow character inside map\n", 29);
}

t_engine	check_all_errors(t_engine engine, char *file)
{
	init_error_struct(&engine); // marche pas
	engine = check_file_error(engine, file);
	if (is_there_file_error(engine) == 1)
	{
		write(1, "Error\n", 6);
		print_file_error(engine);
		exit (EXIT_FAILURE);
	}
	engine.error->fd = open(file, O_RDONLY);
	engine = check_map_errors_case(engine, 0, 0);
	close(engine.error->fd);
	if (is_there_map_error(engine) == 1)
	{
		write(1, "Error\n", 6);
		print_map_error(engine);
		free_map(engine, 0);
		exit (EXIT_FAILURE);
	}
	return (engine);
}
