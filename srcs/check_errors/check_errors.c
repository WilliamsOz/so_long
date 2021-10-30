/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:05:25 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/29 01:53:12 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int check_errors(char **av)
{
	t_maperr error;

	init_maperror(&error);
	error = check_opening_file(av[1], error, 0);
	if (file_errors(error) == 1)
		return (1);
	error = check_file(av[1], error);
	if (file_errors(error) == 1)
		return (1);
	if (check_errors_inside_map_file(av[1], error) == 1)
		return (1);
	return (0);
}
