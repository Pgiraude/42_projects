/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_aligned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:46:47 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 12:12:57 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

e_bool	check_is_aligned(t_cell *target, t_cell *compare, int max_len, int mode)
{
	if (target == NULL || compare == NULL)
		return (false);
	if (mode == 0)
	{
		if (target->final_pos == compare->final_pos + 1)
			return (true);
		else if (target->final_pos == 1 && compare->final_pos == max_len)
			return (true);
	}
	else if (mode == 1)
	{
		if (target->final_pos == compare->final_pos - 1)
			return (true);
		else if (target->final_pos == max_len && compare->final_pos == 1)
			return (true);
	}
	return (false);
}

void	lb_is_aligned(t_list *list_b, t_ctrl *all)
{
	t_cell	*cell;
	t_cell	*back_cell;
	t_cell	*next_cell;

	if (list_b->len < 2)
		return ;
	cell = list_b->first;
	back_cell = list_b->last;
	next_cell = list_b->first->next;
	while (cell != NULL)
	{
		cell->aligne_back = false;
		cell->aligne_next = false;
		if (next_cell == NULL)
			next_cell = list_b->first;
		if (check_is_aligned(cell, back_cell, all->max_len, 1) == true)
			cell->aligne_back = true;
		if (check_is_aligned(cell, next_cell, all->max_len, 0) == true)
			cell->aligne_next = true;
		next_cell = next_cell->next;
		back_cell = cell;
		cell = cell->next;
	}
}

void	la_is_aligned(t_list *list_a, t_ctrl *all)
{
	t_cell	*cell;
	t_cell	*back_cell;
	t_cell	*next_cell;

	if (list_a->len < 2)
		return ;
	cell = list_a->first;
	back_cell = list_a->last;
	next_cell = list_a->first->next;
	while (cell != NULL)
	{
		cell->aligne_back = false;
		cell->aligne_next = false;
		if (next_cell == NULL)
			next_cell = list_a->first;
		if (check_is_aligned(cell, back_cell, all->max_len, 0) == true)
			cell->aligne_back = true;
		if (check_is_aligned(cell, next_cell, all->max_len, 1) == true)
			cell->aligne_next = true;
		next_cell = next_cell->next;
		back_cell = cell;
		cell = cell->next;
	}
}

void	is_aligned(t_ctrl *all)
{
	la_is_aligned(all->list_a, all);
	lb_is_aligned(all->list_b, all);
}
