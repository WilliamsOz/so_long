/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:04:21 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 16:28:47 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

t_mlx	can_be_win(t_mlx mlx, int x, int y)
{
	int		collectible;

	collectible = 0;
	while (x < mlx.x_max)
	{
		while (mlx.map[x][y] != '\0')
		{
			if (mlx.map[x][y] == 'C')
				collectible++;
			y++;
		}
		y = 0;
		x++;
	}
	if (collectible == 0)
		mlx.can_be_win = 1;
	return (mlx);
}

static int	exit_with_mouse(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_id, mlx->img);
	mlx_destroy_window(mlx->mlx_id, mlx->win_id);
	free_map(mlx->map, (*mlx).x_max);
	exit (EXIT_SUCCESS);
	return (0);
}

void	init_starter(char **map, t_maperr e)
{
	t_mlx			mlx;

	init_mlx(&mlx, e, map);
	mlx.x_max = e.x_max;
	mlx.win_size_x = ft_strlen(map[0]) * 32;
	mlx.win_size_y = e.x_max * 32;
	mlx.mlx_id = mlx_init();
	mlx.win_id = mlx_new_window(mlx.mlx_id, mlx.win_size_x, mlx.win_size_y,
			"My_game");
	mlx.img = mlx_new_image(mlx.mlx_id, mlx.win_size_x, mlx.win_size_y);
	mlx.img_addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel,
			&mlx.line_lenght, &mlx.endian);
	get_map_sprite_bonus(mlx, 0, 0, map);
	mlx_loop_hook(mlx.mlx_id, move_enemy, &mlx);
	mlx_key_hook(mlx.win_id, key_hook_bonus, &mlx);
	mlx_hook(mlx.win_id, 17, 1L << 0, exit_with_mouse, &mlx);
	mlx_loop(mlx.mlx_id);
}

int	main(int ac, char **av)
{
	char		**map;
	t_maperr	error;

	map = NULL;
	if (ac != 2)
		write(1, "Error\nThe number of arguments is not two\n", 41);
	else if (check_errors_bonus(&map, av, &error) == 1)
		return (0);
	else
		init_starter(map, error);
	return (0);
}

/*
// __attribute__((destructor))
// void    test() {
//     system("leaks so_long");
// }
*/
/*

BONUS PART :

 // ne pas oublier de free la struct enemy

There’s some sprite animation.

*/