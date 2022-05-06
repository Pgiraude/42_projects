/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:53:06 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/04 17:04:39 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>


int ft_isalpha(unsigned char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1024);
	}
	else
	{
		return (0);
	}
}

int main(void)
{
	unsigned char c = 'b';
	int x;


	x = isalpha(c);
	printf("original = %d\n", x);

	x = ft_isalpha(c);
	printf("ft = %d", x);
	
}
