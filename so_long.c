/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:08:24 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/10 13:43:56 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int	mouse_and_esc_exit(t_engine *engine)
{
	free_all_engine(engine, 1);
	return (1);
}

void	print_move(t_engine *engine, int count)
{
	if (BONUS == 0)
	{
		write(1, "\b", 1);
		while (count >= 10)
		{
			write(1, "\b", 1);
			count /= 10;
		}
		ft_putnbr(engine->move_count);
	}
	// else if (BONUS == 1)
	// {
		
	// }
}

int	manage_events(t_engine *engine)
{
	int	count;

	count = engine->move_count;
	engine = move_player(engine);
	// if (BONUS == 1)
	// {
	// 	//sprite animation
	// 	//move enemy 
	// }
	mlx_put_image_to_window(engine->img->mlx_ptr, engine->img->win_ptr,
		engine->img->img_ptr, 0, 0);
	if (count != engine->move_count)
		print_move(engine, engine->move_count); // print on screen for bonus
	return (1);
}

void	mlx_engine(t_engine *engine, int size_x, int size_y)
{
	engine->keycode = '0';
	engine->move_count = 0;
	engine = get_player_position(engine);
	engine = get_all_collectible(engine);
	engine->img->win_ptr = mlx_new_window(engine->img->mlx_ptr,
		size_x, size_y, "My Game");
	engine->img->img_ptr = mlx_new_image(engine->img->mlx_ptr,
		size_x, size_y);
	engine->img->addr = mlx_get_data_addr(engine->img->img_ptr,
		&engine->img->bit_per_pixel, &engine->img->line_length,
		&engine->img->endian);
	first_init_image(engine, 0, 0, 0);
	mlx_key_hook(engine->img->win_ptr, key_hook, engine);
	mlx_hook(engine->img->win_ptr, 17, 1L << 17, mouse_and_esc_exit, engine);
	mlx_loop_hook(engine->img->mlx_ptr, manage_events, engine);// infini -> deplacement player (+ appliquer l'evenement (exit) || (monster) || (free_space))
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
