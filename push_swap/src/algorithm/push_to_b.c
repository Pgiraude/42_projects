/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:17 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 16:25:29 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_cell	*target_to_process(t_ctrl *all)
{
	t_cell	*cell;
	t_cell	*target;
	int		sign;
	int		lower_cost;

	target = NULL;
	cell = all->list_a->first;
	lower_cost = all->max_len;
	while (cell != NULL)
	{
		if (cell->cost_a >= 0)
			sign = 1;
		else
			sign = -1;
		if (lower_cost > cell->cost_a * sign && cell->tag == true)
		{
			lower_cost = cell->cost_a * sign;
			target = cell;
		}
		cell = cell->next;
	}
	return (target);
}

int	check_further(t_cell *cell, t_cell *cell_back, t_ctrl *all, int mode)
{
	t_cell	*further_pos;
	int		i;

	if (mode == 0)
		further_pos = cell;
	else
		further_pos = cell_back;
	i = 1;
	while (i++ <= 2)
	{
		if (further_pos->next == NULL)
			further_pos = all->list_a->first;
		else
			further_pos = further_pos->next;
	}
	if (check_is_aligned(cell_back, further_pos, all->max_len, 1) == true)
		return (true);
	if (check_is_aligned(cell, further_pos, all->max_len, 1) == true)
		return (true);
	return (false);
}

int	target_to_swapa(t_ctrl *all)
{
	t_cell	*cell;
	t_cell	*cell_back;
	int		nbr_swap;

	nbr_swap = 0;
	cell = all->list_a->first;
	cell_back = all->list_a->last;
	while (cell != NULL)
	{
		cell->tag = false;
		if (check_further(cell, cell_back, all, 0) == true
			&& check_further(cell, cell_back, all, 1) == true)
		{
			cell->tag = true;
			nbr_swap++;
		}
		cell_back = cell;
		cell = cell->next;
	}
	return (nbr_swap);
}

void	get_swap(t_ctrl *all)
{
	t_cell	*target;
	int		nbr;

	if (all->list_a->len == 2)
	{
		target = all->list_a->first;
		if (check_is_aligned(target, target->next, 2, 2) == false)
		{
			all_move(all->list_a, all->list_b, sa);
			all->move = insert_data_list(all->move, sa, 1);
		}
		return ;
	}
	nbr = target_to_swapa(all);
	while (nbr != 0)
	{
		costa_getup_la(all->list_a);
		target = target_to_process(all);
		placeup_target_lista(all, target);
		all_move(all->list_a, all->list_b, sa);
		all->move = insert_data_list(all->move, sa, 1);
		nbr = target_to_swapa(all);
	}
}

void	push_to_b(t_ctrl *all)
{
	t_cell	*target;
	int		i;
	int		nbr;

	get_swap(all);
	nbr = push_to_b_optimisation(all);
	i = 1;
	while (i <= nbr)
	{
		costa_getup_la(all->list_a);
		costb_getposition_la(all->list_a, all->list_b, all);
		target = target_to_process(all);
		placeup_target_lista(all, target);
		all_move(all->list_a, all->list_b, pb);
		all->move = insert_data_list(all->move, pb, 1);
		if (all->list_b->len > 2
			&& (check_is_aligned(target, target->next, all->max_len, 1)
			|| check_is_aligned(target, target->next->next, all->max_len, 0)))
		{
			all_move(all->list_a, all->list_b, sb);
			all->move = insert_data_list(all->move, sb, 1);
		}
		i++;
	}
	get_swap(all);
}
