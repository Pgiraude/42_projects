/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_swap_optimisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:28:58 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 14:30:08 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	lb_is_aligned_bigswap(t_list *List_b, t_ctrl *all)
{
	t_cell	*cell;
	t_cell	*next_cell;
	int		i;

	i = 1;
	if (List_b->len < 4)
		return (false);
	cell = List_b->first;
	next_cell = List_b->first->next;
	while (i <= 2)
	{
		if (check_is_aligned(cell, next_cell, all->max_len, 1) == false)
			return (false);
		if (i != 2)
		{
			cell = cell->next;
			next_cell = next_cell->next->next;
			if (cell->final_pos < next_cell->final_pos)
				return (false);
			cell = cell->next;
		}
		i++;
	}
	return (true);
}

t_bool	bigswap_optimisation(t_ctrl *all)
{
	t_cell	*cell;
	int		i;

	if (all->list_b->len < 4)
		return (false);
	cell = all->list_b->first;
	i = 1;
	while (i++ <= 2)
	{
		if (check_is_aligned(cell, cell->next, all->max_len, 0))
			return (false);
		cell = cell->next->next;
	}
	if (lb_is_aligned_bigswap(all->list_b, all) == false)
		return (false);
	all->move = insert_data_list(all->move, pa, 1);
	all->move = insert_data_list(all->move, pa, 1);
	all->move = insert_data_list(all->move, ss, 1);
	all_move(all->list_a, all->list_b, pa);
	all_move(all->list_a, all->list_b, pa);
	all_move(all->list_a, all->list_b, ss);
	get_all_cost(all);
	return (true);
}

t_bool	lb_is_aligned_swap(t_ctrl *all)
{
	t_cell	*cell_b;
	t_cell	*cell_a;

	if (all->list_b->len < 2)
		return (false);
	cell_a = all->list_a->first;
	cell_b = all->list_b->first;
	if (check_is_aligned(cell_a, all->list_a->last, all->max_len, 0))
		return (false);
	if (all->list_b->len == 2
		&& check_is_aligned(cell_b->next, cell_b, all->max_len, 2))
		return (true);
	if (check_is_aligned(cell_b, cell_b->next, all->max_len, 0) == false)
		return (false);
	cell_b = cell_b->next;
	if (check_is_aligned(cell_b, cell_a, all->max_len, 1) == false)
		return (false);
	return (true);
}

t_bool	swap_optimisation(t_ctrl *all)
{
	t_cell	*first_pos;
	int		i;

	if (lb_is_aligned_swap(all) == false)
		return (false);
	if (all->list_b->len == 2)
	{
		first_pos = all->list_a->first;
		i = 0;
		while (first_pos != NULL && first_pos->final_pos != 1)
		{
			first_pos = first_pos->next;
			i++;
		}
		if (i + 2 > all->max_len / 2 && first_pos != NULL)
			return (false);
	}
	all_move(all->list_a, all->list_b, sb);
	all_move(all->list_a, all->list_b, pa);
	all_move(all->list_a, all->list_b, pa);
	all->move = insert_data_list(all->move, sb, 1);
	all->move = insert_data_list(all->move, pa, 1);
	all->move = insert_data_list(all->move, pa, 1);
	get_all_cost(all);
	return (true);
}
