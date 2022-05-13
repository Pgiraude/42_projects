/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <pgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:19:14 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/13 17:51:24 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_toupper(int c)
{
    if ( c >= 'a' && c <= 'z')
    {
        c = c - 32;
    }
    return(c);
}

int main(void)
{
    char test = 'z';
    int p;

    p = ft_toupper(test);

    int i;
    i = 0;
    printf("%c", p);
}
