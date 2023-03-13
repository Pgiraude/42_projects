/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_A.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:36 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/09 21:35:36 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_score_target(List *target, DDList *ALL)
{
	int		position;
	List	*cell;
	List	*cell_back;

	position = target->costA;
	if (target->costA < 0)
		position = position + ALL->La->len;
	cell_back = ALL->La->last;
	cell = ALL->La->first;
	while (position-- != 0)
	{
		cell_back = cell;
		cell = cell->next;
	}
	if (check_is_aligned(target, cell_back, ALL->max_len, 0)
		&& check_is_aligned(target, cell, ALL->max_len, 1))
		return (0);
	return (get_score(target, cell, ALL->max_len, 1));
}

List    *processing(List *save, List *analyse, DDList *ALL)
{
	int	score_s;
	int	score_a;

	score_s = get_score_target(save, ALL);
	score_a = get_score_target(analyse, ALL);
	if (score_s > score_a)
		return (analyse);
	else if (score_s == score_a && save->target_pos < analyse->target_pos)
		return (analyse);
	return (save);
}

int    get_cost(List *target)
{
	int target_cost;
	int sign_a;
	int sign_b;

	sign_b = 1;
	sign_a = 1;
	if (target->costA < 0)
			sign_a = -1;
	if (target->costB < 0)
			sign_b = -1;
	target_cost = target->costA * sign_a + target->costB * sign_b;
	target_cost += target->bonus_cost;
	return (target_cost);
}

List    *target_to_pushA(DDList *ALL)
{
	List	*cell;
	List	*target;
	int		cell_cost;
	int		target_cost;

	cell = ALL->Lb->first;
	target = cell;
	while (cell != NULL)
	{
		cell_cost = get_cost(cell);
		target_cost = get_cost(target);
		if (cell_cost < target_cost)
			target = cell;
		else if (cell_cost == target_cost)
			target = processing(target, cell, ALL);
		cell = cell->next;
	}
	return (target);
}

void    push_to_a(DDList *ALL)
{
	List *target;
	int loop;

	target = target_to_pushA(ALL);
	ft_printf("target data=%d\n", target->data);
	place_target_listb(ALL, target);
	if (bigswap_optimisation(ALL) == false)
	{
		if (swap_optimisation(ALL) == false)
		{
			loop = 1;
			while (ALL->Lb->len > 0 && loop > 0 && target != NULL)
			{
				if (ALL->Lb->first->aligne_next == true && ALL->Lb->first->next != NULL)
					loop++;
				ALL->Move = insert_data_Dlist(ALL->Move, all_move(ALL->La, ALL->Lb, pa), 1);
				loop--;
			}
		}
	}
}