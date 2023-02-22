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

Bool    check_arg(char *argv)
{
    int i;

    i = 0;
    if (argv[i] == '-')
        i++;
    if (argv[i] == '0' && argv[i + 1] != '\0')
        return (true);
    while (argv[i])
    {
        if (!(argv[i] >= '0' && argv[i] <= '9'))
            return (true);
        i++;
    }
    return (false);
}

Bool    check_double(long long int *tab_data, int len)
{
    int x;
    int y;

    x = 0;
    while(x < (len - 1))
    {
        y = x + 1;
        while (y < len)
        {
            if (tab_data[x] == tab_data[y])
                return (true);
            y++;
        }
        x++;
    }
    return (false);
}

Bool    is_error(int argc, char **argv)
{
    long long int   tab_data[argc];
    long long int   data;
    int             i;

    if (argc < 3)
        return (true);
    i = 0;
    while ((i + 1) < argc)
    {  
        if (check_arg(argv[i + 1]))
            return (true);
        data = ft_atoi(argv[i + 1]);
        if (data > INT_MAX || data < INT_MIN)
            return (true);
        tab_data[i] = data;
        i++;
    }
    tab_data[i] = '\0';
    if (check_double(tab_data, i))
        return (true);
    return (false);
}
