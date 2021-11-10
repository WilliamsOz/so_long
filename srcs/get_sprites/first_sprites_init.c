/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sprites_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:19:57 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/10 16:29:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, char *pixel)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bit_per_pixel / 8));
	*(int *)dst = *(int *)pixel;
}

void	first_init_image(t_engine *engine, int i, int j, int x_pos)
{
	int	y_pos;

	while (engine->map[i] != NULL)
	{
		y_pos = 0;
		j = -1;
		while (engine->map[i][++j] != '\0')
		{
			if (engine->map[i][j] == '1')
				get_wall_sprite(engine, y_pos, x_pos, -1);
			else if (engine->map[i][j] == '0')
				get_floor_sprite(engine, y_pos, x_pos, -1);
			else if (engine->map[i][j] == 'P')
				get_char_sprite(engine, y_pos, x_pos, -1);
			else if (engine->map[i][j] == 'E')
				get_exit_sprite(engine, y_pos, x_pos, -1);
			else if (engine->map[i][j] == 'C' && engine->spr_ind == 1)
				get_collectible_sprite(engine, y_pos, x_pos, -1);
			else if (BONUS == 1 && engine->map[i][j] == 'M')
				get_monster_sprite(engine, y_pos, x_pos, -1);
			y_pos += 32;
		}
		x_pos += 32;
		i++;
	}
}
