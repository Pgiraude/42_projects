/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:28:11 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/17 13:28:57 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_all_list(t_ctrl *all)
{
	t_list	*list_a;
	t_list	*list_b;
	t_list	*move;

	list_a = NULL;
	list_b = NULL;
	move = NULL;
	list_a = create_list(list_a);
	list_b = create_list(list_b);
	move = create_list(move);
	all->list_a = list_a;
	all->list_b = list_b;
	all->move = move;
}

void	set_all_cell(t_ctrl *all)
{
	t_cell	*cell_a;

	cell_a = all->list_a->first;
	all->max_len = all->list_a->len;
	while (cell_a != NULL)
	{
		cell_a->cost_a = 0;
		cell_a->cost_b = 0;
		cell_a->bonus_cost = 0;
		cell_a->final_pos = 0;
		cell_a->tag = false;
		cell_a->move_a = false;
		cell_a->move_b = false;
		cell_a = cell_a->next;
	}
}

void	get_final_pos(t_ctrl *all)
{
	t_list	*list_s;
	t_cell	*cell_a;
	t_cell	*cell_s;
	int		final_pos;

	list_s = duplicate_list(all->list_a);
	quick_sort(list_s);
	cell_a = all->list_a->first;
	while (cell_a != NULL)
	{
		final_pos = 1;
		cell_s = list_s->first;
		while (cell_a->data != cell_s->data)
		{
			final_pos++;
			cell_s = cell_s->next;
		}
		cell_a->final_pos = final_pos;
		cell_a = cell_a->next;
	}
	free_all_list(list_s);
}
