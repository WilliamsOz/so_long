/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:33:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/02 11:16:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	**init_map(char **map, t_maperr ***e, int fd, int count)
{
	char	*line;
	int		eof;

	eof = -1;
	while (eof != 0 && (*(*(*e))).empty_line == 0)
	{
		line = NULL;
		eof = get_next_line(fd, &line);
		if (line == NULL)
			(*(*(*e))).empty_line = 1;
		if (eof != 0 || line != NULL)
		{
			free(line);
			count++;
			(*(*(*e))).free_count++;
		}
	}
	if (count == 0)
		(*(*(*e))).empty_map = 1;
	if ((*(*(*e))).empty_map == 1)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (count));
	if (map == NULL)
		(*(*(*e))).malloc_failed = 1;
	return (map);
}

char	**get_map(char **map, int fd, t_maperr ***e, int count)
{
	char	*line;
	int		eof;

	line = NULL;
	eof = 1;
	while (eof > 0 && (*(*(*e))).malloc_failed == 0)
	{
		line = NULL;
		eof = get_next_line(fd, &line);
		if (eof == -1)
			(*(*(*e))).malloc_failed = 1;
		else if (line != NULL)
		{
			map[count] = line;
			if (map[count] == NULL)
				(*(*(*e))).malloc_failed = 1;
			count++;
			(*(*(*e))).x_max++;
		}
	}
	return (map);
}
