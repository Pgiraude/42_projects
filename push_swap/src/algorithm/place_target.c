/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_target.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:09:18 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 12:12:57 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	placeup_bigmove_listb(t_ctrl *all, t_cell *target)
{
	while ((target->cost_b < 0 && target->cost_a < 0)
		|| (target->move_a == true && target->cost_b < 0)
		|| (target->move_b == true && target->cost_a < 0))
	{
		if (target->move_a == true)
		{
			target->cost_a = target->cost_a * -1;
			target->move_a = false;
		}
		if (target->move_b == true)
		{
			target->cost_b = target->cost_b * -1;
			target->move_b = false;
		}
		all_move(all->list_a, all->list_b, rrr);
		all->move = insert_data_list(all->move, rrr, 1);
		target->cost_a++;
		target->cost_b++;
		target->bonus_cost++;
	}
}

void	placeup_otherbigmove_listb(t_ctrl *all, t_cell *target)
{
	while (target->cost_b > 0 && target->cost_a > 0)
	{
		all_move(all->list_a, all->list_b, rr);
		all->move = insert_data_list(all->move, rr, 1);
		target->cost_b--;
		target->cost_a--;
		target->bonus_cost++;
	}
}

void	placeup_remain_listb(t_ctrl *all, t_cell *target)
{
	while (target->cost_b > 0)
	{
		all_move(all->list_a, all->list_b, rb);
		all->move = insert_data_list(all->move, rb, 1);
		target->cost_b--;
	}
	while (target->cost_b < 0)
	{
		all_move(all->list_a, all->list_b, rrb);
		all->move = insert_data_list(all->move, rrb, 1);
		target->cost_b++;
	}
	while (target->cost_a > 0)
	{
		all_move(all->list_a, all->list_b, ra);
		all->move = insert_data_list(all->move, ra, 1);
		target->cost_a--;
	}
	while (target->cost_a < 0)
	{
		all_move(all->list_a, all->list_b, rra);
		all->move = insert_data_list(all->move, rra, 1);
		target->cost_a++;
	}
}

void	place_target_listb(t_ctrl *all, t_cell *target)
{
	if (target == NULL)
		return ;
	placeup_bigmove_listb(all, target);
	placeup_otherbigmove_listb(all, target);
	placeup_remain_listb(all, target);
	target->move_a = false;
	target->move_b = false;
}

void	placeup_target_lista(t_ctrl *all, t_cell *target)
{
	if (target == NULL)
		return ;
	target->tag = false;
	placeup_bigmove_listb(all, target);
	placeup_otherbigmove_listb(all, target);
	while (target->cost_a > 0)
	{
		all_move(all->list_a, all->list_b, ra);
		all->move = insert_data_list(all->move, ra, 1);
		target->cost_a--;
	}
	while (target->cost_a < 0)
	{
		all_move(all->list_a, all->list_b, rra);
		all->move = insert_data_list(all->move, rra, 1);
		target->cost_a++;
	}
}
