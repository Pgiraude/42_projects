/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:24:29 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 21:24:31 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *s)
{
    int len;
    char *ptr;

    len = 0;
    while (s[len])
    {
        len++;
    }

    ptr = malloc(sizeof(char) * (len + 1));
    if (!ptr)
        return (NULL);

    int i;

    i = 0;
    while (s[i])
    {
        ptr[i] = s[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);

}

int main(void)
{
    char s[] = "salut";
    char *ptr;
    int i;

    ptr = strdup(s);
    i = 0;
    while (ptr[i])
    {
        printf("%i original\n", ptr[i]);
        i++;
    }

    ptr = ft_strdup(s);
    i = 0;
    while (ptr[i])
    {
        printf("%i test\n", ptr[i]);
        i++;
    }
}
