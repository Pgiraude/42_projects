/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <pgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:21:26 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/13 18:39:36 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;

    i = 0;
    while ((s1[i] == s2[i]) && (n > 1) && s1[i] && s2[i])
    {
        printf("%ld \n", n);
        i++;
        n--;
    }
    return (s1[i] - s2[i]);
}

int main(void)
{
    char s1[] = "abcd";
    char s2[] = "abcde";
    int x;

    x = ft_strncmp(s1, s2, 10);
    printf("test %d\n", x);

    x = strncmp(s1, s2, 10);
    printf("%d", x);
}