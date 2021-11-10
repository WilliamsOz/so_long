/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:14:27 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/10 10:27:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	get_floor_sprite(t_engine *engine, int i, int j)
{
	char	*pixel_texture;
	int		x;
	int		y;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
		"./textures/floor.xpm", &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
		&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
		&engine->sprite->endian);
	y = -1;
	while (++y < 32)
	{
		x = -1;
		while (++x < 32)
		{
			pixel_texture = engine->sprite->addr +
			(y * engine->sprite->line_length +
			x * (engine->sprite->bit_per_pixel / 8));
			my_mlx_pixel_put(engine->img, x + i, y + j, pixel_texture);
		}
	}
	free(engine->sprite->img_ptr);
}

void	get_char_sprite(t_engine *engine, int i, int j)
{
	char	*pixel_texture;
	int		x;
	int		y;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
		"./textures/char.xpm", &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
		&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
		&engine->sprite->endian);
	y = -1;
	while (++y < 32)
	{
		x = -1;
		while (++x < 32)
		{
			pixel_texture = engine->sprite->addr +
			(y * engine->sprite->line_length +
			x * (engine->sprite->bit_per_pixel / 8));
			my_mlx_pixel_put(engine->img, x + i, y + j, pixel_texture);
		}
	}
	free(engine->sprite->img_ptr);
}

void	get_exit_sprite(t_engine *engine, int i, int j)
{
	char	*pixel_texture;
	int		x;
	int		y;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
		"./textures/exit.xpm", &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
		&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
		&engine->sprite->endian);
	y = -1;
	while (++y < 32)
	{
		x = -1;
		while (++x < 32)
		{
			pixel_texture = engine->sprite->addr +
			(y * engine->sprite->line_length +
			x * (engine->sprite->bit_per_pixel / 8));
			my_mlx_pixel_put(engine->img, x + i, y + j, pixel_texture);
		}
	}
	free(engine->sprite->img_ptr);
}

void	get_collectible_sprite(t_engine *engine, int i, int j)
{
	char	*pixel_texture;
	int		x;
	int		y;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
		"./textures/collectible.xpm", &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
		&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
		&engine->sprite->endian);
	y = -1;
	while (++y < 32)
	{
		x = -1;
		while (++x < 32)
		{
			pixel_texture = engine->sprite->addr +
			(y * engine->sprite->line_length +
			x * (engine->sprite->bit_per_pixel / 8));
			my_mlx_pixel_put(engine->img, x + i, y + j, pixel_texture);
		}
	}
	free(engine->sprite->img_ptr);
}

void	get_wall_sprite(t_engine *engine, int i, int j)
{
	char	*pixel_texture;
	int		x;
	int		y;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
		"./textures/wall.xpm", &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
		&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
		&engine->sprite->endian);
	y = -1;
	while (++y < 32)
	{
		x = -1;
		while (++x < 32)
		{
			pixel_texture = engine->sprite->addr +
			(y * engine->sprite->line_length +
			x * (engine->sprite->bit_per_pixel / 8));
			my_mlx_pixel_put(engine->img, x + i, y + j, pixel_texture);
		}
	}
	free(engine->sprite->img_ptr);
}
