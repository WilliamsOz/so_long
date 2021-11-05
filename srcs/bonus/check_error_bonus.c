/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:37:45 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/05 16:29:17 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	unvalid_char_bonus(char c)
{
	if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C' && c != 'M')
		return (1);
	return (0);
}

static t_maperr	check_map_bonus(char **map, t_maperr e, int x_max, int count)
{
	t_player	data;
	int			i;

	init_data(&data);
	while (count < x_max && e.is_valid_char == 0)
	{
		i = 0;
		if (map[count][i] == '\0' && i == 0)
			e.is_valid_char = 1;
		while (map[count][i] != '\0' && e.is_valid_char == 0)
		{
			if (unvalid_char_bonus(map[count][i]) == 1)
				e.is_valid_char = 1;
			data = get_data_of_map(map[count][i], data);
			i++;
		}
		count++;
	}
	e = is_data_valid(e, data);
	e = is_map_rectangle(map, e, 0, x_max - 1);
	if (e.map_is_not_rectangle == 0)
		e = is_map_closed(e, map, 0, x_max);
	return (e);
}

static int	check_errors_in_map_bonus(char ****map, char *file, t_maperr **e)
{
	int		fd;

	**map = NULL;
	fd = open(file, O_RDONLY);
	**map = init_map(**map, &e, fd, 0);
	close(fd);
	if (map_errors(**e, 1) == 1)
	{
		if (**map != NULL)
			free_map(**map, (*(*e)).x_max);
		return (1);
	}
	fd = open(file, O_RDONLY);
	**map = get_map(**map, fd, &e, 0);
	close (fd);
	**e = check_map_bonus(**map, **e, (*(*e)).x_max, 0);
	if (map_errors(**e, 0) == 1)
	{
		free_map(**map, (*(*e)).x_max);
		return (1);
	}
	return (0);
}

int	check_errors_bonus(char ***map, char **av, t_maperr *error)
{
	init_maperror(&error);
	*error = check_opening_file(av[1], *error, 0);
	if (file_errors(*error) == 1)
		return (1);
	*error = check_file(av[1], *error);
	if (file_errors(*error) == 1)
		return (1);
	if (check_errors_in_map_bonus(&map, av[1], &error) == 1)
		return (1);
	return (0);
}