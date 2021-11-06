/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:22:52 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/06 18:50:51 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void    free_map(t_engine engine, int x)
{
	while (engine.map[x] != NULL)
	{
		free(engine.map[x]);
		engine.map[x] = NULL;
		x++;
	}
	free(engine.map[x]);
	engine.map[x] = NULL;
	free(engine.map);
}
