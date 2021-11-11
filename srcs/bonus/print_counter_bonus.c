/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_counter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:03:33 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/11 10:51:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    print_counter_bonus(t_engine *engine)
{
    char    *nbr;

    nbr = ft_itoa(engine->move_count);
	mlx_string_put(engine->img->mlx_ptr, engine->img->win_ptr, 0,
		16, 0x00FF0000, nbr);
	free(nbr);
}
