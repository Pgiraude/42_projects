/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 20:25:31 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 21:43:09 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	int i;

	while (i < n)
	{
		(char) s[i] = 0;
		i++;
	}
}

int	main(void)
{
	char t[] = {1, 2, 3, 4};

	size_t size = sizeof(char) * 4;

	ft_bzero(t, size);
	printf("%i\n", t[0]);
	printf("%i\n", t[1]);
}
