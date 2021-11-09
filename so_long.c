/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:08:24 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/09 15:01:38 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int	mouse_exit(t_engine **engine)
{
	free_all_engine(*engine, 1);
	return (1);
}

void	mlx_engine(t_engine *engine)
{

	engine->mlx->windows_id = mlx_new_window(engine->mlx->mlx_id,
		engine->mlx->windows_x, engine->mlx->windows_y, "My Game");
	engine->mlx->image_id = mlx_new_image(engine->mlx->mlx_id,
		engine->mlx->windows_x, engine->mlx->windows_y);


	mlx_hook(engine->mlx->windows_id, 17, 1L << 0, mouse_exit, &engine);
	mlx_loop(engine->mlx->mlx_id);
}

void	init_mlx_engine(t_engine *engine)
{
	engine->mlx = NULL;
	engine->mlx = (t_mlx*)malloc(sizeof(t_mlx));
	if (engine->mlx == NULL)
	{
		write(1, "Error\nMlx malloc failed\n", 24);
		engine_full_destroyer(engine, 0);
	}
	engine->mlx->mlx_id = mlx_init();
	engine->mlx->windows_y = 0;
	while (engine->map[engine->mlx->windows_y] != NULL)
		engine->mlx->windows_y++;
	engine->mlx->windows_y *= 32;
	engine->mlx->windows_x = 0;
	engine->mlx->windows_x = ft_strlen(engine->map[0]);
	engine->mlx->windows_x *= 32;
	mlx_engine(engine);
}

int main(int ac, char **av)
{
	t_engine	*engine;

	if (ac != 2)
		write(1, "Error\nThe number of arguments is not two\n", 41);
	else if (ft_strcmp("/dev/random", av[1]) == 1
			|| ft_strcmp("/dev/null", av[1]) == 1)
		return (0);
	engine = NULL;
	engine = check_all_errors(engine, av[1]);
	init_mlx_engine(engine);
	return (0);
}
