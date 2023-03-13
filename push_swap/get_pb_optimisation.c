/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pb_optimisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:51:38 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 17:27:39 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	costa_getup_la(t_list *list_a)
{
	t_cell	*cell;
	int		paire;
	int		i;

	paire = 0;
	if (list_a->len % 2 == 0)
		paire = 1;
	cell = list_a->first;
	i = 0;
	while (cell != NULL)
	{
		cell->move_a = false;
		if (i <= list_a->len / 2)
			cell->cost_a = i;
		if (i == list_a->len / 2 && paire == 1)
			cell->move_a = true;
		if (i > list_a->len / 2)
			cell->cost_a = i - list_a->len;
		i++;
		cell = cell->next;
	}
}

int	get_pb_tag(t_cell *pivot, t_ctrl *all)
{
	t_cell	*last_pos;
	int		nbr_pb;
	int		i;

	i = 1;
	nbr_pb = 0;
	if (pivot == NULL)
		return (nbr_pb);
	last_pos = pivot;
	while (i++ < all->list_a->len)
	{
		if (all->list_a->len - nbr_pb == 3)
			break ;
		pivot = pivot->next;
		if (pivot == NULL)
			pivot = all->list_a->first;
		if (check_is_aligned(pivot, last_pos, all->max_len, 0) == true)
			last_pos = pivot;
		else
		{
			nbr_pb++;
			pivot->tag = true;
		}
	}
	return (nbr_pb);
}

int	get_pb_score(t_cell *pivot, t_ctrl *all)
{
	t_cell	*last_pos;
	int		score;
	int		i;

	i = 1;
	score = 0;
	last_pos = pivot;
	while (i++ <= all->list_a->len)
	{
		pivot = pivot->next;
		if (pivot == NULL)
			pivot = all->list_a->first;
		if (check_is_aligned(pivot, last_pos, all->max_len, 0) == true)
		{
			last_pos = pivot;
			score++;
		}
	}
	return (score);
}

int	get_pb_optimisation(t_ctrl *all)
{
	t_cell	*cell;
	t_cell	*pivot;
	int		best_score;
	int		score;

	pivot = NULL;
	best_score = 0;
	cell = all->list_a->first;
	while (cell != NULL)
	{
		score = get_pb_score(cell, all);
		if (score > best_score)
		{
			best_score = score;
			pivot = cell;
		}
		cell = cell->next;
	}
	if (best_score == all->max_len)
		return (0);
	return (get_pb_tag(pivot, all));
}
