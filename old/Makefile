# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 17:24:12 by wiozsert          #+#    #+#              #
#    Updated: 2021/11/12 18:16:41 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror

#Libft
PATHLIBFT = ./libft/
LIBFTLIB = libft.a
LIBFTFILESC = get_next_line.c ft_strlen.c ft_putnbr.c ft_itoa.c ft_strcmp.c \
ft_lst_clear.c
LIBFTFILESO = get_next_line.o ft_strlen.o ft_putnbr.o ft_itoa.o ft_strcmp.o \
ft_lst_clear.o

#srcs
PATHSRCS = ./srcs/
PATHERROR = $(PATHSRCS)check_errors/
PATHUTILS = $(PATHSRCS)utils/
PATHDSTROYER = $(PATHSRCS)engine_destroyer/
PATHGETSPRITES = $(PATHSRCS)get_sprites/
PATHEVENTS = $(PATHSRCS)events/
FILESC = so_long.c \
$(PATHERROR)check_all_errors.c $(PATHERROR)cross_map.c \
$(PATHERROR)file_errors.c $(PATHERROR)init_get_check_map.c \
$(PATHERROR)map_errors_utils.c $(PATHERROR)map_errors.c $(PATHUTILS)utils.c \
$(PATHDSTROYER)engine_destroyer.c $(PATHGETSPRITES)map_sprites.c \
$(PATHGETSPRITES)first_sprites_init.c \
$(PATHEVENTS)catch_key_and_move_player.c $(PATHEVENTS)move_up_event.c \
$(PATHEVENTS)move_down_event.c $(PATHEVENTS)move_left_event.c \
$(PATHEVENTS)move_right_event.c
FILESO = so_long.o \
check_all_errors.o cross_map.o file_errors.o init_get_check_map.o \
map_errors_utils.o map_errors.o utils.o engine_destroyer.o map_sprites.o \
first_sprites_init.o catch_key_and_move_player.o \
move_up_event.o move_down_event.o move_left_event.o move_right_event.o
SOLONGLIB = so_long.a

#mlx
PATHMLX = ./mlx/linux_OS/
MLXLIB = libmlx_Linux.a
MLXINC = $(PATHMLX)mlx.h
MLXFLAGS = -lm -lX11 -lXext
MLXFILESO = obj

#bonus
PATHBONUS = $(PATHSRCS)bonus/
BONUSFILESC = $(PATHBONUS)print_counter_bonus.c \
$(PATHBONUS)monster_bonus_sprite.c $(PATHBONUS)monster_patrol.c \
$(PATHBONUS)sprite_animation.c $(PATHBONUS)get_position_monster_bonus.c \
$(PATHBONUS)move_monster.c
BONUSFILESO = print_counter_bonus.o monster_bonus_sprite.o monster_patrol.o \
sprite_animation.o get_position_monster_bonus.o move_monster.o

all : $(NAME)

$(NAME) :
	sed -i 's/# define BONUS 1/# define BONUS 0/g' ./inc/so_long.h

	rm -Rf obj

	cd ./libft && make all && mv $(LIBFTLIB) .. && rm $(LIBFTFILESO)

	cd $(PATHMLX) && make all && mv $(MLXLIB) ../.. && rm -rf $(MLXFILESO)

	cc $(FLAGS) -c $(FILESC) $(MLXINC)

	ar -rcs $(SOLONGLIB) $(FILESO)

	mkdir obj && mv $(FILESO) ./obj/

	cc $(FLAGS) $(SOLONGLIB) $(LIBFTLIB) $(MLXLIB) $(MLXFLAGS) -o $(NAME)

	mv $(LIBFTLIB) $(MLXLIB) $(SOLONGLIB) ./obj/

clean :
	rm -rf ./obj $(SOLONGLIB) $(LIBFTLIB) $(MLXFILESO) $(MLXLIB) $(FILESO) \
	$(BONUSFILESO)

	cd $(PATHLIBFT) && make clean

	cd $(PATHMLX) && make clean

fclean : clean
	rm -rf $(NAME)

re : fclean all

make bonus :
	sed -i 's/# define BONUS 0/# define BONUS 1/g' ./inc/so_long.h

	rm -Rf obj

	cd ./libft && make all && mv $(LIBFTLIB) .. && rm $(LIBFTFILESO)

	cd $(PATHMLX) && make all && mv $(MLXLIB) ../.. && rm -rf $(MLXFILESO)

	cc $(FLAGS) -c $(FILESC) $(BONUSFILESC) $(MLXINC)

	ar -rcs $(SOLONGLIB) $(FILESO) $(BONUSFILESO)

	mkdir obj && mv $(FILESO) $(BONUSFILESO) ./obj/

	cc $(FLAGS) $(SOLONGLIB) $(LIBFTLIB) $(MLXLIB) $(MLXFLAGS) -o $(NAME)

	mv $(LIBFTLIB) $(MLXLIB) $(SOLONGLIB) ./obj/