/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:49:03 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/29 00:31:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_maperr	check_file(char *map, t_maperr e)
{
    int     i;

    i = 0;
	if (ft_strlen(map) <= 4)
		e.empty_name_map = 1;
	else
	{
		while (map[i] != '\0')
            i++;
        if (map[i - 1] != 'r' && map[i - 2] != 'e' && map[i - 3] != 'b'
            && map[i - 4] != '.')
            e.not_ber_extension = 1;
		if (map[i - 1] == 'r' && map[i - 2] == 'e' && map[i - 3] == 'b'
			&& map[i - 4] == '.' && map[i = 4] == '/')
			e.empty_name_map = 1;
	}
	return (e);
}
