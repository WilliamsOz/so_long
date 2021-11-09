# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 17:24:12 by wiozsert          #+#    #+#              #
#    Updated: 2021/11/09 23:10:06 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror #-ggdb3#-g3 -fsanitize=address

#Libft
PATHLIBFT = ./libft/
LIBFTLIB = libft.a
LIBFTFILESC = get_next_line.c ft_strlen.c ft_putnbr.c ft_itoa.c ft_strcmp.c
LIBFTFILESO = get_next_line.o ft_strlen.o ft_putnbr.o ft_itoa.o ft_strcmp.o

#srcs
PATHSRCS = ./srcs/
PATHERROR = $(PATHSRCS)check_errors/
PATHUTILS = $(PATHSRCS)utils/
PATHDSTROYER = $(PATHSRCS)engine_destroyer/
PATHGETSPRITES = $(PATHSRCS)get_sprites/
FILESC = so_long.c \
$(PATHERROR)check_all_errors.c $(PATHERROR)cross_map.c \
$(PATHERROR)file_errors.c $(PATHERROR)init_get_check_map.c \
$(PATHERROR)map_errors_utils.c $(PATHERROR)map_errors.c $(PATHUTILS)utils.c \
$(PATHDSTROYER)engine_destroyer.c $(PATHGETSPRITES)map_sprites.c \
$(PATHGETSPRITES)monster_bonus_sprite.c $(PATHGETSPRITES)first_sprites_init.c
SOLONGLIB = so_long.a

FILESO = so_long.o \
check_all_errors.o cross_map.o file_errors.o init_get_check_map.o \
map_errors_utils.o map_errors.o utils.o engine_destroyer.o map_sprites.o \
monster_bonus_sprite.o first_sprites_init.o

#mlx
PATHMLX =
MLXLIB =
MLXINC =
MLXFLAGS =
MLXFILESO =

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)

	PATHMLX = ./mlx/linux_OS/
	MLXLIB = libmlx_Linux.a
	MLXINC = $(PATHMLX)mlx.h
	MLXFLAGS = -lm -lX11 -lXext
	MLXFILESO = obj
#mlx_clear_window.o mlx_destroy_display.o mlx_destroy_image.o \
	mlx_destroy_window.o mlx_expose_hook.o mlx_flush_event.o \
	mlx_get_color_value.o mlx_get_data_addr.o mlx_hook.o mlx_init.o \
	mlx_int_anti_resize_win.o mlx_int_do_nothing.o mlx_int_get_visual.o \
	mlx_int_param_event.o mlx_int_set_win_event_mask.o \
	mlx_int_str_to_wordtab.o mlx_int_wait_first_expose.o mlx_key_hook.o \
	mlx_loop_hook.o mlx_loop.o mlx_mouse_hook.o mlx_mouse.o \
	mlx_new_image.o mlx_new_window.o mlx_pixel_put.o \
	mlx_put_image_to_window.o mlx_rgb.o mlx_screen_size.o mlx_set_font.o \
	mlx_string_put.o mlx_xpm.o

else

	PATHMLX = ./includes/mlx/mac_OS/
	MLXFLAGS = -framework OpenGL -framework AppKit
	MLXINC = $(PATHMLX)mlx.h
	MLXFILESO = mlx_init_loop.o mlx_int_str_to_wordtab.o mlx_mouse.o \
	mlx_new_image.o mlx_new_window.o mlx_png.o mlx_shaders.o mlx_xpm.o	
	
endif

make test :
	rm -Rf obj

	cc $(FLAGS) -c $(FILESC) $(MLXINC)

	ar -rcs $(SOLONGLIB) $(FILESO)

	cc $(FLAGS) $(SOLONGLIB) $(LIBFTLIB) $(MLXLIB) $(MLXFLAGS) -o $(NAME)

	rm -Rf obj && mkdir obj && mv $(FILESO) ./obj/

all : $(NAME)

$(NAME) :
	rm -Rf obj

	cd ./libft && make all && mv $(LIBFTLIB) .. && rm $(LIBFTFILESO)

	cd $(PATHMLX) && make all && mv $(MLXLIB) ../.. && rm -rf $(MLXFILESO)

	cc $(FLAGS) -c $(FILESC) $(MLXINC)

	ar -rcs $(SOLONGLIB) $(FILESO)

	cc $(FLAGS) $(SOLONGLIB) $(LIBFTLIB) $(MLXLIB) $(MLXFLAGS) -o $(NAME)

	rm -Rf obj && mkdir obj && mv $(FILESO) ./obj/
	cc $(FLAGS) $(SOLONGLIB) $(LIBFTLIB) $(MLXLIB) $(MLXFLAGS) -o $(NAME)

	rm -Rf obj && mkdir obj && mv $(FILESO)
clean :
	rm -rf ./obj $(SOLONGLIB) $(LIBFTLIB) $(MLXFILESO) $(MLXLIB)

	cd $(PATHLIBFT) && make clean

	cd $(PATHMLX) && make clean

fclean : clean
	rm -rf $(NAME)

re : fclean all

make bonus :
	sed -i 's/# define BONUS 0/# define BONUS 1/g' ./inc/so_long.h

#make all
#sed -i 's/# define BONUS 1/# define BONUS 0/g' ./inc/so_long.h

# :%.o tout les point o :%.c