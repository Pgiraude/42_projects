/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/17 09:28:50 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	push_swap(t_ctrl *all, char **values)
{
	t_cell	*first_pos;
	int		i;

	set_all_list(all);
	i = -1;
	while (values[++i])
		all->list_a = insert_data_list(all->list_a, ft_atoi(values[i]), 1);
	if (all->list_a->len == 1)
		return ;
	set_all_cell(all);
	get_final_pos(all);
	push_to_b(all);
	while (all->list_b->len > 0)
	{
		get_all_cost(all);
		push_to_a(all);
	}
	first_pos = all->list_a->first;
	costa_getup_la(all->list_a);
	while (first_pos->final_pos != 1)
		first_pos = first_pos->next;
	first_pos->cost_b = 0;
	first_pos->move_b = false;
	placeup_target_lista(all, first_pos);
}
