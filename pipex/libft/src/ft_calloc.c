/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:24:03 by pgiraude          #+#    #+#             */
/*   Updated: 2022/07/13 18:39:46 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t sizeofby)
{
	void		*ptr;

	if (sizeofby == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > (SIZE_MAX / sizeofby))
		return (NULL);
	ptr = malloc(nmemb * sizeofby);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, (sizeofby * nmemb));
	return (ptr);
}
