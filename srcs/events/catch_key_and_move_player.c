/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key_and_move_player.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:06:27 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/10 15:51:54 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	key_hook(int keycode, t_engine *engine)
{
	if (keycode == UP_KEY)
		engine->keycode = 'w';
	else if (keycode == DOWN_KEY)
		engine->keycode = 's';
	else if (keycode == LEFT_KEY)
		engine->keycode = 'a';
	else if (keycode == RIGHT_KEY)
		engine->keycode = 'd';
	else if (keycode == ESC_KEY)
		engine->keycode = 'q';
	else
	{
		engine->keycode = '0';
		return (1);
	}
	return (0);
}

t_engine	*move_player(t_engine *engine)
{
	if (engine->keycode == 'w')
		engine = move_up(engine, engine->player_pos_x, engine->player_pos_y);
	else if (engine->keycode == 's')
		engine = move_down(engine, engine->player_pos_x, engine->player_pos_y);
	else if (engine->keycode == 'a')
		move_left(engine, engine->player_pos_x, engine->player_pos_y);
	else if (engine->keycode == 'd')
		move_right(engine, engine->player_pos_x, engine->player_pos_y);
	else if (engine->keycode == 'q')
		mouse_and_esc_exit(engine);
	engine->keycode = '0';
	return (engine);
}
