/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:56:11 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/28 21:03:22 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_freestrings(char **tab_str)
{
	int	i;

	i = 0;
	if (!tab_str)
		return ;
	while (tab_str[i])
	{
		free (tab_str[i]);
		i++;
	}
	if (tab_str)
		free (tab_str);
}
