/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:05:07 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/22 21:08:22 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
