/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:24:03 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 21:24:08 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;

    ptr = malloc(nmemb * size);
    if (!ptr)
        return (NULL);

    size_t i;

    i = 0;
    while (i < size)
    {
        ptr[i] = \0;
        i++;
    }
    return (ptr);
    
}

int	main(void)
{
    char *p;

	p = calloc(4, 1);
	printf("original %i %i %i %i \n", p[0], p[1], p[2], p[3]);


	p = ft_calloc(4, 1);
	printf("%i %i %i %i \n", p[0], p[1], p[2], p[3]);


}