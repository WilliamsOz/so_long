/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:04:21 by wiozsert          #+#    #+#             */
/*   Updated: 2021/10/29 03:16:38 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int ac, char **av)
{
    xd = 0;
    if (ac != 2)
        write(1, "Error\nThe number of arguments is not two\n", 41);
    else if (check_errors(av) == 1)
        return (0);
    else
        write(1, "c'est ok bg\n", 12);
    return (0);
}

// __attribute__((destructor))
// void    test() {
//     system("leaks so_long");
// }