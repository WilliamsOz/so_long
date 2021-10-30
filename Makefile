# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 18:14:21 by wiozsert          #+#    #+#              #
#    Updated: 2021/10/29 03:17:03 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
LIBFTFILESO = get_next_line.o ft_strlen.o
PATHSRCS = ./srcs/
PATHUTILS = ./srcs/utils/
PATHCHKERR = ./srcs/check_errors/
FILESC = $(PATHSRCS)so_long.c $(PATHUTILS)utils.c $(PATHCHKERR)check_errors.c \
$(PATHCHKERR)opening_errors.c $(PATHCHKERR)map_format_errors.c \
$(PATHCHKERR)check_map_errors.c $(PATHUTILS)get_map.c \
$(PATHCHKERR)file_errors.c $(PATHCHKERR)map_errors.c \
$(PATHCHKERR)check_map_errors_tools.c
FILESO = so_long.o get_next_line.o ft_strlen.o check_errors.o utils.o \
opening_errors.o map_format_errors.o check_map_errors.o get_map.o \
file_errors.o map_errors.o check_map_errors_tools.o
ALLOBJ = $(FILESO)

all : $(NAME)

$(NAME) :
	rm -Rf obj && mkdir obj
	cd ./libft/ && make all && mv $(LIBFTFILESO) libft.a ..
	cc $(FLAGS) -c $(FILESC) -I
	cc $(FLAGS) libft.a $(ALLOBJ) -o $(NAME)
	mv $(FILESO) libft.a ./obj

clean :
	rm -rf ./obj libft.a

fclean : clean
	rm -rf $(NAME)

re : fclean all

# bonus :