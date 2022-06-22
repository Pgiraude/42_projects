/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:22:04 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/22 21:07:54 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;
	size_t					i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		if (c == ptr[i])
		{
			return ((void *)(ptr + i));
		}
		i++;
	}
	return (NULL);
}
