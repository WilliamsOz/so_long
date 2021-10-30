/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 22:32:24 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/28 23:03:55 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_file_errors(t_maperr e)
{
	if (e.file_exist == 1)
		write(1, "Map doesn't exist\n", 18);
	else if (e.is_symlink == 1)
		write(1, "Map file is a symlink\n", 22);
	else if (e.is_directory == 1)
		write(1, "Map is a directory\n", 19);
	else if (e.empty_name_map == 1)
		write(1, "Map name is not correct\n", 24);
	else if (e.not_ber_extension == 1)
		write(1, "Map extension is not corret\n", 28);
}

int	file_errors(t_maperr e)
{
	if (e.is_symlink == 1 || e.is_directory == 1 || e.file_exist == 1
		|| e.empty_name_map == 1 || e.not_ber_extension == 1)
	{
		write(1, "Error\n", 6);
		print_file_errors(e);
		return (1);
	}
	return (0);
}
