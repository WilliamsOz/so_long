/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:22:52 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/14 12:54:17 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

t_engine	*get_all_collectible(t_engine *engine)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	engine->collectible = 0;
	while (engine->map[x] != NULL && engine->map[x][y] != 'P')
	{
		while (engine->map[x][y] != '\0')
		{
			if (engine->map[x][y] == 'C')
				engine->collectible++;
			y++;
		}
		y = 0;
		x++;
	}
	return (engine);
}

t_engine	*get_player_position(t_engine *engine)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (engine->map[x] != NULL && engine->map[x][y] != 'P')
	{
		while (engine->map[x][y] != '\0')
		{
			if (engine->map[x][y] == 'P')
			{
				engine->player_pos_x = x;
				engine->player_pos_y = y;
				return (engine);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (engine);
}

void	free_map(t_engine *engine, int x)
{
	while (engine->map[x] != NULL)
	{
		free(engine->map[x]);
		engine->map[x] = NULL;
		x++;
	}
	free(engine->map[x]);
	engine->map[x] = NULL;
	free(engine->map);
	engine->map = NULL;
}

int	mouse_and_esc_exit(t_engine *engine)
{
	free_all_engine(engine, 1);
	return (1);
}
