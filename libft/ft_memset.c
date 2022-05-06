/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:05:07 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 20:24:22 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t size)
{
	char *ptr;
	size_t i;

/*
ne marche pasavec un int *ptr
*/
	ptr = s;
	i = 0;

	while (i < size)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (ptr);

}

int main(void)
{
	char A[] = {100, 111, 12, 13, 14};
	int i;
	size_t size;

	size = sizeof(char) * 5;

	i = 0;
	while (i <= 4)
	{
		printf("%d ", A[i]);
		i++;
	}

	printf( "\n" );
	memset(A, 1, size);

	i = 0;
	while (i <= 4)
	{
		printf("%d ", A[i]);
		i++;
	}
	printf( "\n\n" );




	char B[] = {10, 11, 12, 13, 14};
	printf("size = %ld\n", size);

	ft_memset(B, 1, size);

	i = 0;
	while (i <= 4)
	{
		printf("%d ", B[i]);
		i++;
	}

	

}
