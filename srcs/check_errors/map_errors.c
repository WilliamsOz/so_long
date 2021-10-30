/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:31:31 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/29 03:10:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_map_errors(t_maperr e, int ind)
{
	if (ind == 1 && e.empty_map == 1)
			write(1, "Map is empty\n", 13);
	if (ind == 1 && e.malloc_failed == 1)
		write(1, "Malloc failed\n", 14);
	if (ind == 0 && e.is_empty_line == 1)
		write(1, "Map is not correct\n", 19);
	else if (ind == 0 && e.is_valid_char == 1)
		write(1, "Map is not correct\n", 19);
	else if (ind == 0 && e.no_exit == 1)
		write(1, "No exit possible\n", 17);
	else if (ind == 0 && e.no_collectibles == 1)
		write(1, "No collectibles inside map\n", 27);
	else if (ind == 0 && e.no_player == 1)
		write(1, "There is no player\n", 19);
	else if (ind == 0 && e.too_many_player == 1)
		write(1, "There is too many player\n", 25);
	else if (ind == 0 && e.is_map_open == 1)
		write(1, "Map is open\n", 12);
	else if (ind == 0 && e.map_is_square == 1)
		write(1, "Map is a square\n", 16);
	else if (ind == 0 && e.map_too_short == 1)
		write(1, "Map is too small\n", 17);
	else if (ind == 0 && e.map_is_not_rectangle == 1)
		write(1, "Map is not a rectangle\n", 23);
}

int	map_errors(t_maperr e, int ind)
{
	if (ind == 1 && (e.malloc_failed == 1 || e.empty_map == 1))
	{
		write(1, "Error\n", 6);
		print_map_errors(e, ind);
		return (1);
	}
	else if (ind == 0 && (e.is_valid_char == 1 || e.no_exit == 1
		|| e.no_collectibles == 1 || e.no_player == 1
		|| e.too_many_player == 1 || e.is_empty_line == 1
		|| e.is_map_open == 1 || e.map_is_square == 1 || e.map_too_short == 1
		|| e.map_is_not_rectangle == 1))
	{
		write(1, "Error\n", 6);
		print_map_errors(e, 0);
		return (1);
	}
	return (0);
}
