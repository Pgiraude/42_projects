/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_B.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:17 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 18:07:32 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	nbr = target_to_swapa(all);
	while (nbr != 0)
	{
		costa_getup_la(all->list_a);
		target = target_to_process(all);
		placeup_target_lista(all, target);
		all_move(all->list_a, all->list_b, sa);
		all->move = insert_data_Dlist(all->move, sa, 1);
		nbr = target_to_swapa(all);
	}
}

void	push_to_b(t_ctrl *all)
{
	t_cell	*target;
	int		i;
	int		nbr;

	get_swap(all);
	nbr = get_pb_optimisation(all);
	i = 1;
	while (i <= nbr)
	{
		costa_getup_la(all->list_a);
		target = target_to_process(all);
		placeup_target_lista(all, target);
		all_move(all->list_a, all->list_b, pb);
		all->move = insert_data_Dlist(all->move, pb, 1);
		i++;
	}
	get_swap(all);
}
