/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:23:09 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 21:23:17 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    int i;
    int j;

    if (!little[0])
    {
        printf("PP");
        return ((char*)big);
    }
    i = 0;
    while (big[i] && i < len)
    {
        j = 0;
        while (big[i + j] == little[j] && (i + j) < len)
        {
            j++;
            if (!little[j])
            {
                return ((char*)big + i);
            }
        }
        i++;
    }
    return (NULL);
}

int main(void)
{
    char s1[] = "salut manccc";
    char s2[] = "";

    char *x;
    char *y;
    int i = 0;

    x = strstr(s1, s2);

    while (x[i])
    {
        printf("%d original\n", x[i]);
        i++;
    }

    x = ft_strnstr(s1, s2, 11);

    i = 0;

    while (x[i])
    {
        printf("%d test\n", x[i]);
        i++;
    }
}
