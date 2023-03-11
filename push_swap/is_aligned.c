/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_aligned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:46:47 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 17:48:02 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Bool	check_is_aligned(List *target, List *compare, int max_len, int mode)
{
	if (target == NULL || compare == NULL)
		return (false);
	if (mode == 0)
	{
		if (target->target_pos == compare->target_pos + 1)
			return (true);
		else if (target->target_pos == 1 && compare->target_pos == max_len)
			return (true);
	}
	else if (mode == 1)
	{
		if (target->target_pos == compare->target_pos - 1)
			return (true);
		else if (target->target_pos == max_len && compare->target_pos == 1)
			return (true);
	}
	return (false);
}

void	lb_is_aligned(DList *ListB, DDList *ALL)
{
	List	*cell;
	List	*back_cell;
	List	*next_cell;

	if (ListB->len < 2)
		return ;
	cell = ListB->first;
	back_cell = ListB->last;
	next_cell = ListB->first->next;
	while (cell != NULL)
	{
		cell->aligne_back = false;
		cell->aligne_next = false;
		if (next_cell == NULL)
			next_cell = ListB->first;
		if (check_is_aligned(cell, back_cell, ALL->max_len, 1) == true)
			cell->aligne_back = true;
		if (check_is_aligned(cell, next_cell, ALL->max_len, 0) == true)
			cell->aligne_next = true;
		next_cell = next_cell->next;
		back_cell = cell;
		cell = cell->next;
	}
}

void	la_is_aligned(DList *ListA, DDList *ALL)
{
	List	*cell;
	List	*back_cell;
	List	*next_cell;

	if (ListA->len < 2)
		return ;
	cell = ListA->first;
	back_cell = ListA->last;
	next_cell = ListA->first->next;
	while (cell != NULL)
	{
		cell->aligne_back = false;
		cell->aligne_next = false;
		if (next_cell == NULL)
			next_cell = ListA->first;
		if (check_is_aligned(cell, back_cell, ALL->max_len, 0) == true)
			cell->aligne_back = true;
		if (check_is_aligned(cell, next_cell, ALL->max_len, 1) == true)
			cell->aligne_next = true;
		next_cell = next_cell->next;
		back_cell = cell;
		cell = cell->next;
	}
}

void	is_aligned(DDList *ALL)
{
	la_is_aligned(ALL->La, ALL);
	lb_is_aligned(ALL->Lb, ALL);
}
