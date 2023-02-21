/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:57:58 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/21 18:50:46 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Bool is_arg_error(int argc, char **argv)
{
    int x;
    int y;
    long long int   data;

    x = 1;
    while (x < argc)
    {  
        y = 0;
        if (argv[x][y] == '-')
            y++;
        while (argv[x][y])
        {
            if (!(argv[x][y] >= '0' && argv[x][y] <= '9'))
                return (true);
            y++;
        }
        data = ft_atoi(argv[x]);
        if (data > INT_MAX || data < INT_MIN)
            return (true);
        x++;
    }
    
    return (false);
}