/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:20:52 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 21:20:55 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
    int l;

    l = 0;
    while(s[l])
    {
        l++;
    }

    while (l >= 0)
    {
        printf("T\n");
        if ( c == s[l])
        {
            return((char*)(s + l));
            /*
            fonctionne pas si je mets s[i] ou sans le char*
            */
        }
        l--;
    }
    printf("P\n");

    return (NULL);
}

int main()
{
    char s[] = "salut me";

    char *x;
    char *p;
   x = strrchr(s, 0);

   printf("%s\n", x);

    p = ft_strrchr(s, 0);
   printf("%s\n", p);
}
