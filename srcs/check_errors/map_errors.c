/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:15:08 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/06 18:58:30 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static t_engine    is_char_valid(t_engine engine, char c)
{
	if (BONUS == 0 && c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
		engine.error->unvalid_char = 1;
	if (BONUS == 1 && c != '0' && c != '1' && c != 'P' && c != 'E'
		&& c != 'C' && c != 'M')
		engine.error->unvalid_char = 1;
	return (engine);
}

static t_engine	get_map_data(t_engine engine, char c)
{
	if (c == 'P')
		engine.data->player++;
	else if (c == 'E')
		engine.data->exit++;
	else if (c == 'C')
		engine.data->collectible++;
	return (engine);
}

static t_engine	is_data_valid(t_engine engine)
{
	if (engine.data->player == 0)
		engine.error->no_player = 1;
	if (engine.data->player > 1)
		engine.error->too_many_player = 1;
	if (engine.data->collectible == 0)
		engine.error->no_collectible = 1;
	if (engine.data->exit == 0)
		engine.error->no_exit = 1;
	return (engine);
}

static t_engine	is_map_rectangle(t_engine engine, int x)
{
	int	x_lenght;
	int	cmp_lenght;

	x_lenght = ft_strlen(engine.map[0]);
	while (engine.map[x] != NULL)
	{
		cmp_lenght = ft_strlen(engine.map[x]);
		if (x_lenght != cmp_lenght)
			engine.error->map_bad_format = 1;
		x++;
	}
	return (engine);
}

t_engine	check_map_errors_case(t_engine engine, int x, int y)
{
	engine.data->player = 0;
	engine.data->collectible = 0;
	engine.data->exit = 0;
	while (engine.map[x] != NULL)
	{
		while (engine.map[x][y] != '\0')
		{
			if (y == 0 && engine.map[x][y] == '\0')
				engine.error->map_bad_format = 1;
			engine = is_char_valid(engine, engine.map[x][y]);
			engine = get_map_data(engine, engine.map[x][y]);
			y++;
		}
		y = 0;
		x++;
	}
	engine = is_data_valid(engine);
	engine = is_map_rectangle(engine, 1);
	engine = is_map_closed(engine, 0, 0);
	if (is_there_map_error(engine) == 1)
	{
		print_map_error(engine);
		free_map(engine, 0);
		exit (EXIT_FAILURE);
	}
	return (engine);
}
