/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:03:56 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/06 15:14:15 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin_dup(char const *str_to_dup, char *str)
{
	int	i;

	i = 0;
	if (str_to_dup == NULL)
		return (str + i);
	while (str_to_dup[i])
	{
		str[i] = str_to_dup[i];
		i++;
	}
	return (str + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*str_index;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str_index = ft_strjoin_dup(s1, str);
	str_index = ft_strjoin_dup(s2, str_index);
	str_index[0] = '\0';
	return (str);
}
