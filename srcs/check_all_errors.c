/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:42:10 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/06 13:55:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_error_struct(t_engine *engine)
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

t_engine    check_file_error(t_engine engine, char *file)
{
	engine.error->fd = open(file, O_RDONLY);
	if (engine.error->fd == -1)
		engine.error->no_file = 1;
	else
		close (engine.error->fd);
	engine.error->fd = open(file, __O_NOFOLLOW);
	if (engine.error->fd == -1)
		engine.error->file_bad_format = 1;
	else
		close (engine.error->fd);
	engine.error->fd = open(file, __O_DIRECTORY);
	if (engine.error->fd != -1)
		engine.error->file_bad_format = 1;
	else
		close(engine.error->fd);
	return (engine);
}

void	check_all_errors(t_engine engine, char *file)
{
	init_error_struct(&engine);
	engine = check_file_error(engine);
	if (is_there_an_error_file(engine) == 1)
	{
		printf_file_error(engine);
		exit (EXIT_FAILURE);
	}
	// check_map_error(engine);


}
