/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 21:20:18 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/20 22:00:30 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == c)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
