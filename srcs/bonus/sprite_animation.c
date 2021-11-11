/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:08:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/11 10:54:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	get_collectible_sprite_bonus(t_engine *engine, int i, int j, int y)
{
	char	*pixel_texture;
	int		x;
	int		width;
	int		height;

	width = 32;
	height = 32;
	engine->sprite->img_ptr = mlx_xpm_file_to_image(engine->img->mlx_ptr,
		engine->spr, &width, &height);
	engine->sprite->addr = mlx_get_data_addr(engine->sprite->img_ptr,
		&engine->sprite->bit_per_pixel, &engine->sprite->line_length,
		&engine->sprite->endian);
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
	mlx_destroy_image(engine->img->mlx_ptr, engine->sprite->img_ptr);
}

static	t_engine	*get_sprite_animation(t_engine *engine)
{
	if (engine->spr_ind == 2)
		engine->spr = "./textures/collectible2.xpm";
	else if (engine->spr_ind == 3)
		engine->spr = "./textures/collectible3.xpm";
	else if (engine->spr_ind == 4)
		engine->spr = "./textures/collectible4.xpm";
	else if (engine->spr_ind == 5)
		engine->spr = "./textures/collectible1.xpm";
	return (engine);
}

t_engine	*collectible_sprite_animation(t_engine *engine, int x, int y)
{
	static int  sprite_animation = 0;

	sprite_animation++;
	if (sprite_animation % 5 != 0)
		return (engine);
	engine->spr_ind++;
	engine = get_sprite_animation(engine);
	while (engine->map[x] != NULL)
	{
		while (engine->map[x][y] != '\0')
		{
			if (engine->map[x][y] == 'C')
				get_collectible_sprite_bonus(engine, y * 32, x * 32, -1);
			y++;
		}
		y = 0;
		x++;
	}
	if (engine->spr_ind == 5)
		engine->spr_ind = 1;
	if (sprite_animation == 150)
		sprite_animation = 0;
	return (engine);
}