/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:57:58 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/16 19:18:50 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_str_values(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free (values[i]);
		i++;
	}
	free (values);
}

t_bool	check_arg(char *val)
{
	int	i;

	i = 0;
	if (ft_strlen(val) > 11)
		return (true);
	if ((val[i] == '-' && val[i + 1] == '0')
		|| (val[i] == '-' && val[i + 1] == '\0'))
		return (true);
	if (val[i] == '0' && val[i + 1] != '\0')
		return (true);
	if (val[i] == '-')
		i++;
	while (val[i])
	{
		if (!(val[i] >= '0' && val[i] <= '9'))
			return (true);
		i++;
	}
	return (false);
}

t_bool	check_double(int *tab_data, int len)
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

int	*get_number(char **char_values, int len)
{
	long long int	data;
	int				*tab_data;
	int				i;

	tab_data = malloc(sizeof(int) * (len + 1));
	if (!tab_data)
		return (NULL);
	i = 0;
	while (char_values[i])
	{
		data = ft_atoi(char_values[i]);
		if (data > INT_MAX || data < INT_MIN)
			return (free (tab_data), NULL);
		tab_data[i] = data;
		i++;
	}
	tab_data[i] = '\0';
	return (tab_data);
}

t_bool	is_error(char **str_values, int **values)
{
	int				i;

	i = 0;
	while (str_values[i])
	{
		if (check_arg(str_values[i]) == true)
			return (true);
		i++;
	}
	*values = get_number(str_values, i);
	if (*values == NULL)
		return (true);
	else if (check_double(*values, i))
		return (free (*values), true);
	return (false);
}
