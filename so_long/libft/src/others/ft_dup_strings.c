/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:56:11 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/28 19:37:52 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_dup_strings(char **tab_str)
{
	int		i;
	char	**new_tab;

	i = 0;
	new_tab = NULL;
	if (!tab_str)
		return (NULL);
	while (tab_str[i])
		i++;
	new_tab = malloc(sizeof(char *) * (i + 1));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (tab_str[i])
	{
		new_tab[i] = ft_strdup(tab_str[i]);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}
