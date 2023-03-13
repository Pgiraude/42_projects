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

void	calculate_bonus_cost(t_ctrl *all)
{
	t_cell	*cell;
	int		sign;
	int		i;

	cell = all->list_b->first;
	while (cell != NULL)
	{
		sign = 1;
		i = 0;
		if (i < cell->cost_a && i < cell->cost_b)
			while (i < cell->cost_a && i < cell->cost_b)
				i++;
		else if (i > cell->cost_a && i > cell->cost_b)
			while (i > cell->cost_a && i > cell->cost_b)
				i--;
		else if ((cell->move_a == true && i > cell->cost_b)
			|| (cell->move_b == true && i > cell->cost_a))
			while (i > cell->cost_b || i > cell->cost_a)
				i--;
		if (i > 0)
			sign = -1;
		cell->bonus_cost = i * sign;
		cell = cell->next;
	}
}

int	get_score(t_cell *target, t_cell *compare, int max_len, int mode)
{
	int	position;
	int	score;

	position = target->final_pos;
	score = 0;
	if (mode == 0)
	{
		while (position-- != compare->final_pos)
		{
			score++;
			if (position < 1)
				position = max_len;
		}
	}
	else
	{
		while (position++ != compare->final_pos)
		{
			score++;
			if (position > max_len)
				position = 1;
		}
	}
	return (score);
}

int	costa_lb(int max_len, t_cell *la_back, t_cell *la, t_cell *lb)
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

void	costa_getposition_lb(t_list *list_a, t_list *list_b, t_ctrl *all)
{
	t_cell	*cella;
	t_cell	*cella_back;
	t_cell	*cellb;
	int		cost;
	int		paire;

	paire = 0;
	if (list_a->len % 2 == 0)
		paire = 1;
	cellb = list_b->first;
	while (cellb != NULL)
	{
		cellb->move_a = false;
		cella_back = list_a->last;
		cella = list_a->first;
		cost = costa_lb(all->max_len, cella_back, cella, cellb);
		if (cost <= list_a->len / 2)
			cellb->cost_a = cost;
		if (cost == list_a->len / 2 && paire == 1)
			cellb->move_a = true;
		if (cost > list_a->len / 2)
			cellb->cost_a = cost - list_a->len;
		cellb = cellb->next;
	}
}

void	get_all_cost(t_ctrl *all)
{
	t_cell	*cell;
	int		paire;
	int		i;

	paire = 0;
	if (all->list_b->len % 2 == 0)
		paire = 1;
	cell = all->list_b->first;
	i = 0;
	while (cell != NULL)
	{
		cell->move_b = false;
		if (i <= all->list_b->len / 2)
			cell->cost_b = i;
		if (i == all->list_b->len / 2 && paire == 1)
			cell->move_b = true;
		if (i > all->list_b->len / 2)
			cell->cost_b = i - all->list_b->len;
		i++;
		cell = cell->next;
	}
	is_aligned(all);
	costa_getposition_lb(all->list_a, all->list_b, all);
	calculate_bonus_cost(all);
}
