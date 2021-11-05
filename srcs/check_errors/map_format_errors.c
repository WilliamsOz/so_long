/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:49:03 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/03 14:50:26 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_maperr	check_file(char *name_file, t_maperr e)
{
	int	i;

	i = 0;
	if (ft_strlen(name_file) <= 4)
		e.empty_name_map = 1;
	else
	{
		while (name_file[i] != '\0')
			i++;
		if (name_file[i - 1] != 'r' && name_file[i - 2] != 'e'
			&& name_file[i - 3] != 'b' && name_file[i - 4] != '.')
			e.not_ber_extension = 1;
		if (name_file[i - 1] == 'r' && name_file[i - 2] == 'e'
			&& name_file[i - 3] == 'b' && name_file[i - 4] == '.'
			&& name_file[i - 5] == '/')
			e.empty_name_map = 1;
	}
	return (e);
}
