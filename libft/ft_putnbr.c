/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:00:22 by wiozsert          #+#    #+#             */
/*   Updated: 2021/11/03 14:20:30 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static long	ft_intlen(long nbr)
{
	int		i;
	long	len;

	i = 1;
	len = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	while (--i > 0)
		len *= 10;
	return (len);
}

void	ft_putnbr(int n)
{
	char	res[10];
	long	nbr;
	int		i;
	long	cc;

	nbr = n;
	i = -1;
	cc = 0;
	while (++i < 10)
		res[i] = '\0';
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	i = 0;
	cc = ft_intlen(nbr);
	while (cc > 0)
	{
		res[i] = ('0' + ((nbr / cc) % 10));
		write(1, &res[i], 1);
		cc /= 10;
		i++;
	}
}
