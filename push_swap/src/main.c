/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/16 20:00:29 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_ctrl	*all;
	char	**str_values;
	int		*values;

	values = NULL;
	str_values = NULL;
	str_values = get_values(argc, argv);
	printf("test\n");
	if (str_values[0] == 0)
		printf("test1\n");
	int i;
	i = 0;
	printf("test2\n");
	while (str_values[i])
	{
		printf("[%s] ", str_values[i]);
		i++;
	}
	
	if (str_values[0] == 0)
		return (EXIT_FAILURE);
	if (is_error(str_values, &values) == true)
	{
		free_str_values(str_values);
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	free_str_values(str_values);
	all = malloc(sizeof(*all));
	if (!all)
		return (EXIT_FAILURE);
	push_swap(all, values);
	free (values);
	ft_print_allmove(all->move);
	free_all_list(all->list_a);
	free_all_list(all->list_b);
	free_all_list(all->move);
	free(all);
}
