/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:08:24 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/06 13:48:44 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int main(int ac, char **av)
{
	t_engine	engine;

	if (ac != 2)
		write(1, "Error\nThe number of arguments is not two\n", 41);
	check_all_errors(engine, av[1]);
	// init_starter(map, error);
	return (0);
}
