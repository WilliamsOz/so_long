/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:10:10 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/04 19:21:30 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	erase_actual_counter_and_print_count(int move, int mlx_move)
{
	move = mlx_move;
	write(1, "\b", 1);
	while (move >= 10)
	{
		write(1, "\b", 1);
		move /= 10;
	}
	ft_putnbr(mlx_move);
}
