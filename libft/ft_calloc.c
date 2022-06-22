/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:24:03 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/22 21:06:46 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t sizeofby)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nmemb * sizeofby);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (sizeofby * nmemb))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
