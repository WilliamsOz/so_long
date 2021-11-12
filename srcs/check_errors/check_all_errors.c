/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:42:10 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/12 16:28:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static t_engine	*init_error_struct(t_engine *engine)
{
	engine->error = NULL;
	engine->error = (t_error *)malloc(sizeof(t_error));
	if (engine->error == NULL)
	{
		write(1, "Error\nMalloc failed\n", 20);
		engine_destroyer(engine, 0);
	}
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
	return (engine);
}

t_engine	*check_all_errors(t_engine *engine, char *file)
{
	engine = (t_engine *)malloc(sizeof(t_engine));
	if (engine == NULL)
	{
		write(1, "Error\nEngine Malloc failed\n", 27);
		exit (EXIT_FAILURE);
	}
	engine = init_error_struct(engine);
	engine = check_file_error(engine, file);
	if (is_there_file_error(engine) == 1)
	{
		write(1, "Error\n", 6);
		print_file_error(engine);
		engine_error_destroyer(engine, 0);
	}
	engine->error->fd = open(file, O_RDONLY);
	engine = init_get_check_map(engine, file);
	if (is_there_map_error(engine) == 1)
	{
		write(1, "Error\n", 6);
		print_map_error(engine);
		engine_full_destroyer(engine, 0);
	}
	return (engine);
}
