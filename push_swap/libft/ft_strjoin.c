/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:03:56 by pgiraude          #+#    #+#             */
/*   Updated: 2022/07/12 22:58:26 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;
	int		x;

	if (!s1 && !s2)
		return (NULL);
	x = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (x + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
			str[i + j] = s2[j];
			j++;
	}
	str[i + j] = '\0';
	return (str);
}
