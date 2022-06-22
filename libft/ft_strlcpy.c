/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:18:25 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/22 21:10:17 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d;

	i = 0;
	while (dst[i])
		i++;
	d = i;
	i = 0;
	while (i <= (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (size > d)
	{
		dst[i] = '\0';
	}
	return (i);
}
