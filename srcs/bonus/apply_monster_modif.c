/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_monster_modif.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:44:01 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 16:29:10 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	find_all_enemy(t_mlx mlx, int x, int y)
{
	int	count;

	count = 0;
	while (x < mlx.x_max)
	{
		while (mlx.map[x][y] != '\0')
		{
			if (mlx.map[x][y] == 'M')
				count++;
			y++;
		}
		y = 0;
		x++;
	}
	return (count);
}

static void	find_pos(t_mlx mlx, int *x, int *y)
{
	while (*x < mlx.x_max && mlx.map[*x][*y] != 'M')
	{
		while (mlx.map[*x][*y] != '\0' && mlx.map[*x][*y] != 'M')
			*y += 1;
		if (mlx.map[*x][*y] != 'M')
		{
			*y = 0;
			*x += 1;
		}
	}
}

int		is_all_enemy_at_right(t_mlx mlx, int x, int y)
{
	while (x < mlx.x_max)
	{
		while (mlx.map[x][y] != '\0')
		{
			if (mlx.map[x][y] == 'M' && mlx.map[x][y + 1] == '0')
				return (0);
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

int		is_all_enemy_at_left(t_mlx mlx, int x, int y)
{
	while (x < mlx.x_max)
	{
		while (mlx.map[x][y] != '\0')
		{
			if (mlx.map[x][y] == 'M' && mlx.map[x][y - 1] == '0')
				return (0);
			y++;
		}
		y = 0;
		x++;
	}
	return (1);
}

int	move_enemy(t_mlx *mlx, int x, int y)
{
	static int	g_ind = 2;
	static int	g_time = 1;

	g_time++;
	if (g_time % 3000 != 0)
		return (0);
	if (g_ind == 2 && is_all_enemy_at_right(*mlx, 0, 0) == 1)
		g_ind = 1;
	else if (g_ind == 1 && is_all_enemy_at_left(*mlx, 0, 0) == 1)
		g_ind = 2;
	x = 0;
	y = 0;
	mlx->enemy_count = find_all_enemy(*mlx, 0, 0);
	while (mlx->enemy_count > 0)
	{
		find_pos(*mlx, &x, &y);
		if (g_ind == 2 && mlx->map[x][y + 1] == '0')
			enemy_right_move(&mlx, x, &y);
		else if (g_ind == 1 && mlx->map[x][y - 1] == '0')
			enemy_left_move(&mlx, x, &y);
		else if (mlx->map[x][y + 1] == 'P' || mlx->map[x][y - 1] == 'P')
			end_game(*mlx);
		else
			y++;
		mlx->enemy_count--;
	}
	return (1);
}
