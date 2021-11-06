/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:26:23 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/06 17:29:23 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	printf_file_error(t_engine engine)
{
	if (engine.error->no_file == 1)
		write(1, "There is no file\n", 17);
	else if (engine.error->file_bad_format == 1)
		write(1, "Format of the file is not corret\n", 33);
}

int		is_there_file_error(t_engine engine)
{
	if (engine.error->no_file == 1)
		return (1);
	else if (engine.error->file_bad_format == 1)
		return (1);
	return (0);
}


t_engine	check_file_error(t_engine engine, char *file)
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
