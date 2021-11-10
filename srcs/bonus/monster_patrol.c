/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_patrol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:09:22 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/10 16:19:33 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static t_engine    *move_enemy_to_left(t_engine *engine, int x, int y)
{
	while (engine->map[x] != NULL)
	{
		while (engine->map[x][y] != '\0')
		{
			if (engine->map[x][y] == 'M' && engine->map[x][y - 1] == 'P')
				free_all_engine(engine, 1);
			if (engine->map[x][y] == 'M' && engine->map[x][y - 1] == '0')
			{
				engine->map[x][y] = '0';
				get_floor_sprite(engine, y * 32, x * 32, -1);
				engine->map[x][y - 1] = 'M';
				get_monster_sprite(engine, (y - 1) * 32, x * 32, -1);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (engine);
}

static t_engine    *move_enemy_to_right(t_engine *engine, int x, int y)
{
	while (engine->map[x] != NULL)
	{
		while (engine->map[x][y] != '\0')
		{
			if (engine->map[x][y] == 'M' && engine->map[x][y + 1] == 'P')
				free_all_engine(engine, 1);
			if (engine->map[x][y] == 'M' && engine->map[x][y + 1] == '0')
			{
				engine->map[x][y] = '0';
				get_floor_sprite(engine, y * 32, x * 32, -1);
				engine->map[x][y + 1] = 'M';
				get_monster_sprite(engine, (y + 1) * 32, x * 32, -1);
				y += 2;
			}
			else
				y++;
		}
		y = 0;
		x++;
	}
	return (engine);
}

static int	all_enemy_stuck_on_right(t_engine *engine, int x, int y)
{
	while(engine->map[x] != NULL)
	{
		while (engine->map[x][y] != '\0')
		{
			if (engine->map[x][y] == 'M')
			{
				if (engine->map[x][y + 1] == '0')
					return (0);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

static int	all_enemy_stuck_on_left(t_engine *engine, int x, int y)
{
	while(engine->map[x] != NULL)
	{
		while (engine->map[x][y] != '\0')
		{
			if (engine->map[x][y] == 'M')
			{
				if (engine->map[x][y - 1] == '0')
					return (0);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

t_engine    *monster_patrol(t_engine *engine)
{
	static int  ind = 1;
	static int  time = 0;

	time++;
	if (time % 15 != 0)
		return (engine);
	if (ind == 1 && all_enemy_stuck_on_right(engine, 0, 0) == 1)
		ind = 0;
	else if (ind == 0 && all_enemy_stuck_on_left(engine, 0, 0) == 1)
		ind = 1;
	if (ind == 1)
		engine = move_enemy_to_right(engine, 0, 0);
	else if (ind == 0)
		engine = move_enemy_to_left(engine, 0, 0);
	if (time == 150)
		time = 0;
	return (engine);
}