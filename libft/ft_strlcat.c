/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:18:55 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/20 22:09:27 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    int i;
    int len_dst;
    i = 0;
    while (dst[i])
    {
        i++;
    }
    len_dst = i;

    int len_src;
    i = 0;
    while (src[i])
    {
        i++;
    }
    len_src = i;

    i = 0;
    while (i <= (size - 1))
    {
        dst[len_dst + i] = src[i];
        i++;
    }
    dst[len_dst + i] = '\0';
    return (len_dst + i);

}

int main(void)
{
    char dst[] = "papa";
    char src[] = "lolo";
    int i;

    size_t size = sizeof(char) * 2;

    ft_strlcat(dst, src, size);

    i = 0;
    while (dst[i])
    {
        printf("%c ", dst[i]);
        i++;
    }

    printf("\n");
    char dst1[] = "papa";
    char src1[] = "lolo";

    strncat(dst1, src1, size);
    i = 0;
    while (dst1[i])
    {
        printf("%c ", dst1[i]);
        i++;
    }
}
/*
Pb avec src = \0
*/