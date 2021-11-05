/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_errors_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:17:38 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/03 17:46:02 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	unvalid_char(char c)
{
	if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
		return (1);
	return (0);
}

void	init_data(t_player *data)
{
	(*data).player = 0;
	(*data).exit = 0;
	(*data).collectibles = 0;
}

t_player	get_data_of_map(char c, t_player data)
{
	if (c == 'E')
		data.exit++;
	else if (c == 'C')
		data.collectibles++;
	else if (c == 'P')
		data.player++;
	return (data);
}

t_maperr	is_data_valid(t_maperr e, t_player data)
{
	if (data.exit < 1)
		e.no_exit = 1;
	else if (data.collectibles < 1)
		e.no_collectibles = 1;
	else if (data.player < 1)
		e.no_player = 1;
	else if (data.player > 1)
		e.too_many_player = 1;
	return (e);
}
