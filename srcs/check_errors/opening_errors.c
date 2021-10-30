/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:36:56 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/28 22:36:19 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_maperr	check_opening_file(char *file, t_maperr error, int fd)
{
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error.file_exist = 1;
	else
		close (fd);
	fd = open(file, O_NOFOLLOW);
	if (fd == -1)
		error.is_symlink = 1;
	else
		close(fd);
	fd = open(file, O_DIRECTORY);
	if (fd != -1)
		error.is_directory = 1;
	else
		close(fd);
	return (error);
}
