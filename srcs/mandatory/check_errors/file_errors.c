/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:26:23 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/14 12:22:03 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	print_file_error(t_engine *engine)
{
	if (engine->error->no_file == 1)
		write(1, "There is no file\n", 17);
	else if (engine->error->file_bad_format == 1)
		write(1, "Format of the file is not corret\n", 33);
}

int	is_there_file_error(t_engine *engine)
{
	if (engine->error->no_file == 1)
		return (1);
	else if (engine->error->file_bad_format == 1)
		return (1);
	return (0);
}

static t_engine	*check_file_name(t_engine *engine, char *file, int i)
{
	while (file[i] != '\0')
		i++;
	if ((i == 4 && file[i - 1] == 'r' && file[i - 2] == 'e'
			&& file[i - 3] == 'b' && file[i - 4] == '.')
		|| (file[i - 1] == 'r' && file[i - 2] == 'e'
			&& file[i - 3] == 'b' && file[i - 4] == '.' && file[i - 5] == '/'))
		engine->error->file_bad_format = 1;
	else if (ft_strlen(file) <= 4)
		engine->error->file_bad_format = 1;
	else if (file[i - 1] != 'r' || file[i - 2] != 'e'
		|| file[i - 3] != 'b' || file[i - 4] != '.')
		engine->error->file_bad_format = 1;
	return (engine);
}

t_engine	*check_file_error(t_engine *engine, char *file)
{
	engine->error->fd = open(file, O_RDONLY);
	if (engine->error->fd == -1)
		engine->error->no_file = 1;
	else
		close (engine->error->fd);
	engine->error->fd = open(file, __O_NOFOLLOW);
	if (engine->error->fd == -1)
	{
		engine->error->file_bad_format = 1;
		close (engine->error->fd);
	}
	engine->error->fd = open(file, __O_DIRECTORY);
	if (engine->error->fd != -1)
	{
		engine->error->file_bad_format = 1;
		close(engine->error->fd);
	}
	engine = check_file_name(engine, file, 0);
	return (engine);
}
