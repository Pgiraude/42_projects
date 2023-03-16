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

	str_values = NULL;
	str_values = get_values(argc, argv);
	if (str_values == NULL)
	{
		return (EXIT_FAILURE);
	}
	if (is_error(str_values) == true)
	{
		free_str_values(str_values);
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	all = malloc(sizeof(*all));
	if (!all)
		return (EXIT_FAILURE);
	push_swap(all, str_values);
	ft_print_allmove(all->move);
	free_str_values(str_values);
	free_all_list(all->list_a);
	free_all_list(all->list_b);
	free_all_list(all->move);
	free(all);
}
