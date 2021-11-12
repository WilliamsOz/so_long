/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:43:43 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/12 16:48:52 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lst_clear(t_monster_position *data)
{
	t_monster_position	*tmp;

	tmp = data;
	while (tmp != NULL)
	{
		data = data->next;
		free(tmp);
		tmp = NULL;
		tmp = data;
	}
	data = NULL;
}
