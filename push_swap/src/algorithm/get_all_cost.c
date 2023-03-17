/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/17 13:15:50 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

	paire = is_paire(list_a->len);
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

int	costb_la(int max_len, t_cell *lb_back, t_cell *lb, t_cell *la)
{
	int	i;
	int	cost;
	int	score;
	int	save_score;

	save_score = max_len * 2;
	cost = 0;
	i = 0;
	while (lb != NULL)
	{
		if (check_is_aligned(la, lb_back, max_len, 1) == true
			|| check_is_aligned(la, lb, max_len, 0) == true)
			return (i);
		score = get_score(la, lb_back, max_len, 1);
		score += get_score(la, lb, max_len, 0);
		if (score < save_score)
		{
			save_score = score;
			cost = i;
		}
		i++;
		lb_back = lb;
		lb = lb->next;
	}
	return (cost);
}

void	costb_getposition_la(t_list *list_a, t_list *list_b, t_ctrl *all)
{
	t_cell	*cell_b;
	t_cell	*cellb_back;
	t_cell	*cell_a;
	int		cost;
	int		paire;

	if (list_b->len <= 2)
		return ;
	paire = is_paire(list_b->len);
	cell_a = list_a->first;
	while (cell_a != NULL)
	{
		cell_a->move_b = false;
		cellb_back = list_b->last;
		cell_b = list_b->first;
		cost = costb_la(all->max_len, cellb_back, cell_b, cell_a);
		if (cost <= list_b->len / 2)
			cell_a->cost_b = cost;
		if (cost == list_b->len / 2 && paire == 1)
			cell_a->move_b = true;
		if (cost > list_b->len / 2)
			cell_a->cost_b = cost - list_b->len;
		cell_a = cell_a->next;
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
	costa_getposition_lb(all->list_a, all->list_b, all);
	calculate_bonus_cost(all);
}
