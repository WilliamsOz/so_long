/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:41:29 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/07 19:02:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static t_engine *check_diagonals_ends(t_engine *engine, int x, int y)
{
	if (engine->map[0][0] != '1')
		engine->error->map_not_close = 1;
	y = ft_strlen(engine->map[0]) - 1;
	if (engine->map[x][y] != '1')
		engine->error->map_not_close = 1;
	while (engine->map[x + 1] != NULL)
		x++;
	y = 0;
	if (engine->map[x][y] != '1')
		engine->error->map_not_close = 1;
	y = ft_strlen(engine->map[0]) - 1;
	if (engine->map[x][y] != '1')
		engine->error->map_not_close = 1;
	return (engine);
}

static t_engine    *cross_x_map(t_engine *engine, int x, int y)
{
	if (engine->map[0][y] != '1')
		engine->error->map_not_close = 1;
	while (engine->map[x + 1] != NULL)
		x++;
	if (engine->map[x][y] != '1')
		engine->error->map_not_close = 1;
	return (engine);
}

static t_engine		*cross_y_map(t_engine *engine, int x, int y)
{
	if (engine->map[x][0] != '1')
		engine->error->map_not_close = 1;
	while (engine->map[x][y + 1] != '\0')
		y++;
	if (engine->map[x][y] != '1')
		engine->error->map_not_close = 1;
	return (engine);
}

t_engine	*is_map_closed(t_engine *engine, int x, int y)
{
	int		x_max;
	int		y_max;

	y_max = ft_strlen(engine->map[0]);
	x_max = 0;
	while (engine->map[x_max + 1] != NULL)
		x_max++;
	engine = check_diagonals_ends(engine, 0, 0);
	while (engine->map[x] != NULL)
	{
		while (engine->map[x][y] != '\0')
		{
			if (x != 0 && y != 0 && x != x_max && y != y_max)
			{
				engine = cross_x_map(engine, x, y);
				engine = cross_y_map(engine, x, y);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (engine);
}
