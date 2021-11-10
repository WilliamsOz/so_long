/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:09:28 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/10 16:11:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static t_engine    *collectible_event(t_engine *engine, int x, int y)
{
    engine->collectible--;
	engine->map[x][y] = '0';
	get_floor_sprite(engine, y * 32, x * 32, -1);
	x--;
	engine->map[x][y] = 'P';
	get_char_sprite(engine, y * 32, x * 32, -1);
	engine->player_pos_x = x;
	engine->player_pos_y = y;
	engine->move_count++;
	return (engine);
}

static t_engine    *walk_event(t_engine *engine, int x, int y)
{
	engine->map[x][y] = '0';
	get_floor_sprite(engine, y * 32, x * 32, -1);
	x--;
	engine->map[x][y] = 'P';
	get_char_sprite(engine, y * 32, x * 32, -1);
	engine->player_pos_x = x;
	engine->player_pos_y = y;
	engine->move_count++;
	return (engine);
}

static void		exit_event(t_engine *engine)
{
	engine->move_count++;
	print_move(engine, engine->move_count);
	if (BONUS == 1)
		print_counter_bonus(engine);
	free_all_engine(engine, 1);
}

static void		dead_event(t_engine *engine)
{
	engine->move_count++;
	print_move(engine, engine->move_count);
	if (BONUS == 1)
		print_counter_bonus(engine);
	free_all_engine(engine, 1);
}

t_engine	*move_up(t_engine *engine, int x, int y)
{
	if (engine->map[x - 1][y] == 'C')
        engine = collectible_event(engine, x, y);
	else if (engine->map[x - 1][y] == '0')
		engine = walk_event(engine, x, y);
	else if (engine->collectible == 0 && engine->map[x - 1][y] == 'E')
		exit_event(engine);
	else if (BONUS == 1 && engine->map[x - 1][y] == 'M')
		dead_event(engine);
	return (engine);
}