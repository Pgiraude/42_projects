/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:18:00 by pgiraude          #+#    #+#             */
/*   Updated: 2022/07/02 19:45:42 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*ptr_src;
	char		*ptr_dest;
	size_t		i;

	if (!dest || !src)
		return (NULL);
	ptr_dest = dest;
	ptr_src = src;
	if (dest > src)
	{
		while (n > 0)
		{
			ptr_dest[n - 1] = ptr_src[n - 1];
			n--;
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			ptr_dest[i] = ptr_src[i];
	}
	return (dest);
}
