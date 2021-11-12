# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 17:03:51 by wiozsert          #+#    #+#              #
#    Updated: 2021/11/12 18:26:08 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror

# FILESC = so_long.c \
# check_all_errors.c cross_map.c file_errors.c init_get_check_map.c \
# map_errors_utils.c map_errors.c utils.c engine_destroyer.c map_sprites.c \
# first_sprites_init.c catch_key_and_move_player.c move_up_event.c \
# move_down_event.c move_left_event.c move_right_event.c
# FILESO := $(addprefix $(BUILDDIR)/,$(SOURCES:%.c=%.o))
FILESC = $(shell find ./srcs -type f)
FILESO = 


MLXINC = ./mlx/mlx.h

all : $(NAME)

$(NAME) :
	mkdir -p obj
	@make -C ./libft
	mv ./libft/%.o ./libft/%.a ./obj
	mv ./libft/libft.a .

# @cd mlx && make all && mv libmlx.a .. && make clean

# cc $(FLAGS) -c $(FILESC) $(MLXINC)
# ar - rcs so_long.a 

clean :
	rm -Rf ./obj

fclean : clean
	rm *.o

re : fclean all