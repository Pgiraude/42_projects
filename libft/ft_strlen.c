/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:50:07 by pgiraude          #+#    #+#             */
/*   Updated: 2022/05/06 17:03:31 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int ft_strlen(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		i++;
	}
	printf("%d", i);
	return (i);
}

int main(void)
{
	char c[] = "aaaaaaaa";
	ft_strlen(c);
}
