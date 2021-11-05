/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:17:38 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/03 17:44:36 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_maperr	is_map_closed(t_maperr e, char **map, int x, int x_max)
{
	int	y;

	y = 0;
	while (x < x_max && e.is_map_open == 0)
	{
		while (map[x][y] != '\0' && e.is_map_open == 0)
		{
			if (x == 0 && map[x][y] != '1')
				e.is_map_open = 1;
			else if (x > 0 && y == 0 && map[x][y] != '1')
				e.is_map_open = 1;
			else if (map[x][y + 1] == '\0' && map[x][y] != '1')
				e.is_map_open = 1;
			else if (x == x_max && map[x][y] != '1')
				e.is_map_open = 1;
			y++;
		}
		y = 0;
		x++;
	}
	return (e);
}

t_maperr	is_map_rectangle(char **map, t_maperr e, int x, int x_max)
{
	int		y;
	int		y_cmp;

	y = 0;
	y_cmp = 1;
	while (map[x][y] != '\0')
		y++;
	if (y == x_max)
		e.map_is_square = 1;
	else if (y <= 1 || x_max <= 1)
		e.map_too_short = 1;
	else
	{
		while (x <= x_max && e.map_is_not_rectangle == 0)
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

static t_maperr	check_map(char **map, t_maperr e, int x_max, int count)
{
	t_player	data;
	int			i;

	init_data(&data);
	while (count < x_max && e.is_valid_char == 0)
	{
		i = 0;
		if (map[count][i] == '\0' && i == 0)
			e.is_valid_char = 1;
		while (map[count][i] != '\0' && e.is_valid_char == 0)
		{
			if (unvalid_char(map[count][i]) == 1)
				e.is_valid_char = 1;
			data = get_data_of_map(map[count][i], data);
			i++;
		}
		count++;
	}
	e = is_data_valid(e, data);
	e = is_map_rectangle(map, e, 0, x_max - 1);
	if (e.map_is_not_rectangle == 0)
		e = is_map_closed(e, map, 0, x_max);
	return (e);
}

int	check_errors_inside_map(char ****map, char *file, t_maperr **e)
{
	int		fd;

	**map = NULL;
	fd = open(file, O_RDONLY);
	**map = init_map(**map, &e, fd, 0);
	close(fd);
	if (map_errors(**e, 1) == 1)
	{
		if (**map != NULL)
			free_map(**map, (*(*e)).x_max);
		return (1);
	}
	fd = open(file, O_RDONLY);
	**map = get_map(**map, fd, &e, 0);
	close (fd);
	**e = check_map(**map, **e, (*(*e)).x_max, 0);
	if (map_errors(**e, 0) == 1)
	{
		free_map(**map, (*(*e)).x_max);
		return (1);
	}
	return (0);
}
