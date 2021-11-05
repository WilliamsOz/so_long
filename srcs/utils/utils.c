/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:15:44 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 16:31:17 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_mlx_and_map(t_mlx mlx)
{
	mlx_destroy_image(mlx.mlx_id, mlx.img);
	mlx_destroy_window(mlx.mlx_id, mlx.win_id);
	free_map(mlx.map, mlx.x_max);
}

void	end_game(t_mlx mlx)
{
	free_mlx_and_map(mlx);
	exit (EXIT_SUCCESS);
}

void	my_pixel_put(t_mlx *mlx, int x, int y, char *color)
{
	char	*dst;

	dst = mlx->img_addr + (y * mlx->line_lenght
			+ x * (mlx->bits_per_pixel / 8));
	*(int *)dst = *(int *)color;
}

void	init_mlx(t_mlx *mlx, t_maperr e, char **map)
{
	(*mlx).enemy_count = 0;
	(*mlx).monster_move_count = 0;
	(*mlx).win = 0;
	(*mlx).y_max = ft_strlen(map[0]);
	(*mlx).can_be_win = 0;
	(*mlx).map = map;
	(*mlx).move_count = 0;
	(*mlx).x_max = e.x_max;
	(*mlx).lin = 0;
	(*mlx).col = 0;
}

void	free_map(char **map, int x_max)
{
	int		count;

	count = 0;
	while (count < x_max)
	{
		free(map[count]);
		count++;
	}
	free(map);
	map = NULL;
}

void	init_maperror(t_maperr **error)
{
	(*(*error)).free_count = 0;
	(*(*error)).x_max = 0;
	(*(*error)).is_symlink = 0;
	(*(*error)).is_directory = 0;
	(*(*error)).file_exist = 0;
	(*(*error)).empty_name_map = 0;
	(*(*error)).not_ber_extension = 0;
	(*(*error)).empty_map = 0;
	(*(*error)).empty_line = 0;
	(*(*error)).malloc_failed = 0;
	(*(*error)).is_valid_char = 0;
	(*(*error)).no_exit = 0;
	(*(*error)).no_collectibles = 0;
	(*(*error)).no_player = 0;
	(*(*error)).too_many_player = 0;
	(*(*error)).is_map_open = 0;
	(*(*error)).map_is_square = 0;
	(*(*error)).map_too_short = 0;
	(*(*error)).map_is_not_rectangle = 0;
	(*(*error)).mlx_init_error = 0;
	(*(*error)).mlx_wind_error = 0;
	(*(*error)).mlx_img_error = 0;
}
