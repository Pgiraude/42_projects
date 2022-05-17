/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:23:33 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 21:23:36 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

int ft_atoi(const char *nptr)
{
    int i;
    int sign;
    long long int nb;

    sign = 1;
    nb = 0;
    i = 0;
    while (nptr[i] == ' ' || nptr[i] == 9)
    {
        i++;
    }
    if (nptr[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (nptr[i] == '+')
    {
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        nb = (nptr[i] - 48) + nb * 10;
        i++;
    }
    return (nb * sign);
}

int main(void)
{
    char s[] = "     12345";

    int x;

    x = atoi(s);
    printf("original : %d\n", x);

    x = ft_atoi(s);
    printf("test     : %d\n", x);
}