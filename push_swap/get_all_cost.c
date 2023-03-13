/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 18:27:45 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_bonus_cost(DDList *ALL)
{
	List	*cell;
	int		sign;
	int		i;

	cell = ALL->Lb->first;
	while (cell != NULL)
	{
		sign = 1;
		i = 0;
		if (i < cell->costA && i < cell->costB)
			while (i < cell->costA && i < cell->costB)
				i++;
		else if (i > cell->costA && i > cell->costB)
			while (i > cell->costA && i > cell->costB)
				i--;
		else if ((cell->moveA == true && i > cell->costB)
			|| (cell->moveB == true && i > cell->costA))
			while (i > cell->costB || i > cell->costA)
				i--;
		if (i > 0)
			sign = -1;
		cell->bonus_cost = i * sign;
		cell = cell->next;
	}
}

int	get_score(List *target, List *compare, int max_len, int mode)
{
	int	position;
	int	score;

	position = target->target_pos;
	score = 0;
	if (mode == 0)
	{
		while (position-- != compare->target_pos)
		{
			score++;
			if (position < 1)
				position = max_len;
		}
	}
	else
	{
		while (position++ != compare->target_pos)
		{
			score++;
			if (position > max_len)
				position = 1;
		}
	}
	return (score);
}

int	costa_lb(int max_len, List *la_back, List *la, List *lb)
{
	int	i;
	int	cost;
	int	score;
	int	save_score;

	save_score = max_len * 2;
	cost = 0;
	i = 0;
	while (la != NULL)
	{
		if (check_is_aligned(lb, la_back, max_len, 0) == true
			|| check_is_aligned(lb, la, max_len, 1) == true)
			return (i);
		score = get_score(lb, la_back, max_len, 0);
		score += get_score(lb, la, max_len, 1);
		if (score < save_score)
		{
			save_score = score;
			cost = i;
		}
		i++;
		la_back = la;
		la = la->next;
	}
	return (cost);
}

void	costa_getposition_lb(DList *ListA, DList *ListB, DDList *ALL)
{
	List	*cella;
	List	*cella_back;
	List	*cellb;
	int		cost;
	int		paire;

	paire = 0;
	if (ListA->len % 2 == 0)
		paire = 1;
	cellb = ListB->first;
	while (cellb != NULL)
	{
		cellb->moveA = false;
		cella_back = ListA->last;
		cella = ListA->first;
		cost = costa_lb(ALL->max_len, cella_back, cella, cellb);
		if (cost <= ListA->len / 2)
			cellb->costA = cost;
		if (cost == ListA->len / 2 && paire == 1)
			cellb->moveA = true;
		if (cost > ListA->len / 2)
			cellb->costA = cost - ListA->len;
		cellb = cellb->next;
	}
}

void	get_all_cost(DDList *ALL)
{
	List	*cell;
	int		paire;
	int		i;

	paire = 0;
	if (ALL->Lb->len % 2 == 0)
		paire = 1;
	cell = ALL->Lb->first;
	i = 0;
	while (cell != NULL)
	{
		cell->moveB = false;
		if (i <= ALL->Lb->len / 2)
			cell->costB = i;
		if (i == ALL->Lb->len / 2 && paire == 1)
			cell->moveB = true;
		if (i > ALL->Lb->len / 2)
			cell->costB = i - ALL->Lb->len;
		i++;
		cell = cell->next;
	}
	is_aligned(ALL);
	costa_getposition_lb(ALL->La, ALL->Lb, ALL);
	calculate_bonus_cost(ALL);
}
