/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:50:07 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/21 16:17:41 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	if (!c)
		return (0);
	i = 0;
	while (c[i])
	{
		i++;
	}
	return (i);
}
