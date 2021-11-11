/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_patrol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:09:22 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/11 15:36:22 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

t_engine	*monster_patrol(t_engine *engine)
{
	static int	time = 0;

	time++;
	if (time % 10 != 0)
		return (engine);
	engine = move_monster(engine);
	if (time == 150)
		time = 0;
	return (engine);
}
