/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:23 by user42            #+#    #+#             */
/*   Updated: 2021/11/11 16:19:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_monster_position
{
	int							x;
	int							y;
	int							ind;
	struct s_monster_position	*next;
}				t_monster_position;

typedef struct s_map_data
{
	int			player;
	int			collectible;
	int			exit;
}				t_map_data;

typedef struct s_error
{
	int			no_file;
	int			fd;
	int			file_bad_format;
	int			malloc_fail;
	int			map_not_close;
	int			map_bad_format;
	int			unvalid_char;
	int			no_exit;
	int			no_collectible;
	int			no_player;
	int			too_many_player;
}				t_error;

typedef struct s_img
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bit_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_sprite
{
	char		*spr;
	int			spr_ind;
}				t_sprite;

typedef struct s_engine
{
	t_monster_position	*monster_position;
	int					collectible;
	int					player_pos_x;
	int					player_pos_y;
	int					move_count;
	char				keycode;
	t_img				*img;
	t_img				*sprite;
	t_error				*error;
	t_map_data			*data;
	char				**map;
	char				*spr;
	int					spr_ind;
}				t_engine;

void	ft_lst_clear(t_monster_position *data);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int n);
void	ft_putnbr(int n);
int		ft_strlen(char *str);
int		get_next_line(const int fd, char **line);

#endif