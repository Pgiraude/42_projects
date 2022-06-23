/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 19:38:35 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/23 19:39:32 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_set_check(char const *s1, char const *set, int i)
{
	int	j;

	j = 0;
	while (set[j] == s1[i])
	{
		j++;
		i++;
		if (!set[j])
			return (1);
	}
	return (0);
}

int	ft_strlen_tr(char const *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len_s1;
	int		len_set;
	char	*str;
	int		i;

	len_s1 = ft_strlen_tr(s1);
	len_set = ft_strlen_tr(set);
	start = 0;
	if (ft_set_check(s1, set, 0))
		start = len_set;
	if (ft_set_check(s1, set, (len_s1 - len_set)))
		len_s1 = len_s1 - len_set;
	str = malloc(sizeof(char) * (len_s1 - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < (len_s1 - start))
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
