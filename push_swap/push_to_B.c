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
	List	*further_pos;
	int		i;

	if (mode == 0)
		further_pos = cell;
	else
		further_pos = cell_back;
	i = 1;
	while (i++ <= 2)
	{
		if (further_pos->next == NULL)
			further_pos = ALL->La->first;
		else
			further_pos = further_pos->next;
	}
	if (check_is_aligned(cell_back, further_pos, ALL->max_len, 1) == true)
		return (true);
	if (check_is_aligned(cell, further_pos, ALL->max_len, 1) == true)
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

void	get_swap(DDList *ALL)
{
	List	*target;
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
}

void	push_to_b(DDList *ALL)
{
	List	*target;
	int		i;
	int		nbr;

	get_swap(ALL);
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
	get_swap(ALL);
}
