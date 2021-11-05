# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 14:45:54 by user42            #+#    #+#              #
#    Updated: 2021/11/04 19:32:18 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FILESC = get_next_line.c ft_strlen.c ft_putnbr.c ft_itoa.c
FILESO = get_next_line.o ft_strlen.o ft_putnbr.o ft_itoa.o

all : $(NAME)

$(NAME) :
	cc $(FLAGS) -c $(FILESC)
	ar -rcs $(NAME) $(FILESO)

clean :
	rm -rf $(FILESO) $(BONUSO)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus :	fclean
	cc $(FLAGS) -c $(FILESC) $(BONUSC)
	ar -rcs $(NAME) $(FILESO) $(BONUSO)