/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:11:55 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 16:35:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	get_char_sprite(t_mlx mlx, int x, int y)
{
	mlx.sprite_img = mlx_xpm_file_to_image(mlx.mlx_id, "./textures/char.xpm",
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
