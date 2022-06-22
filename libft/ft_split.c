/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:55:24 by pgiraude          #+#    #+#             */
/*   Updated: 2022/06/22 21:09:13 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill(char const *x, char c, int i)
{
	int		len;
	char	*str;

	len = 0;
	while (x[i + len] != c && x[i + len])
	{
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	len = 0;
	while (x[i + len] != c && x[i + len])
	{
		str[len] = x[i + len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

int	ft_nb_split(char const *x, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (x[i] == c)
		i++;
	while (x[i])
	{
		if (x[i] == c)
		{
			count++;
			while (x[i] == c)
			{
				i++;
			}
		}
		else
		{
			i++;
			if (x[i] == '\0')
				count++;
		}
	}
	return (count);
}

char	**ft_split(char const *x, char c)
{
	char	**str;
	int		i;
	int		y;

	str = malloc(sizeof(char *) * (ft_nb_split(x, c) + 1));
	if (!str)
		return (NULL);
	y = 0;
	i = 0;
	while (x[i] == c)
		i++;
	while (x[i])
	{
		if (x[i] != c)
		{
			str[y] = ft_fill(x, c, i);
			y++;
			while (x[i] != c && x[i])
				i++;
		}
		else
			i++;
	}
	str[y] = '\0';
	return (str);
}
