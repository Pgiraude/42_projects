/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_swap_optimisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:28:58 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 12:12:57 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

e_bool	lb_is_aligned_bigswap(t_list *ListB, t_ctrl *all)
{
	t_cell	*cell;
	t_cell	*next_cell;
	int		i;

	i = 1;
	if (ListB->len < 4)
		return (false);
	cell = ListB->first;
	next_cell = ListB->first->next;
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

e_bool	bigswap_optimisation(t_ctrl *all)
{
	t_cell	*cell;
	int		i;

	if (all->list_b->len < 4)
		return (false);
	cell = all->list_b->first;
	i = 1;
	while (i <= 4)
	{
		if (cell->aligne_next == true)
			return (false);
		i++;
		cell = cell->next;
	}
	if (lb_is_aligned_bigswap(all->list_b, all) == false)
		return (false);
	all->move = insert_data_list(all->move, all_move(all->list_a, all->list_b, pa), 1);
	all->move = insert_data_list(all->move, all_move(all->list_a, all->list_b, pa), 1);
	all->move = insert_data_list(all->move, all_move(all->list_a, all->list_b, ss), 1);
	all->move = insert_data_list(all->move, all_move(all->list_a, all->list_b, pa), 1);
	all->move = insert_data_list(all->move, all_move(all->list_a, all->list_b, pa), 1);
	get_all_cost(all);
	return (true);
}

e_bool	lb_is_aligned_swap(t_ctrl *all)
{
	t_cell	*cellb;
	t_cell	*cella;

	if (all->list_b->len < 2)
		return (false);
	cella = all->list_a->first;
	cellb = all->list_b->first;
	if (cella->aligne_next == false)
		return (false);
	if (check_is_aligned(cellb, cellb->next, all->max_len, 1) == false)
		return (false);
	cellb = cellb->next;
	if (check_is_aligned(cellb, cella, all->max_len, 1) == false)
		return (false);
	return (true);
}

e_bool	swap_optimisation(t_ctrl *all)
{
	t_cell	*first_pos;
	int		i;

	if (lb_is_aligned_swap(all) == false)
		return (false);
	if (all->list_b->len == 2)
	{
		first_pos = all->list_a->first;
		i = 0;
		while (first_pos->final_pos != 1 || first_pos != NULL)
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
