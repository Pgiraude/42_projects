/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 13:48:09 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_ctrl	*all;

	if (argc == 1)
		return (EXIT_FAILURE);
	else if (is_error(argc, argv) == true)
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	all = malloc(sizeof(*all));
	if (!all)
		return (EXIT_FAILURE);
	push_swap(all, argc, argv);
	/*---type move---*/
	ft_printf("after algo =\n");
	ft_printpiles(all->list_a, all->list_b);
	ft_printf("\n------\n");
	/*---type move---*/

	ft_printf("sol = ");
	ft_print_allmove(all->move);


	free_all_list(all->list_a);
	free_all_list(all->list_b);
	free_all_list(all->move);
	free(all);
}