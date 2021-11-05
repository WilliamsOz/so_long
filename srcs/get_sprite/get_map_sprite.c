/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:37:46 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 19:12:21 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_floor_sprite(t_mlx mlx, int x, int y)
{
	mlx.sprite_img = mlx_xpm_file_to_image(mlx.mlx_id, "./textures/floor.xpm",
			&mlx.width, &mlx.height);
	mlx.sprite_addr = mlx_get_data_addr(mlx.sprite_img, &mlx.bits_per_pixel,
			&mlx.line_lenght, &mlx.endian);
	while (mlx.lin < 32)
	{
		x = mlx.x_img * 32;
		while (mlx.col < 32)
		{
			mlx.buffer = mlx.sprite_addr + (y * mlx.line_lenght
					+ x * (mlx.bits_per_pixel / 8));
			my_pixel_put(&mlx, x, y, mlx.buffer);
			y++;
			mlx.col++;
		}
		mlx.col = 0;
		mlx.lin++;
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx.mlx_id, mlx.win_id, mlx.sprite_img,
		mlx.y_img * 32, mlx.x_img * 32);
}

static void	get_wall_sprite(t_mlx mlx, int x, int y)
{
	mlx.sprite_img = mlx_xpm_file_to_image(mlx.mlx_id, "./textures/wall.xpm",
			&mlx.width, &mlx.height);
	mlx.sprite_addr = mlx_get_data_addr(mlx.sprite_img, &mlx.bits_per_pixel,
			&mlx.line_lenght, &mlx.endian);
	while (mlx.lin < 32)
	{
		x = mlx.x_img * 32;
		while (mlx.col < 32)
		{
			mlx.buffer = mlx.sprite_addr + (y * mlx.line_lenght
					+ x * (mlx.bits_per_pixel / 8));
			my_pixel_put(&mlx, x, y, mlx.buffer);
			y++;
			mlx.col++;
		}
		mlx.col = 0;
		mlx.lin++;
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx.mlx_id, mlx.win_id, mlx.sprite_img,
		mlx.y_img * 32, mlx.x_img * 32);
}

static void	get_exit_sprite(t_mlx mlx, int x, int y)
{
	mlx.sprite_img = mlx_xpm_file_to_image(mlx.mlx_id, "./textures/exit.xpm",
			&mlx.width, &mlx.height);
	mlx.sprite_addr = mlx_get_data_addr(mlx.sprite_img, &mlx.bits_per_pixel,
			&mlx.line_lenght, &mlx.endian);
	while (mlx.lin < 32)
	{
		x = mlx.x_img * 32;
		while (mlx.col < 32)
		{
			mlx.buffer = mlx.sprite_addr + (y * mlx.line_lenght
					+ x * (mlx.bits_per_pixel / 8));
			my_pixel_put(&mlx, x, y, mlx.buffer);
			y++;
			mlx.col++;
		}
		mlx.col = 0;
		mlx.lin++;
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx.mlx_id, mlx.win_id, mlx.sprite_img,
		mlx.y_img * 32, mlx.x_img * 32);
}

static void	get_collectible_sprite(t_mlx mlx, int x, int y)
{
	mlx.sprite_img = mlx_xpm_file_to_image(mlx.mlx_id,
			"./textures/collectible.xpm", &mlx.width, &mlx.height);
	mlx.sprite_addr = mlx_get_data_addr(mlx.sprite_img, &mlx.bits_per_pixel,
			&mlx.line_lenght, &mlx.endian);
	while (mlx.lin < 32)
	{
		x = mlx.x_img * 32;
		while (mlx.col < 32)
		{
			mlx.buffer = mlx.sprite_addr + (y * mlx.line_lenght
					+ x * (mlx.bits_per_pixel / 8));
			my_pixel_put(&mlx, x, y, mlx.buffer);
			y++;
			mlx.col++;
		}
		mlx.col = 0;
		mlx.lin++;
		y = 0;
		x++;
	}
	mlx_put_image_to_window(mlx.mlx_id, mlx.win_id, mlx.sprite_img,
		mlx.y_img * 32, mlx.x_img * 32);
}

void	get_map_sprite(t_mlx mlx, int x, int y, char **map)
{
	while (x < mlx.x_max)
	{
		while (map[x][y] != '\0')
		{
			mlx.x_img = x;
			mlx.y_img = y;
			if (map[x][y] == 'P')
				get_char_sprite(mlx, x * 32, y * 32);
			else if (map[x][y] == '1')
				get_wall_sprite(mlx, x * 32, y * 32);
			else if (map[x][y] == '0')
				get_floor_sprite(mlx, x * 32, y * 32);
			else if (map[x][y] == 'E')
				get_exit_sprite(mlx, x * 32, y * 32);
			else if (map[x][y] == 'C')
				get_collectible_sprite(mlx, x * 32, y * 32);
			y++;
		}
		y = 0;
		x++;
	}
}
