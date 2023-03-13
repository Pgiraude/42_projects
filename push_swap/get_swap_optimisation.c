/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_swap_optimisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:28:58 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 17:43:34 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Bool	lb_is_aligned_bigswap(DList *ListB, DDList *ALL)
{
	List	*cell;
	List	*next_cell;
	int		i;

	i = 1;
	if (ListB->len < 4)
		return (false);
	cell = ListB->first;
	next_cell = ListB->first->next;
	while (i <= 2)
	{
		if (check_is_aligned(cell, next_cell, ALL->max_len, 1) == false)
			return (false);
		if (i != 2)
		{
			cell = cell->next;
			next_cell = next_cell->next->next;
			if (cell->target_pos < next_cell->target_pos)
				return (false);
			cell = cell->next;
		}
		i++;
	}
	return (true);
}

Bool	bigswap_optimisation(DDList *ALL)
{
	List	*cell;
	int		i;

	if (ALL->Lb->len < 4)
		return (false);
	cell = ALL->Lb->first;
	i = 1;
	while (i <= 4)
	{
		if (cell->aligne_next == true)
			return (false);
		i++;
		cell = cell->next;
	}
	if (lb_is_aligned_bigswap(ALL->Lb, ALL) == false)
		return (false);
	ALL->Move = insert_data_Dlist(ALL->Move, all_move(ALL->La, ALL->Lb, pa), 1);
	ALL->Move = insert_data_Dlist(ALL->Move, all_move(ALL->La, ALL->Lb, pa), 1);
	ALL->Move = insert_data_Dlist(ALL->Move, all_move(ALL->La, ALL->Lb, ss), 1);
	ALL->Move = insert_data_Dlist(ALL->Move, all_move(ALL->La, ALL->Lb, pa), 1);
	ALL->Move = insert_data_Dlist(ALL->Move, all_move(ALL->La, ALL->Lb, pa), 1);
	get_all_cost(ALL);
	return (true);
}

Bool	lb_is_aligned_swap(DDList *ALL)
{
	List	*cellb;
	List	*cella;

	if (ALL->Lb->len < 2)
		return (false);
	cella = ALL->La->first;
	cellb = ALL->Lb->first;
	if (cella->aligne_next == false)
		return (false);
	if (check_is_aligned(cellb, cellb->next, ALL->max_len, 1) == false)
		return (false);
	cellb = cellb->next;
	if (check_is_aligned(cellb, cella, ALL->max_len, 1) == false)
		return (false);
	return (true);
}

Bool	swap_optimisation(DDList *ALL)
{
	List	*first_pos;
	int		i;

	if (lb_is_aligned_swap(ALL) == false)
		return (false);
	if (ALL->Lb->len == 2)
	{
		first_pos = ALL->La->first;
		i = 0;
		while (first_pos->target_pos != 1 || first_pos != NULL)
		{
			first_pos = first_pos->next;
			i++;
		}
		if (i + 2 > ALL->max_len / 2 && first_pos != NULL)
			return (false);
	}
	all_move(ALL->La, ALL->Lb, sb);
	all_move(ALL->La, ALL->Lb, pa);
	all_move(ALL->La, ALL->Lb, pa);
	ALL->Move = insert_data_Dlist(ALL->Move, sb, 1);
	ALL->Move = insert_data_Dlist(ALL->Move, pa, 1);
	ALL->Move = insert_data_Dlist(ALL->Move, pa, 1);
	get_all_cost(ALL);
	return (true);
}
