/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_B.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:17 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/09 20:02:30 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	placeup_target_lista(DDList *ALL, List *target)
{
	if (target == NULL)
		return ;
	target->tag = false;
	while (target->costA > 0)
	{
		all_move(ALL->La, ALL->Lb, ra);
		ALL->Move = insert_data_Dlist(ALL->Move, ra, 1);
		target->costA--;
	}
	while (target->costA < 0)
	{
		all_move(ALL->La, ALL->Lb, rra);
		ALL->Move = insert_data_Dlist(ALL->Move, rra, 1);
		target->costA++;
	}
}

List	*target_to_process(DDList *ALL)
{
	List	*cell;
	List	*target;
	int		sign;
	int		lower_cost;

	target = NULL;
	cell = ALL->La->first;
	lower_cost = ALL->max_len;
	while (cell != NULL)
	{
		if (cell->costA >= 0)
			sign = 1;
		else
			sign = -1;
		if (lower_cost > cell->costA * sign && cell->tag == true)
		{
			lower_cost = cell->costA * sign;
			target = cell;
		}
		cell = cell->next;
	}
	return (target);
}

int	check_further(List *cell, List *cell_back, DDList *ALL, int mode)
{
	List	*target;
	int		i;
	int		further_pos;

	if (mode == 0)
		target = cell;
	else
		target = cell_back;
	i = 1;
	while (i++ <= 2)
	{
		if (target->next == NULL)
			target = ALL->La->first;
		else
			target = target->next;
	}
	further_pos = target->target_pos;
	if (cell_back->target_pos == further_pos - 1
		|| (cell_back->target_pos == ALL->max_len && further_pos == 1))
		return (true);
	if (cell->target_pos == further_pos - 1
		|| (cell->target_pos == ALL->max_len && further_pos == 1))
		return (true);
	return (false);
}

int	target_to_swapa(DDList *ALL)
{
	List	*cell;
	List	*cell_back;
	int		nbr_swap;

	nbr_swap = 0;
	cell = ALL->La->first;
	cell_back = ALL->La->last;
	while (cell != NULL)
	{
		cell->tag = false;
		if (check_further(cell, cell_back, ALL, 0) == true
			&& check_further(cell, cell_back, ALL, 1) == true)
		{
			cell->tag = true;
			nbr_swap++;
		}
		cell_back = cell;
		cell = cell->next;
	}
	return (nbr_swap);
}

void	push_to_b(DDList *ALL)
{
	List	*target;
	int		i;
	int		nbr;

	nbr = target_to_swapa(ALL);
	while (nbr != 0)
	{
		costa_getup_la(ALL->La);
		target = target_to_process(ALL);
		placeup_target_lista(ALL, target);
		all_move(ALL->La, ALL->Lb, sa);
		ALL->Move = insert_data_Dlist(ALL->Move, sa, 1);
		nbr = target_to_swapa(ALL);
	}
	nbr = get_pb_optimisation(ALL);
	i = 1;
	while (i <= nbr)
	{
		costa_getup_la(ALL->La);
		target = target_to_process(ALL);
		placeup_target_lista(ALL, target);
		all_move(ALL->La, ALL->Lb, pb);
		ALL->Move = insert_data_Dlist(ALL->Move, pb, 1);
		i++;
	}
}
