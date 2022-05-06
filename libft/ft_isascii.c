/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:11:20 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 16:32:54 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int ft_isascii(unsigned char c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int main(void)
{
	unsigned char c = -1;
	int x;

	x = isascii(c);
	printf("origin %d\n", x);

	x = ft_isascii(c);
	printf("test %d", x);

}
	
