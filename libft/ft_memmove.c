/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:18:00 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/13 15:16:12 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char *ptr_src;
	char *ptr_dest;

	size_t i;

	ptr_dest = dest;
	ptr_src = src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

int main (void)
{
	char a[] = {1, 2, 3};
	char dest[] = {11, 12, 50};
	char dest2[] = {111, 75, 50};


	size_t n = sizeof(char) * 2;

	memmove(dest, a, n);

	printf("original %i %i %i \n", dest[0], dest[1], dest[2]);


	ft_memmove(dest2, dest2 + 1, 2);
	
	printf("test %i %i %i \n", dest2[0], dest2[1], dest2[2]);
}
