/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_destroyer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:55:13 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/09 15:00:01 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	engine_destroyer(t_engine *engine, int ind)
{
	free(engine);
	engine = NULL;
	if (ind == 0)
		exit (EXIT_FAILURE);
	else if (ind == 1)
		exit (EXIT_SUCCESS);
}

void	engine_error_destroyer(t_engine *engine, int ind)
{
	free(engine->error);
	engine->error = NULL;
	engine_destroyer(engine, ind);
}

void	engine_map_destroyer(t_engine *engine, int ind)
{
	free_map(engine, 0);
	engine_error_destroyer(engine, ind);
}

void	engine_full_destroyer(t_engine *engine, int ind)
{
	free(engine->data);
	engine->data = NULL;
	engine_map_destroyer(engine, ind);
}

void	free_all_engine(t_engine *engine, int ind)
{
	mlx_destroy_image(engine->mlx->mlx_id, engine->mlx->image_id);
	engine->mlx->image_id = NULL;
	mlx_destroy_window(engine->mlx->mlx_id, engine->mlx->windows_id);
	engine->mlx->windows_id = NULL;
	mlx_destroy_display(engine->mlx->mlx_id);
	free(engine->mlx->mlx_id);
	engine->mlx->mlx_id = NULL;
	free(engine->mlx);
	engine->mlx = NULL;
	engine_full_destroyer(engine, ind);
}