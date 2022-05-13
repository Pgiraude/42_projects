/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <pgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:19:47 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/13 17:53:24 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ctype.h>
#include <stdio.h>

int ft_tolower(int c)
{
    if ( c >= 'A' && c <= 'Z')
    {
        c = c + 32;
    }
    return(c);
}

int main(void)
{
    char test = 'Z';
    int p;

    p = ft_tolower(test);

    int i;
    i = 0;
    printf("%c", p);
}
