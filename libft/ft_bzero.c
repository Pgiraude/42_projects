/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:25:31 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/12 14:36:42 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t i;
	char *ptr;

	ptr = s;



	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

int	main(void)
{
	int t[] = {1, 2, 3, 4};
	int p[] = {1, 2, 3, 4};

	size_t size = sizeof(int) * 2;

	bzero(p, size);
	printf("original %i %i %i %i \n", p[0], p[1], p[2], p[3]);


	ft_bzero(t, size);
	printf("%i %i %i %i \n", t[0], t[1], t[2], t[3]);


}
