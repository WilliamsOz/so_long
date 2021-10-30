/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:33:35 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/29 03:16:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char    *ft_strcpy(char *src, char *dest, int len)
{
	int	i;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	dest[len] = '\0';
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	free(src);
	return (dest);
}

char	**init_map(char **map, t_maperr *e, int fd, int count)
{
	char	*line;
	int		eof;

	eof = -1;
	while (eof != 0)
	{
		line = NULL;
		eof = get_next_line(fd, &line);
		if (eof != 0 || line != NULL)
		{
			free(line);
			count++;
		}
	}
	if (count == 0)
		(*e).empty_map = 1;
	if ((*e).empty_map == 1)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (count));
	if (map == NULL)
		(*e).malloc_failed = 1;
	map[count] = NULL;
	return (map);
}

char	**get_map(char **map, int fd, t_maperr *e, int count)
{
	char	*line;
	int		eof;

	line = NULL;
	eof = 1;
	while (eof > 0 && (*e).malloc_failed == 0)
	{
		line = NULL;
		eof = get_next_line(fd, &line);
		if (eof == -1)
			(*e).malloc_failed = 1;
		else if (line == NULL && eof > 0)
			(*e).is_empty_line = 1;
		else if (line != NULL)
		{
			map[count] = ft_strcpy(line, map[count], 0);
			if (map[count] == NULL)
				(*e).malloc_failed = 1;
			count++;
			(*e).free_count++;
			(*e).x_max++;
		}
		map[count] = NULL;
	}
	return (map);
}
