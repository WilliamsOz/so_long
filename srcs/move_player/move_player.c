/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:28:33 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 19:28:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_up(t_mlx **mlx, int x, int y)
{
	while (x < (*(*mlx)).x_max && (*(*mlx)).map[x][y] != 'P')
	{
		while ((*(*mlx)).map[x][y] != '\0' && (*(*mlx)).map[x][y] != 'P')
			y++;
		if ((*(*mlx)).map[x][y] != 'P')
		{
			y = 0;
			x++;
		}
	}
	if ((x > 1 && (*(*mlx)).map[x - 1][y] != '1'
		&& (*(*mlx)).map[x - 1][y] != 'E')
		|| ((*(*mlx)).map[x - 1][y] == 'E' && (*(*mlx)).can_be_win == 1))
	{
		if ((*(*mlx)).map[x - 1][y] == 'E' && (*(*mlx)).can_be_win == 1)
			end_game(**mlx);
		(*(*mlx)).map[x][y] = '0';
		(*(*mlx)).map[x - 1][y] = 'P';
		(*(*mlx)).x_img = x;
		(*(*mlx)).y_img = y;
		get_floor_sprite(**mlx, x * 32, y * 32);
		(*(*mlx)).x_img = x - 1;
		get_char_sprite(**mlx, (x - 1) * 32, y * 32);
		(*(*mlx)).move_count++;
	}
}

static void	move_down(t_mlx **mlx, int x, int y)
{
	while (x < (*(*mlx)).x_max && (*(*mlx)).map[x][y] != 'P')
	{
		while ((*(*mlx)).map[x][y] != '\0' && (*(*mlx)).map[x][y] != 'P')
			y++;
		if ((*(*mlx)).map[x][y] != 'P')
		{
			y = 0;
			x++;
		}
	}
	if ((x < (*(*mlx)).x_max - 2 && (*(*mlx)).map[x + 1][y] != '1'
		&& (*(*mlx)).map[x + 1][y] != 'E')
		|| ((*(*mlx)).map[x + 1][y] == 'E' && (*(*mlx)).can_be_win == 1))
	{
		if (((*(*mlx)).map[x + 1][y] == 'E' && (*(*mlx)).can_be_win == 1))
			end_game(**mlx);
		(*(*mlx)).map[x][y] = '0';
		(*(*mlx)).map[x + 1][y] = 'P';
		(*(*mlx)).x_img = x;
		(*(*mlx)).y_img = y;
		get_floor_sprite(**mlx, x * 32, y * 32);
		(*(*mlx)).x_img = x + 1;
		get_char_sprite(**mlx, (x + 1) * 32, y * 32);
		(*(*mlx)).move_count++;
	}
}

static void	move_left(t_mlx **mlx, int x, int y)
{
	while (x < (*(*mlx)).x_max && (*(*mlx)).map[x][y] != 'P')
	{
		while ((*(*mlx)).map[x][y] != '\0' && (*(*mlx)).map[x][y] != 'P')
			y++;
		if ((*(*mlx)).map[x][y] != 'P')
		{
			y = 0;
			x++;
		}
	}
	if ((y > 1 && (*(*mlx)).map[x][y - 1] != '1'
		&& (*(*mlx)).map[x][y - 1] != 'E')
		|| ((*(*mlx)).map[x][y - 1] == 'E' && (*(*mlx)).can_be_win == 1))
	{
		if ((*(*mlx)).map[x][y - 1] == 'E' && (*(*mlx)).can_be_win == 1)
			end_game(**mlx);
		(*(*mlx)).map[x][y] = '0';
		(*(*mlx)).map[x][y - 1] = 'P';
		(*(*mlx)).x_img = x;
		(*(*mlx)).y_img = y;
		get_floor_sprite(**mlx, x * 32, y * 32);
		(*(*mlx)).y_img = y - 1;
		get_char_sprite(**mlx, x * 32, (y - 1) * 32);
		(*(*mlx)).move_count++;
	}
}

static void	move_right(t_mlx **mlx, int x, int y)
{
	while (x < (*(*mlx)).x_max && (*(*mlx)).map[x][y] != 'P')
	{
		while ((*(*mlx)).map[x][y] != '\0' && (*(*mlx)).map[x][y] != 'P')
			y++;
		if ((*(*mlx)).map[x][y] != 'P')
		{
			y = 0;
			x++;
		}
	}
	if ((y < (*(*mlx)).y_max - 2 && (*(*mlx)).map[x][y + 1] != '1'
		&& (*(*mlx)).map[x][y + 1] != 'E')
		|| ((*(*mlx)).map[x][y + 1] == 'E' && (*(*mlx)).can_be_win == 1))
	{
		if ((*(*mlx)).map[x][y + 1] == 'E' && (*(*mlx)).can_be_win == 1)
			end_game(**mlx);
		(*(*mlx)).map[x][y] = '0';
		(*(*mlx)).map[x][y + 1] = 'P';
		(*(*mlx)).x_img = x;
		(*(*mlx)).y_img = y;
		get_floor_sprite(**mlx, x * 32, y * 32);
		(*(*mlx)).y_img = y + 1;
		get_char_sprite(**mlx, x * 32, (y + 1) * 32);
		(*(*mlx)).move_count++;
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	int		move;

	PRINTD(keycode)
	move = mlx->move_count;
	*mlx = can_be_win(*mlx, 0, 0);
	if (keycode == UP_KEY)
		move_up(&mlx, 0, 0);
	else if (keycode == DOWN_KEY)
		move_down(&mlx, 0, 0);
	else if (keycode == LEFT_KEY)
		move_left(&mlx, 0, 0);
	else if (keycode == RIGHT_KEY)
		move_right(&mlx, 0, 0);
	else if (keycode == ESC_KEY)
	{
		mlx_destroy_image(mlx->mlx_id, mlx->img);
		mlx_destroy_window(mlx->mlx_id, mlx->win_id);
		free_map(mlx->map, (*mlx).x_max);
		exit (EXIT_SUCCESS);
	}
	if (move != mlx->move_count)
		erase_actual_counter_and_print_count(move, mlx->move_count);
	return (keycode);
}
