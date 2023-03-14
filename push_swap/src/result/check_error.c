/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:57:58 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 13:30:57 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

e_bool	check_arg(char *argv)
{
	int	i;

	i = 0;
	if (ft_strlen(argv) > 11)
		return (true);
	if (argv[i] == '-')
		i++;
	if (argv[i] == '0' && argv[i + 1] != '\0')
		return (true);
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (true);
		i++;
	}
	return (false);
}

e_bool	check_double(int *tab_data, int len)
{
	int	x;
	int	y;

	x = 0;
	while (x < (len - 1))
	{
		y = x + 1;
		while (y < len)
		{
			if (tab_data[x] == tab_data[y])
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}

int	*get_number(int argc, char **argv, int len)
{
	int	*tab_data;
	int	data;
	int	i;

	tab_data = malloc(sizeof(int) * (len + 1));
	if (!tab_data)
		return (NULL);
	i = 0;
	while ((i + 1) < argc)
	{
		data = ft_atoi(argv[i + 1]);
		tab_data[i] = data;
		i++;
	}
	tab_data[i] = '\0';
	return (tab_data);
}

e_bool	is_error(int argc, char **argv)
{
	long long int	data;
	int				*tab_data;
	int				i;

	if (argc < 3)
		return (true);
	i = 0;
	while ((i + 1) < argc)
	{
		if (check_arg(argv[i + 1]) == true)
			return (true);
		data = ft_atoi(argv[i + 1]);
		if (data > INT_MAX || data < INT_MIN)
			return (true);
		i++;
	}
	tab_data = get_number(argc, argv, i);
	if (check_double(tab_data, i))
		return (free (tab_data), true);
	return (false);
}
