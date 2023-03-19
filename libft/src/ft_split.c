/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:55:24 by pgiraude          #+#    #+#             */
/*   Updated: 2022/07/10 19:58:00 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_errornull(char **str, int i)
{
	while (i)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (NULL);
}

int	ft_count_word(char const *x, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (x[i])
	{
		while (x[i] == c)
			i++;
		if (x[i] != '\0')
		{
			count++;
			i++;
		}
		while (x[i] != c && x[i])
			i++;
	}
	return (count);
}

char	*the_word(char const *x, char c, int pos)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (x[pos + len] != c && x[pos + len])
	{
		len++;
	}
	word = malloc(sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = x[pos + i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

int	strlen_word(char const *x, char c, int i)
{
	int	pos;

	pos = 0;
	while (x[pos + i] != c && x[pos + i])
		pos++;
	while (x[pos + i] == c && x[pos + i])
		pos++;
	return (pos);
}

char	**ft_split(char const *x, char c)
{
	char	**tab;
	int		y;
	int		pos;
	int		nbr_word;

	nbr_word = ft_count_word(x, c);
	tab = malloc(sizeof(*tab) * (nbr_word + 1));
	if (!tab)
		return (NULL);
	y = 0;
	pos = 0;
	if (nbr_word > 0)
		while (x[pos] == c)
			pos++;
	while (y < nbr_word)
	{
		tab[y] = the_word(x, c, pos);
		if (tab[y] == NULL)
			return (ft_errornull(tab, y));
		pos = pos + strlen_word(x, c, pos);
		y++;
	}
	tab[nbr_word] = 0;
	return (tab);
}
