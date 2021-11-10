/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/11/10 12:16:00 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H


//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL
#include <stdio.h>
# define D printf("ICI\n");
# define PRINTD(x) printf("%d\n", x);
# define PRINTS(x) printf("%s\n", x);
# define PRINTC(x) printf("%c\n", x);
# define PRINTP(x) printf("%p\n", x);
# define ex exit(EXIT_FAILURE);
//DELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDELDEL

# include <stdlib.h>
# include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int n);
void	ft_putnbr(int n);
int		ft_strlen(char *str);
int		get_next_line(const int fd, char **line);

#endif