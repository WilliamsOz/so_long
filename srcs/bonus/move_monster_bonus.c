/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_monster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:11:36 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/11 15:37:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static t_engine	*right_move(t_engine *engine, t_monster_position *tmp)
{
	if (engine->map[tmp->x][tmp->y + 1] == 'P')
		free_all_engine(engine, 1);
	engine->map[tmp->x][tmp->y] = '0';
	get_floor_sprite(engine, tmp->y * 32, tmp->x * 32, -1);
	engine->map[tmp->x][tmp->y + 1] = 'M';
	get_monster_sprite(engine, (tmp->y + 1) * 32, tmp->x * 32, -1);
	tmp->y++;
	return (engine);
}

static t_engine	*left_move(t_engine *engine, t_monster_position *tmp)
{
	if (engine->map[tmp->x][tmp->y - 1] == 'P')
		free_all_engine(engine, 1);
	engine->map[tmp->x][tmp->y] = '0';
	get_floor_sprite(engine, tmp->y * 32, tmp->x * 32, -1);
	engine->map[tmp->x][tmp->y - 1] = 'M';
	get_monster_sprite(engine, (tmp->y - 1) * 32, tmp->x * 32, -1);
	tmp->y--;
	return (engine);
}

t_engine	*move_monster(t_engine *engine)
{
	t_monster_position	*tmp;

	tmp = engine->monster_position;
	while (tmp != NULL)
	{
		if (tmp->ind == 1)
		{
			if (engine->map[tmp->x][tmp->y + 1] == '0'
				|| engine->map[tmp->x][tmp->y + 1] == 'P')
				right_move(engine, tmp);
			else if (engine->map[tmp->x][tmp->y - 1] == '0')
				tmp->ind++;
		}
		else if (tmp->ind == 2)
		{
			if (engine->map[tmp->x][tmp->y - 1] == '0'
				|| engine->map[tmp->x][tmp->y - 1] == 'P')
				left_move(engine, tmp);
			else if (engine->map[tmp->x][tmp->y + 1] == '0')
				tmp->ind--;
		}
		tmp = tmp->next;
	}
	return (engine);
}
