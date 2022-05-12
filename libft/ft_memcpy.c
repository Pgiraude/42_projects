/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:17:36 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/12 15:27:44 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *ptr_dest;
	char *ptr_src;
	size_t i;

	ptr_dest = dest;
	ptr_src = src;
	i = 0;
	while(i < n)
	{
		(char*) dest[i] = (char*) src[i];
		i++;
	}
	return (dest);
}

int	main(void)
{
	char a[] = {1, 2, 3};
	char dest[] = {11, 12, 13};
	char dest2[] = {111, 122, 133};


	size_t n = sizeof(char) * 3;

	memcpy(dest, a, n);

	printf("original %i %i %i \n", dest[0], dest[1], dest[2]);


	ft_memcpy(dest2, a, n);
	
	printf("original %i %i %i \n", dest2[0], dest2[1], dest2[2]);

}
