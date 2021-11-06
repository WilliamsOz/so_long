# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 17:24:12 by wiozsert          #+#    #+#              #
#    Updated: 2021/11/06 18:55:01 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror

#Libft
PATHLIBFT = ./libft/
LIBFTLIB = libft.a
LIBFTFILESC = get_next_line.c ft_strlen.c ft_putnbr.c ft_itoa.c
LIBFTFILESO = get_next_line.o ft_strlen.o ft_putnbr.o ft_itoa.o

#srcs
PATHSRCS = ./srcs/
PATHERROR = $(PATHSRCS)check_errors/
PATHUTILS = $(PATHSRCS)utils/
FILESC = so_long.c \
$(PATHERROR)check_all_errors.c $(PATHERROR)map_errors.c \
$(PATHERROR)file_errors.c $(PATHERROR)init_get_check_map.c $(PATHUTILS)utils.c \
$(PATHERROR)cross_map.c
FILESO = check_all_errors.o map_errors.o file_errors.o init_get_check_map.o \
utils.o so_long.o cross_map.o

#mlx
PATHMLX = ./mlx/linux_OS/
MLXLIB = libmlx.a
MLXINC = ./mlx/linux_OS/mlx.h

all : $(NAME)

$(NAME) :
	cd ./libft && make all && mv $(LIBFTFILESO) $(LIBFTLIB) ..
	
#cd $(PATHMLX) && make all && mv $(MLXLIB) *.o ..

	cc $(FLAGS) -c $(FILESC)

	cc $(FLAGS) $(FILESO) $(LIBFTLIB) -o $(NAME)

clean :
	rm -rf *.o *.a

fclean : clean
	rm -rf $(NAME)

re : fclean all
















#make bonus
#sed -i 's/# define BONUS 0/# define BONUS 1/g' ./inc/so_long.h

#make all
#sed -i 's/# define BONUS 1/# define BONUS 0/g' ./inc/so_long.h

# :%.o tout les point o :%.c