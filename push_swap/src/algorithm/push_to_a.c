/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:36 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 12:12:57 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_score_target(t_cell *target, t_ctrl *all)
{
	int		position;
	t_cell	*cell;
	t_cell	*cell_back;

	position = target->cost_a;
	if (target->cost_a < 0)
		position = position + all->list_a->len;
	cell_back = all->list_a->last;
	cell = all->list_a->first;
	while (position-- != 0)
	{
		cell_back = cell;
		cell = cell->next;
	}
	if (check_is_aligned(target, cell_back, all->max_len, 0)
		&& check_is_aligned(target, cell, all->max_len, 1))
		return (0);
	return (get_score(target, cell, all->max_len, 1));
}

t_cell    *get_best_target(t_cell *save, t_cell *analyse, t_ctrl *all)
{
	int	score_s;
	int	score_a;

	score_s = get_score_target(save, all);
	score_a = get_score_target(analyse, all);
	if (score_s > score_a)
		return (analyse);
	else if (score_s == score_a && save->final_pos < analyse->final_pos)
		return (analyse);
	return (save);
}

int    get_cost(t_cell *target)
{
	int target_cost;
	int sign_a;
	int sign_b;

	sign_b = 1;
	sign_a = 1;
	if (target->cost_a < 0)
			sign_a = -1;
	if (target->cost_b < 0)
			sign_b = -1;
	target_cost = target->cost_a * sign_a + target->cost_b * sign_b;
	target_cost += target->bonus_cost;
	return (target_cost);
}

t_cell    *target_to_push_a(t_ctrl *all)
{
	t_cell	*cell;
	t_cell	*target;
	int		cell_cost;
	int		target_cost;

	cell = all->list_b->first;
	target = cell;
	while (cell != NULL)
	{
		cell_cost = get_cost(cell);
		target_cost = get_cost(target);
		if (cell_cost < target_cost)
			target = cell;
		else if (cell_cost == target_cost)
			target = get_best_target(target, cell, all);
		cell = cell->next;
	}
	return (target);
}

void    push_to_a(t_ctrl *all)
{
	t_cell *target;
	int loop;

	if (all->list_b->len == 0)
		return ;
	bigswap_optimisation(all);
	swap_optimisation(all);
	target = target_to_push_a(all);
	ft_printf("target data=%d\n", target->data);
	place_target_listb(all, target);
	if (bigswap_optimisation(all) == false
		&& swap_optimisation(all) == false)
	{
		
		loop = 1;
		while (all->list_b->len > 0 && loop > 0 && target != NULL)
		{
			if (all->list_b->first->aligne_next == true && all->list_b->first->next != NULL)
				loop++;
			all->move = insert_data_list(all->move, pa, 1);
			all_move(all->list_a, all->list_b, pa);
			loop--;
		}
	}
}