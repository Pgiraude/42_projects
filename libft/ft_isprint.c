/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:33:46 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 16:49:24 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_isprint(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	else
		return (0);
}

int main(void)
{
	unsigned char c = -1;
	int x;

	x = isprint(c);
	printf("original %d\n", x);

	x = ft_isprint(c);
	printf("test %d", x);

}
