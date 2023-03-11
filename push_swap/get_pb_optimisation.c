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

void	costa_getup_la(DList *ListA)
{
	List	*cell;
	int		paire;
	int		i;

	paire = 0;
	if (ListA->len % 2 == 0)
		paire = 1;
	cell = ListA->first;
	i = 0;
	while (cell != NULL)
	{
		cell->moveA = false;
		if (i <= ListA->len / 2)
			cell->costA = i;
		if (i == ListA->len / 2 && paire == 1)
			cell->moveA = true;
		if (i > ListA->len / 2)
			cell->costA = i - ListA->len;
		i++;
		cell = cell->next;
	}
}

int	get_pb_tag(List *pivot, DDList *ALL)
{
	List	*last_pos;
	int		nbr_pb;
	int		i;

	i = 1;
	nbr_pb = 0;
	if (pivot == NULL)
		return (nbr_pb);
	last_pos = pivot;
	while (i++ < ALL->La->len)
	{
		if (ALL->La->len - nbr_pb == 3)
			break ;
		pivot = pivot->next;
		if (pivot == NULL)
			pivot = ALL->La->first;
		if (check_is_aligned(pivot, last_pos, ALL->max_len, 0) == true)
			last_pos = pivot;
		else
		{
			nbr_pb++;
			pivot->tag = true;
		}
	}
	return (nbr_pb);
}

int	get_pb_score(List *pivot, DDList *ALL)
{
	List	*last_pos;
	int		score;
	int		i;

	i = 1;
	score = 0;
	last_pos = pivot;
	while (i++ <= ALL->La->len)
	{
		pivot = pivot->next;
		if (pivot == NULL)
			pivot = ALL->La->first;
		if (check_is_aligned(pivot, last_pos, ALL->max_len, 0) == true)
		{
			last_pos = pivot;
			score++;
		}
	}
	return (score);
}

int	get_pb_optimisation(DDList *ALL)
{
	List	*cell;
	List	*pivot;
	int		best_score;
	int		score;

	pivot = NULL;
	best_score = 0;
	cell = ALL->La->first;
	while (cell != NULL)
	{
		score = get_pb_score(cell, ALL);
		if (score > best_score)
		{
			best_score = score;
			pivot = cell;
		}
		cell = cell->next;
	}
	if (best_score == ALL->max_len)
		return (0);
	return (get_pb_tag(pivot, ALL));
}
