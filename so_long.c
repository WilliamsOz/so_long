/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:08:24 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/09 23:07:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int	mouse_exit(t_engine **engine)
{
	free_all_engine(*engine, 1);
	return (1);
}

static int	key_hook(int keycode, t_engine *engine)
{
	if (keycode == UP_KEY)
		engine->keycode = 'w';
	else if (keycode == DOWN_KEY)
		engine->keycode = 's';
	else if (keycode == LEFT_KEY)
		engine->keycode = 'a';
	else if (keycode == RIGHT_KEY)
		engine->keycode = 'd';
	else if (keycode == ESC_KEY)
		engine->keycode = 'q';
	else
	{
		engine->keycode = '0';
		return (1);
	}
	return (0);
}

// void	move_player(t_engine *engine)
// {
// 	if (engine->keycode == 'w')
// 		move_up(engine);
// 	else if (engine->keycode == 's')
// 		move_down(engine);
// 	else if (engine->keycode == 'a')
// 		move_left(engine);
// 	else if (engine->keycode == 'd')
// 		move_right(engine);
// 	else if (engine->keycode == 'q')
// 		esc_exit(engine);
// }

// int	manage_events(t_engine *engine)
// {
// 	move_player(engine);
// 	if (BONUS == 1)
// 	{
// 		//sprite animation
// 		//move enemy 
// 	}
// 	mlx_put_image_to_window(engine->img->mlx_ptr, engine->img->win_ptr,
// 		engine->img->img_ptr, 0, 0);
// 	if (BONUS == 1)
// 	{
// 		//print counter on windows
// 	}
// 	return (1);
// }

void	mlx_engine(t_engine *engine, int size_x, int size_y)
{
	engine->keycode = '0';
	engine->move_count = 0;
	// engine = init_move(engine);
	engine->img->win_ptr = mlx_new_window(engine->img->mlx_ptr,
		size_x, size_y, "My Game");
	engine->img->img_ptr = mlx_new_image(engine->img->mlx_ptr,
		size_x, size_y);
	engine->img->addr = mlx_get_data_addr(engine->img->img_ptr,
		&engine->img->bit_per_pixel, &engine->img->line_length,
		&engine->img->endian);
	first_init_image(engine, 0, 0, 0);
	mlx_key_hook(engine->img->win_ptr, key_hook, engine);
	mlx_hook(engine->img->win_ptr, 17, 1L << 0, mouse_exit, &engine);
	// mlx_loop_hook(engine->img->mlx_ptr, manage_events, engine);// infini -> deplacement player (+ appliquer l'evenement (exit) || (monster) || (free_space))
	// -> deplacement monstre
	// -> sprite animation
	mlx_loop(engine->img->mlx_ptr);
}

void	init_mlx_engine(t_engine *engine, int size_x, int size_y)
{
	engine->img = NULL;
	engine->img = (t_img*)malloc(sizeof(t_img));
	if (engine->img == NULL)
	{
		write(1, "Error\nMlx malloc failed\n", 24);
		engine_full_destroyer(engine, 0);
	}
	engine->sprite = NULL;
	engine->sprite = (t_img*)malloc(sizeof(t_img));
	if (engine->sprite == NULL)
	{
		free(engine->img);
		engine->img = NULL;
		write(1, "Error\nMlx malloc failed\n", 24);
		engine_full_destroyer(engine, 0);
	}
	engine->img->mlx_ptr = mlx_init();
	while (engine->map[size_y] != NULL)
		size_y++;
	size_y *= 32;
	size_x = 0;
	size_x = ft_strlen(engine->map[0]);
	size_x *= 32;
	mlx_engine(engine, size_x, size_y);
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
	init_mlx_engine(engine, 0, 0);
	return (0);
}
