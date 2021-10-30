/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:17:38 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/29 03:15:29 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_maperr	is_map_closed(t_maperr e, char **map, int x, int y)
{
	while (x <= e.x_max && e.is_map_open == 0)
	{
		while (map[x][y] != '\0' && e.is_map_open == 0)
		{
			if (x == 0 && map[x][y] != '1')
				e.is_map_open = 1;
			else if (x > 0 && y == 0 && map[x][y] != '1')
				e.is_map_open = 1;
			else if (map[x][y + 1] == '\0' && map[x][y] != '1')
				e.is_map_open = 1;
			else if (x == e.x_max && map[x][y] != '1')
				e.is_map_open = 1;
			y++;
		}
		y = 0;
		x++;
	}
	return (e);
}

static t_maperr	is_map_rectangle(char **map, t_maperr e, int x, int y)
{
	int		y_cmp;

	e.x_max--;
	y_cmp = 1;
	while (map[x][y] != '\0')
		y++;
	if (y == e.x_max)
		e.map_is_square = 1;
	else if (y <= 4 || e.x_max + 1 <= 4)
		e.map_too_short = 1;
	else
	{
		while (x <= e.x_max && e.map_is_not_rectangle == 0)
		{
			while (map[x][y_cmp] != '\0')
				y_cmp++;
			if (y != y_cmp)
				e.map_is_not_rectangle = 1;
			y_cmp = 0;
			x++;
		}
	}
	return (e);
}

t_maperr	check_map(char **map, t_maperr e)
{
	t_player	data;
	int			count;
	int			i;

	count = 0;
	init_data(&data);
	while (map[count] != NULL && e.is_valid_char == 0)
	{
		i = 0;
		if (map[count][i] == '\0' && i == 0)
			e.is_valid_char = 1;
		while (map[count][i] != '\0' && e.is_valid_char == 0)
		{
			if (unvalid_char(map[count][i]) == 1)
				e.is_valid_char = 1;
			data = get_player_data(map[count][i], data);
			i++;
		}
		count++;
	}
	e = is_data_valid(e, data);
	e = is_map_rectangle(map, e, 0, 0);
	if (e.map_is_not_rectangle == 0)
		e = is_map_closed(e, map, 0, 0);
	return (e);
}

int	check_errors_inside_map_file(char *file, t_maperr e)
{
	char	**map;
	int		fd;

	map = NULL;
	fd = open(file, O_RDONLY);
	map = init_map(map, &e, fd, 0);
	close(fd);
	if (map_errors(e, 1) == 1)
	{
		if (map != NULL)
			free_map(map, e);
		return (1);
	}
	fd = open(file, O_RDONLY);
	map = get_map(map, fd, &e, 0);
	close (fd);
	e = check_map(map, e);
	if (map_errors(e, 0) == 1)
	{
		free_map(map, e);
		return (1);
	}
	free_map(map, e);
	return (0);
}
