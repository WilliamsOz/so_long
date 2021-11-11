/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:25:55 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/11 15:45:39 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static t_engine	*collectible_event(t_engine *engine, int x, int y)
{
	engine->collectible--;
	engine->map[x][y] = '0';
	get_floor_sprite(engine, y * 32, x * 32, -1);
	y--;
	engine->map[x][y] = 'P';
	get_char_sprite(engine, y * 32, x * 32, -1);
	engine->player_pos_x = x;
	engine->player_pos_y = y;
	engine->move_count++;
	return (engine);
}

static t_engine	*walk_event(t_engine *engine, int x, int y)
{
	engine->map[x][y] = '0';
	get_floor_sprite(engine, y * 32, x * 32, -1);
	y--;
	engine->map[x][y] = 'P';
	get_char_sprite(engine, y * 32, x * 32, -1);
	engine->player_pos_x = x;
	engine->player_pos_y = y;
	engine->move_count++;
	return (engine);
}

static t_engine	*exit_event(t_engine *engine)
{
	engine->move_count++;
	print_move(engine, engine->move_count);
	free_all_engine(engine, 1);
	return (engine);
}

static t_engine	*dead_event(t_engine *engine)
{
	engine->move_count++;
	print_move(engine, engine->move_count);
	free_all_engine(engine, 1);
	return (engine);
}

t_engine	*move_left(t_engine *engine, int x, int y)
{
	if (engine->map[x][y - 1] == 'C')
		engine = collectible_event(engine, x, y);
	else if (engine->map[x][y - 1] == '0')
		engine = walk_event(engine, x, y);
	else if (engine->collectible == 0 && engine->map[x][y - 1] == 'E')
		engine = exit_event(engine);
	else if (BONUS == 1 && engine->map[x][y - 1] == 'M')
		engine = dead_event(engine);
	return (engine);
}
