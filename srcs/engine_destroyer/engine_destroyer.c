/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_destroyer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:55:13 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/07 18:06:18 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	engine_destroyer(t_engine *engine)
{
	free(engine);
	engine = NULL;
	exit (EXIT_FAILURE);
}

void	engine_error_destroyer(t_engine *engine)
{
	free(engine->error);
	engine->error = NULL;
	engine_destroyer(engine);
}

void	engine_map_destroyer(t_engine *engine)
{
	free_map(engine, 0);
	engine_error_destroyer(engine);
}

void	engine_full_destroyer(t_engine *engine)
{
	free(engine->data);
	engine->data = NULL;
	engine_map_destroyer(engine);
}