/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 14:43:23 by user42            #+#    #+#             */
/*   Updated: 2021/11/07 17:55:46 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*get_first_read(char *line, char *buffer)
{
	line = (char *)malloc(sizeof(char) * 2);
	if (line == NULL)
		return (NULL);
	line[0] = buffer[0];
	line[1] = '\0';
	return (line);
}

char	*get_next_reads(char *line, char *buffer)
{
	char	*tmp;
	int		len;
	int		i;

	tmp = line;
	len = ft_strlen(line);
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (line == NULL)
		return (NULL);
	line[len] = buffer[0];
	line[len + 1] = '\0';
	i = 0;
	while (tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	char	buffer[1];
	int		eof;

	eof = read(fd, buffer, 1);
	if (buffer[0] == '\n' || eof == 0)
		return (eof);
	if (eof > 0)
		*line = get_first_read(*line, buffer);
	if (*line == NULL && eof > 0)
		return (-1);
	while (eof > 0 && buffer[0] != '\n')
	{
		eof = read(fd, buffer, 1);
		if (buffer[0] == '\n' || eof == 0)
			return (eof);
		*line = get_next_reads(*line, buffer);
		if (*line == NULL)
			return (-1);
	}
	return (eof);
}
