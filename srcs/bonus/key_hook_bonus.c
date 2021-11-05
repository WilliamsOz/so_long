/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:30:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 16:29:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
	if ((*(*mlx)).map[x - 1][y] == 'M')
		end_game(**mlx);
	if ((x > 1 && (*(*mlx)).map[x - 1][y] != '1'
		&& (*(*mlx)).map[x - 1][y] != 'E')
		|| ((*(*mlx)).map[x - 1][y] == 'E' && (*(*mlx)).can_be_win == 1))
	{
		if ((*(*mlx)).map[x - 1][y] == 'E' && (*(*mlx)).can_be_win == 1)
			end_game(**mlx);
		**mlx = apply_modif_on_mlx_for_up(**mlx, x, y);
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
	if ((*(*mlx)).map[x + 1][y] == 'M')
		end_game(**mlx);
	if ((x < (*(*mlx)).x_max - 2 && (*(*mlx)).map[x + 1][y] != '1'
		&& (*(*mlx)).map[x + 1][y] != 'E')
		|| ((*(*mlx)).map[x + 1][y] == 'E' && (*(*mlx)).can_be_win == 1))
	{
		if (((*(*mlx)).map[x + 1][y] == 'E' && (*(*mlx)).can_be_win == 1))
			end_game(**mlx);
		**mlx = apply_modif_on_mlx_for_down(**mlx, x, y);
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
	if ((*(*mlx)).map[x][y - 1] == 'M')
		end_game(**mlx);
	if ((y > 1 && (*(*mlx)).map[x][y - 1] != '1'
		&& (*(*mlx)).map[x][y - 1] != 'E')
		|| ((*(*mlx)).map[x][y - 1] == 'E' && (*(*mlx)).can_be_win == 1))
	{
		if ((*(*mlx)).map[x][y - 1] == 'E' && (*(*mlx)).can_be_win == 1)
			end_game(**mlx);
		**mlx = apply_modif_on_mlx_for_lef(**mlx, x, y);
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
	if ((*(*mlx)).map[x][y + 1] == 'M')
		end_game(**mlx);
	if ((y < (*(*mlx)).y_max - 2 && (*(*mlx)).map[x][y + 1] != '1'
		&& (*(*mlx)).map[x][y + 1] != 'E')
		|| ((*(*mlx)).map[x][y + 1] == 'E' && (*(*mlx)).can_be_win == 1))
	{
		if ((*(*mlx)).map[x][y + 1] == 'E' && (*(*mlx)).can_be_win == 1)
			end_game(**mlx);
		**mlx = apply_modif_on_mlx_for_right(**mlx, x, y);
		get_floor_sprite(**mlx, x * 32, y * 32);
		(*(*mlx)).y_img = y + 1;
		get_char_sprite(**mlx, x * 32, (y + 1) * 32);
		(*(*mlx)).move_count++;
	}
}

void	print_bonus(t_mlx mlx, int move)
{
	char	*dest;

	if (move != 0)
	{
		mlx.x_img = 0;
		mlx.y_img = 0;
		get_wall_sprite_bonus(mlx, 0, 0);
	}
	dest = ft_itoa(move);
	mlx_string_put(mlx.mlx_id, mlx.win_id, 0, 16, 0x00FF0000, dest);
	free(dest);
}

int	key_hook_bonus(int keycode, t_mlx *mlx)
{
	int		move;

	move = mlx->move_count;
	*mlx = can_be_win(*mlx, 0, 0);
	if (keycode == MAC_UP_KEY)
		move_up(&mlx, 0, 0);
	else if (keycode == MAC_DOWN_KEY)
		move_down(&mlx, 0, 0);
	else if (keycode == MAC_LEFT_KEY)
		move_left(&mlx, 0, 0);
	else if (keycode == MAC_RIGHT_KEY)
		move_right(&mlx, 0, 0);
	else if (keycode == MAC_ESC_KEY)
	{
		free_mlx_and_map(*mlx);
		exit (EXIT_SUCCESS);
	}
	if (move != mlx->move_count)
		print_bonus(*mlx, mlx->move_count);
	return (1);
}
