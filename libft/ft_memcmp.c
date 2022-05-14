/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:22:37 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 21:22:45 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *ptr1;
    const unsigned char *ptr2;
    size_t i;

    ptr1 = s1;
    ptr2 = s2;
    i = 0;
    while (ptr1[i] == ptr2[i] && n > 1)
    {
        printf("P\n");
        i++;
        n--;
    }
    return(ptr1[i] - ptr2[i]);

}

int main()
{
    char s1[] = {1, 2, 3, 5};
    char s2[] = {1, 2, 3, 4};
    size_t n = 4;

    int x;

    x = ft_memcmp(s1, s2, n);

    printf ("%d test\n", x);

    x = memcmp(s1, s2, n);

    printf ("%d orginal\n", x);
}

// pb quand on compare des char, 256 au lieu de 1