/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_destroyer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:55:13 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/17 12:49:51 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/so_long.h"

void	engine_destroyer(t_engine *engine, int ind)
{
	free(engine);
	engine = NULL;
	if (ind == 1)
		exit (EXIT_SUCCESS);
	exit (EXIT_FAILURE);
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
	if (BONUS == 1 && engine->monster_position != NULL)
		ft_lst_clear(engine->monster_position);
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
