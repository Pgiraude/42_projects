/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:05:07 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 18:04:41 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t size)
{
	int *ptr;

	ptr = 
}

int main(void)
{
	int A[] = {10, 11, 12, 13, 14};
	int i;

	i = 0;
	while (i <= 4)
	{
		printf("%d ", A[i]);
		i++;
	}

	printf( "\n\n" );
	memset(A, 0, 12);

	i = 0;
	while (i <= 4)
	{
		printf("%d ", A[i]);
		i++;
	}

}
