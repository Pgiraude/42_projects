/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:16:37 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/16 20:03:52 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**create_tab_values(char **values, char **tmp)
{
	int		index_a;
	int		index_b;
	char	**new_values;

	if (values == NULL)
		return (tmp);
	index_a = 0;
	while (values[index_a])
		index_a++;
	index_b = 0;
	while (tmp[index_b])
		index_b++;
	new_values = malloc(sizeof(*new_values) * (index_a + index_b + 1));
	if (!new_values)
		return (NULL);
	index_a = -1;
	while (values[++index_a])
		new_values[index_a] = values[index_a];
	index_b = -1;
	while (tmp[++index_b])
		new_values[index_a + index_b] = tmp[index_b];
	new_values[index_a + index_b] = 0;
	return (free (values), free (tmp), new_values);
}

char	**get_values(int argc, char **argv)
{
	int		i;
	char	**tmp;
	char	**values;

	tmp = NULL;
	values = NULL;
	if (argc == 1)
		return (NULL);
	i = 0;
	while(argv[i + 1])
	{
		tmp = ft_split(argv[i + 1], ' ');
		values = create_tab_values(values, tmp);
		i++;
	}
	return (values);
}