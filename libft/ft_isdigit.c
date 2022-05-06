/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:10:14 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/04 17:26:35 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int ft_isdigit(unsigned char c)
{
	if (c >= '0' && c <= '9')
	{
		return(10);
	}
	else
		return(0);
}

int	main(void)
{
	unsigned char c = 'a';
	int x;

	x = isdigit(c);
	printf("original %d\n", x);

	x = ft_isdigit(c);
	printf("test %d\n", x);
}
