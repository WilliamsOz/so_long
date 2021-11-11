/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:18:08 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/11 16:18:08 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

t_engine	*collectible_sprite_animation(t_engine *engine, int x, int y);
void		get_collectible_sprite_bonus(t_engine *engine, int i, int j,
				int y);
void		print_counter_bonus(t_engine *engine);
t_engine	*monster_patrol(t_engine *engine);
t_engine	*move_monster(t_engine *engine);
void		get_monster_sprite(t_engine *engine, int i, int j, int y);
t_engine	*get_monster_pos(t_engine *engine, int x, int y, int count);

#endif