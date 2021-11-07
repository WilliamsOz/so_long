/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:08:24 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/07 19:15:53 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	start_graphic_part(t_engine *engine)
{
	(void)engine;
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
	start_graphic_part(engine);
	return (0);
}
