# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 17:03:51 by wiozsert          #+#    #+#              #
#    Updated: 2021/11/14 13:16:33 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lm -lX11 -lXext

#srcs
FILESC = ./srcs/so_long.c $(shell find ./srcs/mandatory/ -type f)
FILESO = so_long.o \
check_all_errors.o cross_map.o file_errors.o init_get_check_map.o \
map_errors_utils.o map_errors.o utils.o engine_destroyer.o map_sprites.o \
first_sprites_init.o catch_key_and_move_player.o move_up_event.o \
move_down_event.o move_left_event.o move_right_event.o

#libft
PATHLIBFT = ./libft/
LIBFTFILESC = $(addprefix $(PATHLIBFT), ft_itoa.c ft_lst_clear.c ft_putnbr.c \
ft_strcmp.c ft_strlen.c get_next_line.c)
LIBFTFILESO = $(addprefix $(PATHLIBFT), ft_itoa.o ft_lst_clear.o ft_putnbr.o \
ft_strcmp.o ft_strlen.o get_next_line.o)
LIBFTLIB = libft.a

#bonus
BONUSFILESC = $(shell find ./srcs/bonus/ -type f)
BONUSFILESO = get_position_monster_bonus.o monster_patrol_bonus.o \
move_monster_bonus.o print_counter_bonus.o sprite_animation_bonus.o \
monster_sprite_bonus.o

#mlx
MLXINC = ./mlx/mlx.h
MLXLIB = libmlx.a

all : $(NAME)

$(NAME) : $(FILESC) $(LIBFTFILESC)
	@sed -i 's/# define BONUS 1/# define BONUS 0/g' ./inc/so_long.h
	@mkdir -p obj
	@make -C ./libft
	@mv $(LIBFTFILESO) ./obj && mv ./libft/libft.a .
	@cd mlx && make all && mv $(MLXLIB) .. && make clean
	@cc $(FLAGS) -c $(FILESC) $(MLXINC)
	@cc $(FLAGS) $(FILESO) $(LIBFTLIB) $(MLXLIB) $(MLXFLAGS) -o $(NAME)
	@mv $(FILESO) $(MLXLIB) $(LIBFTLIB) ./obj

clean :
	@rm -Rf ./obj

fclean : clean
	@rm -Rf $(NAME)

re : fclean all

bonus :
	@sed -i 's/# define BONUS 0/# define BONUS 1/g' ./inc/so_long.h
	@mkdir -p obj
	@make -C ./libft
	@mv $(LIBFTFILESO) ./obj && mv ./libft/libft.a .
	@cd mlx && make all && mv $(MLXLIB) .. && make clean
	@cc $(FLAGS) -c $(FILESC) $(BONUSFILESC) $(MLXINC)
	@cc $(FLAGS) $(FILESO) $(BONUSFILESO) $(LIBFTLIB) $(MLXLIB) $(MLXFLAGS) -o $(NAME)
	@mv $(FILESO) $(BONUSFILESO) $(MLXLIB) $(LIBFTLIB) ./obj