/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move_modification.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:30:06 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 16:30:45 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_mlx	apply_modif_on_mlx_for_up(t_mlx mlx, int x, int y)
{
	mlx.map[x][y] = '0';
	mlx.map[x - 1][y] = 'P';
	mlx.x_img = x;
	mlx.y_img = y;
	return (mlx);
}

t_mlx	apply_modif_on_mlx_for_down(t_mlx mlx, int x, int y)
{
	mlx.map[x][y] = '0';
	mlx.map[x + 1][y] = 'P';
	mlx.x_img = x;
	mlx.y_img = y;
	return (mlx);
}

t_mlx	apply_modif_on_mlx_for_lef(t_mlx mlx, int x, int y)
{
	mlx.map[x][y] = '0';
	mlx.map[x][y - 1] = 'P';
	mlx.x_img = x;
	mlx.y_img = y;
	return (mlx);
}

t_mlx	apply_modif_on_mlx_for_right(t_mlx mlx, int x, int y)
{
	mlx.map[x][y] = '0';
	mlx.map[x][y + 1] = 'P';
	mlx.x_img = x;
	mlx.y_img = y;
	return (mlx);
}
