/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:05:07 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/20 21:50:12 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = s;
	i = 0;
	while (i < size)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (ptr);
}
