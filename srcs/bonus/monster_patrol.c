/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_patrol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:09:22 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/11 01:52:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long_bonus.h"

// static t_engine    *move_enemy_to_left(t_engine *engine, int x, int y)
// {
// 	while (engine->map[x] != NULL)
// 	{
// 		while (engine->map[x][y] != '\0')
// 		{
// 			if (engine->map[x][y] == 'M' && engine->map[x][y - 1] == 'P')
// 				free_all_engine(engine, 1);
// 			if (engine->map[x][y] == 'M' && engine->map[x][y - 1] == '0')
// 			{
// 				engine->map[x][y] = '0';
// 				get_floor_sprite(engine, y * 32, x * 32, -1);
// 				engine->map[x][y - 1] = 'M';
// 				get_monster_sprite(engine, (y - 1) * 32, x * 32, -1);
// 			}
// 			y++;
// 		}
// 		y = 0;
// 		x++;
// 	}
// 	return (engine);
// }

// static t_engine    *move_enemy_to_right(t_engine *engine, int x, int y)
// {
// 	while (engine->map[x] != NULL)
// 	{
// 		while (engine->map[x][y] != '\0')
// 		{
// 			if (engine->map[x][y] == 'M' && engine->map[x][y + 1] == 'P')
// 				free_all_engine(engine, 1);
// 			if (engine->map[x][y] == 'M' && engine->map[x][y + 1] == '0')
// 			{
// 				engine->map[x][y] = '0';
// 				get_floor_sprite(engine, y * 32, x * 32, -1);
// 				engine->map[x][y + 1] = 'M';
// 				get_monster_sprite(engine, (y + 1) * 32, x * 32, -1);
// 				y += 2;
// 			}
// 			else
// 				y++;
// 		}
// 		y = 0;
// 		x++;
// 	}
// 	return (engine);
// }

// static int	all_enemy_stuck_on_right(t_engine *engine, int x, int y)
// {
// 	while(engine->map[x] != NULL)
// 	{
// 		while (engine->map[x][y] != '\0')
// 		{
// 			if (engine->map[x][y] == 'M')
// 			{
// 				if (engine->map[x][y + 1] == '0')
// 					return (0);
// 			}
// 			y++;
// 		}
// 		y = 0;
// 		x++;
// 	}
// 	return (1);
// }

// static int	all_enemy_stuck_on_left(t_engine *engine, int x, int y)
// {
// 	while(engine->map[x] != NULL)
// 	{
// 		while (engine->map[x][y] != '\0')
// 		{
// 			if (engine->map[x][y] == 'M')
// 			{
// 				if (engine->map[x][y - 1] == '0')
// 					return (0);
// 			}
// 			y++;
// 		}
// 		y = 0;
// 		x++;
// 	}
// 	return (1);
// }

static t_engine	*get_first_monster(t_engine *engine, int *ptr_count, int x, int y)
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

static t_engine	*get_next_monster(t_engine *engine, int x, int y)
{
	t_monster_position	*tmp;
	t_monster_position	*new;

	new = NULL;
	new = (t_monster_position*)malloc(sizeof(t_monster_position));
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

t_engine	*get_monster_position(t_engine *engine, int x, int y, int count)
{
	engine->monster_position = NULL;
	engine->monster_position = (t_monster_position *)malloc(sizeof(t_monster_position));
	if (engine->monster_position == NULL)
		free_all_engine(engine, 0);
	while (engine->map[x] != NULL)
	{
		while (engine->map[x][y] != '\0')
		{
			if (engine->map[x][y] == 'M' && count == 0)
				engine = get_first_monster(engine, &count, x, y);
			else if (engine->map[x][y] == 'M')
				engine = get_next_monster(engine, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	return (engine);
}

static t_engine	*right_move(t_engine *engine, t_monster_position *tmp)
{
	engine->map[tmp->x][tmp->y] = '0';
	get_floor_sprite(engine, tmp->y * 32, tmp->x * 32, -1);
	engine->map[tmp->x][tmp->y + 1] = 'M';				
	get_monster_sprite(engine, (tmp->y + 1) * 32, tmp->x * 32, -1);
	tmp->y++;
	return (engine);
}

static t_engine	*left_move(t_engine *engine, t_monster_position *tmp)
{
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
			if (engine->map[tmp->x][tmp->y + 1] == '0')
				right_move(engine, tmp);
			else if (engine->map[tmp->x][tmp->y - 1] == '0')
				tmp->ind++;
		}
		else if (tmp->ind == 2)
		{
			if (engine->map[tmp->x][tmp->y - 1] == '0')
				left_move(engine, tmp);
			else if (engine->map[tmp->x][tmp->y + 1] == '0')
				tmp->ind--;
		}
		tmp = tmp->next;
	}
	return (engine);
}

t_engine    *monster_patrol(t_engine *engine)
{
	// static int  ind = 1;
	static int  time = 0;

	time++;
	if (time % 10 != 0)
		return (engine);
	engine = move_monster(engine);
	// if (ind == 1 && all_enemy_stuck_on_right(engine, 0, 0) == 1)
		// ind = 0;
	// else if (ind == 0 && all_enemy_stuck_on_left(engine, 0, 0) == 1)
		// ind = 1;
	// if (ind == 1)
		// engine = move_enemy_to_right(engine, 0, 0);
	// else if (ind == 0)
		// engine = move_enemy_to_left(engine, 0, 0);
	if (time == 150)
		time = 0;
	return (engine);
}