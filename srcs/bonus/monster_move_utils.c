/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:34:05 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 16:29:31 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	enemy_right_move(t_mlx **mlx, int x, int *y)
{
    (*mlx)->map[x][*y] = '0';
	(*mlx)->map[x][*y + 1] = 'M';
	(*mlx)->x_img = x;
	(*mlx)->y_img = *y;
	get_floor_sprite(**mlx, x * 32, *y * 32);
	(*mlx)->y_img = *y + 1;
	get_monster_sprite(**mlx, x + 32, (*y + 1) * 32);
	*y += 2;
}

void	enemy_left_move(t_mlx **mlx, int x, int *y)
{
    (*mlx)->map[x][*y] = '0';
	(*mlx)->map[x][*y - 1] = 'M';
	(*mlx)->x_img = x;
	(*mlx)->y_img = *y;
	get_floor_sprite(**mlx, x * 32, *y * 32);
	(*mlx)->y_img = *y - 1;
	get_monster_sprite(**mlx, x + 32, (*y - 1) * 32);
	if ((*mlx)->map[x][*y - 1] == 'P')
		end_game((*(*mlx)));
	*y += 1;
}
