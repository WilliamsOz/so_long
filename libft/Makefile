# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 14:45:54 by user42            #+#    #+#              #
#    Updated: 2021/11/14 12:26:06 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FILESC = get_next_line.c ft_strlen.c ft_putnbr.c ft_itoa.c ft_strcmp.c \
ft_lst_clear.c
FILESO = get_next_line.o ft_strlen.o ft_putnbr.o ft_itoa.o ft_strcmp.o \
ft_lst_clear.o

all : $(NAME)

$(NAME) :
	@cc $(FLAGS) -c $(FILESC)
	@ar -rcs $(NAME) $(FILESO)

clean :
	@rm -rf $(FILESO)

fclean : clean
	@rm -rf $(NAME)

re : fclean all