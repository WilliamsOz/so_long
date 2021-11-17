/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position_monster_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:07:03 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/17 12:40:57 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static t_engine	*get_next_monster(t_engine *engine, int x, int y)
{
	t_monster_position	*tmp;
	t_monster_position	*new;

	new = NULL;
	new = (t_monster_position *)malloc(sizeof(t_monster_position));
	if (new == NULL)
	{
		free(engine->monster_position);
		engine->monster_position = NULL;
		free_all_engine(engine, 0);
	}
	if (engine->map[x][y + 1] == '0')
		new->ind = 1;
	else if (engine->map[x][y - 1] == '0')
		new->ind = 2;
	new->next = NULL;
	new->x = x;
	new->y = y;
	tmp = engine->monster_position;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (engine);
}

static t_engine	*get_first_moob(t_engine *engine, int *ptr_count, int x, int y)
{
	if (engine->map[x][y + 1] == '0')
		engine->monster_position->ind = 1;
	else if (engine->map[x][y - 1] == '0')
		engine->monster_position->ind = 2;
	engine->monster_position->next = NULL;
	engine->monster_position->x = x;
	engine->monster_position->y = y;
	*ptr_count += 1;
	return (engine);
}

t_engine	*get_monster_pos(t_engine *engine, int x, int y, int count)
{
	engine->monster_position = NULL;
	engine->monster_position = (t_monster_position *)malloc
		(sizeof(t_monster_position));
	if (engine->monster_position == NULL)
		free_all_engine(engine, 0);
	while (engine->map[x] != NULL)
	{
		while (engine->map[x][y] != '\0')
		{
			if (engine->map[x][y] == 'M' && count == 0)
				engine = get_first_moob(engine, &count, x, y);
			else if (engine->map[x][y] == 'M')
				engine = get_next_monster(engine, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	return (engine);
}
