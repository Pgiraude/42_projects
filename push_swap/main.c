/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 18:42:34 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*move;
	t_ctrl	*all;
	int		i;

	if (is_error(argc, argv))
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	list_a = NULL;
	list_b = NULL;
	move = NULL;
	move = create_list(move);
	list_a = create_list(list_a);
	list_b = create_list(list_b);
	all = malloc(sizeof(*all));
	if (!all)
		return (EXIT_FAILURE);
	all->list_a = list_a;
	all->list_b = list_b;
	all->move = move;
	i = 1;
	while (i < argc)
	{
		list_a = insert_data_list(list_a, ft_atoi(argv[i]), 1);
		i++;
	}

	/*---print list---*/
	ft_printf("len A = %d le B = %d\n", list_a->len, list_b->len);
	ft_printpiles(list_a, list_b);
	/*---print list---*/

	ft_printf("\n------\n");
	/*---print solution---*/

	push_swap(all);

	/*---type move---*/
	ft_printf("after algo =\n");
	ft_printpiles(list_a, list_b);
	ft_printf("\n------\n");
	/*---type move---*/

	ft_printf("sol = ");
	ft_print_allmove(move);


	free_all_list(list_a);
	free_all_list(list_b);
	free_all_list(move);
	free(all);
}
	