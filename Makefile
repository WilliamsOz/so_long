# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 18:14:21 by wiozsert          #+#    #+#              #
#    Updated: 2021/11/05 19:30:19 by wiozsert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

PATHMLX = ./includes/mlx/mac_OS/ #

#libft
PATHLIBFT = ./libft/
LIBFTLIB = libft.a
LIBFTFILESC = get_next_line.c ft_strlen.c ft_putnbr.c ft_itoa.c
LIBFTFILESO = get_next_line.o ft_strlen.o ft_putnbr.o ft_itoa.o

#srcs
PATHSRCS = ./srcs/
PATHUTILS = ./srcs/utils/
PATHCHKERR = ./srcs/check_errors/
PATHGETSPT = ./srcs/get_sprite/
PATHMOVE = ./srcs/move_player/
FILESC = $(PATHUTILS)utils.c $(PATHCHKERR)check_errors.c \
$(PATHCHKERR)opening_errors.c $(PATHCHKERR)map_format_errors.c \
$(PATHCHKERR)check_map_errors.c $(PATHUTILS)get_map.c \
$(PATHCHKERR)file_errors.c $(PATHCHKERR)map_errors.c \
$(PATHCHKERR)check_map_errors_tools.c $(PATHGETSPT)get_map_sprite.c \
$(PATHGETSPT)get_char_sprite.c $(PATHMOVE)move_player.c \
$(PATHMOVE)print_move.c
FILESO = opening_errors.o map_format_errors.o check_map_errors.o get_map.o \
file_errors.o map_errors.o check_map_errors_tools.o get_map_sprite.o \
get_char_sprite.o move_player.o print_move.o check_errors.o utils.o

#get_next_line.o ft_strlen.o check_errors.o utils.o ft_putnbr.o

#bonus


#mlx
PATHLXMLX = ./includes/mlx/
PATHMLX = ./includes/
MLXLIB = libmlx.a
MLXINC = ./includes/mlx/
MLXMOVELXFILESO = 
MLXFILESO =
MOVEMLXMACOBJ =

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)

	PATHMLX = ./includes/mlx/linux_OS/
	FLAGS = -Wall -Wextra -Werror
	MLXLIB = libmlx_Linux.a
	MLXINC = $(PATHMLX)mlx.h
	MLXFILESO = mlx_clear_window.o mlx_destroy_display.o mlx_destroy_image.o \
	mlx_destroy_window.o mlx_expose_hook.o mlx_flush_event.o \
	mlx_get_color_value.o mlx_get_data_addr.o mlx_hook.o mlx_init.o \
	mlx_int_anti_resize_win.o mlx_int_do_nothing.o mlx_int_get_visual.o \
	mlx_int_param_event.o mlx_int_set_win_event_mask.o \
	mlx_int_str_to_wordtab.o mlx_int_wait_first_expose.o mlx_key_hook.o \
	mlx_loop_hook.o mlx_loop.o mlx_mouse_hook.o mlx_mouse.o \
	mlx_new_image.o mlx_new_window.o mlx_pixel_put.o \
	mlx_put_image_to_window.o mlx_rgb.o mlx_screen_size.o mlx_set_font.o \
	mlx_string_put.o mlx_xpm.o
	MLXMOVELXFILESO = cd obj && mv $(MLXFILESO) .. && cd .. && rm -Rf obj

else

	PATHMLX = ./includes/mlx/mac_OS
	FLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit
	MLXINC = $(PATHMLX)mlx.h
	MLXFILESO = mlx_init_loop.o mlx_int_str_to_wordtab.o mlx_mouse.o \
	mlx_new_image.o mlx_new_window.o mlx_png.o mlx_shaders.o mlx_xpm.o
	MOVEMLXMACOBJ = rm -Rf obj && mkdir obj && mv mlx_init_loop.o \
	mlx_int_str_to_wordtab.o mlx_mouse.o mlx_new_image.o mlx_new_window.o \
	mlx_png.o mlx_shaders.o mlx_xpm.o ./obj/
	MLXFILESO = mlx_init_loop.o mlx_int_str_to_wordtab.o mlx_mouse.o \
	mlx_new_image.o mlx_new_window.o mlx_png.o mlx_shaders.o mlx_xpm.o 

endif

all : $(NAME)

$(NAME) :
	@cd ./libft/ && make all && mv $(LIBFTFILESO) $(LIBFTLIB) ..

	@cd $(PATHMLX) && make all && $(MLXMOVELXFILESO) && \
	mv $(MLXLIB) $(MLXFILESO) ../../..

	@cc $(FLAGS) -c ./srcs/so_long.c \
	$(FILESC) $(MLXINC)
	
	@mkdir obj && mv $(MLXFILESO) $(LIBFTFILESO) ./obj
	
	@cc $(FLAGS) so_long.o $(FILESO) $(LIBFTLIB) $(MLXLIB) -lm -lX11 -lXext -o $(NAME)

	@mv $(FILESO) so_long.o libmlx_Linux.a libft.a ./obj

clean :
	@rm -rf ./obj $(MLXLIB) $(OBJANDBONUSOBJ) so_long.o \
	@so_long_bonus.o $(MLXFILESO) $(LIBFTLIB) $(LIBFTFILESO)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : fclean
	
# bonus : fclean
# 	cd ./libft/ && make all && mv $(LIBFTFILESO) libft.a ..
# 	cd ./includes/mlx/mac_OS && make all && mv libmlx.a $(MLXFILESO) ../../..
# 	rm -Rf obj && mkdir obj
# 	cc $(FLAGS) -c $(FILESCANDBONUS) ./includes/mlx/mac_OS/mlx.h
# 	cc $(FLAGS) $(OBJANDBONUSOBJ) libft.a libmlx.a \
# 	-framework OpenGL -framework AppKit -o $(NAME)
# 	mv $(MLXFILESO) ./obj