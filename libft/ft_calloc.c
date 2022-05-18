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

void *ft_calloc(size_t nmemb, size_t sizeofby)
{
    char *ptr;

    ptr = malloc(nmemb * sizeofby);
    if (!ptr)
        return (NULL);

    size_t i;

    i = 0;
    while (i < (sizeofby * nmemb))
    {
        ptr[i] = '\0';
        i++;
    }
    return (ptr);
    
}

int	main(void)
{
    int *p;
    int i;

	p = calloc(4, 4);

    	printf("%i %i %i %i original\n", p[0], p[1], p[2], p[3]);


	p = ft_calloc(4, 4);

    i = 0;
    while(p[i])
    {
    	printf("%i test\n", p[i]);
        i++;
    }


}