/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <pgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:20:18 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/13 18:28:52 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char    *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if ( c == s[i])
        {
            return((char*)(s + i));
            /*
            fonctionne pas si je mets s[i] ou sans le char*
            */
        }
        i++;
    }
    if (s[i] == c)
    {
        return((char*)(s + i));
        // pour gerer le \0
    }
    return (NULL);
}

int main()
{
    char s[] = "\0 salut me";

    char *x;
    char *p;
    x = strchr(s, 0);

    printf("%s\n", x);

    p = ft_strchr(s, 0);
    printf("%s\n", p);
}