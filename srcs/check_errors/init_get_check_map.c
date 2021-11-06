/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_get_check_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:43:10 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/06 17:29:26 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static t_engine	init_map(t_engine engine, char *file, int eof, int count)
{
	char	*line;

	while (eof != 0)
	{
		line = NULL;
		eof = get_next_line(engine.error->fd, &line);
		if (line == NULL)
			engine.error->map_bad_format = 1;
		if (eof != 0 || line != NULL)
		{
			free(line);
			count++;
		}
	}
	if (count == 0)
	{
		write(1, "Error\nEmpty map\n", 16);
		exit (EXIT_FAILURE);
	}
	engine.map = (char **)malloc(sizeof(char *) * (count + 1));
	if (engine.map == NULL)
		engine.error->malloc_fail = 1;
	else
		engine.map[count] = NULL;
	return (engine);
}

static void		engine_map_malloc_failed(t_engine engine, int count)
{
	int		free_count;

	free_count = 0;
	while (free_count < count && engine.map[free_count] != NULL)
	{
		free(engine.map[free_count]);
		engine.map[free_count] = NULL;
		free_count++;
	}
	free(engine.map);
	engine.map = NULL;
	close(engine.error->fd);
}

static t_engine	get_map(t_engine engine, char *file, int eof, int count)
{
	char	*line;

	while (eof != 0 && engine.error->malloc_fail == 0)
	{
		line = NULL;
		eof = get_next_line(engine.error->fd, &line);
		if (eof == -1)
			engine.error->malloc_fail = 1;
		else if (line != NULL)
		{
			engine.map[count] = line;
			if (engine.map[count] == NULL)
				engine.error->malloc_fail = 1;
			else
				count++;
		}
	}
	if (engine.error->malloc_fail == 1)
		engine_map_malloc_failed(engine, count);
	return (engine);
}

t_engine	init_get_check_map(t_engine engine, char *file)
{
	engine.map = NULL;
	engine = init_map(engine, file, -1, 0);
	if (engine.error->malloc_fail == 1)
	{
		write(1, "Error\nMalloc Failed\n", 21);
		close(engine.error->fd);
		exit (EXIT_FAILURE);
	}
	engine = get_map(engine, file, -1, 0);
	engine = check_map_errors_case(engine, 0, 0);
	return (engine);
}
