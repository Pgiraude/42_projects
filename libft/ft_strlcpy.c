/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <pgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/13 16:59:27 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int ft_strlcpy(char *dst, const char *src, size_t size)
{
    int i;
    int d;
    int s;

    i = 0;
    while (dst[i])
    {
        i++;
    }
    d = i;

    i = 0;
    while (src[i])
    {
        i++;
    }
    s = i;

    i = 0;
    while (i <= (size - 1))
    {
        dst[i] = src[i];
        i++;
    }
    if (size > d)
    {
        dst[i] = '\0';
    }
    return (i);
}

int main(void)
{
    char dst[] = "mec";
    char src[] = "gars";
    int i;

    size_t size = sizeof(char) * 4;

    ft_strlcpy(dst, src, size);

    i = 0; 
    while (dst[i])
    {
        printf("%c ", dst[i]);
        i++;
    }

    printf("\n");
    char dst1[] = "mec";
    char src1[] = "gars";

    strncpy(dst1, src1, size);
    i = 0;
    while (dst1[i])
    {
        printf("%c ", dst1[i]);
        i++;
    }
}