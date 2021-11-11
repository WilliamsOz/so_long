/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:14:27 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/11 15:48:14 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	get_floor_sprite(t_engine *engine, int i, int j, int y)
{
	char	*pixel_texture;
	int		x;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
			"./textures/floor.xpm", &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
			&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
			&engine->sprite->endian);
	while (++y < 32)
	{
		x = -1;
		while (++x < 32)
		{
			pixel_texture = engine->sprite->addr
				+ (y * engine->sprite->line_length
					+ x * (engine->sprite->bit_per_pixel / 8));
			my_mlx_pixel_put(engine->img, x + i, y + j, pixel_texture);
		}
	}
	mlx_destroy_image(engine->img->mlx_ptr, engine->sprite->img_ptr);
}

void	get_char_sprite(t_engine *engine, int i, int j, int y)
{
	char	*pixel_texture;
	int		x;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
			"./textures/char.xpm", &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
			&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
			&engine->sprite->endian);
	while (++y < 32)
	{
		x = -1;
		while (++x < 32)
		{
			pixel_texture = engine->sprite->addr
				+ (y * engine->sprite->line_length
					+ x * (engine->sprite->bit_per_pixel / 8));
			my_mlx_pixel_put(engine->img, x + i, y + j, pixel_texture);
		}
	}
	mlx_destroy_image(engine->img->mlx_ptr, engine->sprite->img_ptr);
}

void	get_exit_sprite(t_engine *engine, int i, int j, int y)
{
	char	*pixel_texture;
	int		x;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
			"./textures/exit.xpm", &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
			&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
			&engine->sprite->endian);
	while (++y < 32)
	{
		x = -1;
		while (++x < 32)
		{
			pixel_texture = engine->sprite->addr
				+ (y * engine->sprite->line_length
					+ x * (engine->sprite->bit_per_pixel / 8));
			my_mlx_pixel_put(engine->img, x + i, y + j, pixel_texture);
		}
	}
	mlx_destroy_image(engine->img->mlx_ptr, engine->sprite->img_ptr);
}

void	get_collectible_sprite(t_engine *engine, int i, int j, int y)
{
	char	*pixel_texture;
	int		x;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
			"./textures/collectible1.xpm", &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
			&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
			&engine->sprite->endian);
	while (++y < 32)
	{
		x = -1;
		while (++x < 32)
		{
			pixel_texture = engine->sprite->addr
				+ (y * engine->sprite->line_length
					+ x * (engine->sprite->bit_per_pixel / 8));
			my_mlx_pixel_put(engine->img, x + i, y + j, pixel_texture);
		}
	}
	mlx_destroy_image(engine->img->mlx_ptr, engine->sprite->img_ptr);
}

void	get_wall_sprite(t_engine *engine, int i, int j, int y)
{
	char	*pixel_texture;
	int		x;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
			"./textures/wall.xpm", &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
			&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
			&engine->sprite->endian);
	while (++y < 32)
	{
		x = -1;
		while (++x < 32)
		{
			pixel_texture = engine->sprite->addr
				+ (y * engine->sprite->line_length
					+ x * (engine->sprite->bit_per_pixel / 8));
			my_mlx_pixel_put(engine->img, x + i, y + j, pixel_texture);
		}
	}
	mlx_destroy_image(engine->img->mlx_ptr, engine->sprite->img_ptr);
}
