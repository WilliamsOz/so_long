/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_destroyer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:55:13 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/10 10:28:24 by user42           ###   ########.fr       */
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
	mlx_destroy_image(engine->img->mlx_ptr, engine->img->img_ptr);
	engine->img->img_ptr = NULL;
	free(engine->sprite);
	engine->sprite = NULL;
	mlx_destroy_window(engine->img->mlx_ptr, engine->img->win_ptr);
	engine->img->win_ptr = NULL;
	mlx_destroy_display(engine->img->mlx_ptr);
	free(engine->img->mlx_ptr);
	engine->img->mlx_ptr = NULL;
	free(engine->img);
	engine->img = NULL;
	engine_full_destroyer(engine, ind);
}