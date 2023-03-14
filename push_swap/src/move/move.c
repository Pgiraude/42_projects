/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:46:37 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 14:00:23 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_move(t_list *list)
{
	t_cell	*cell_a;
	t_cell	*cell_b;

	cell_a = NULL;
	cell_b = NULL;
	if (is_empty_list(list) || list->len < 2)
		return ;
	cell_a = isolate_cell_list(list, 0);
	cell_b = isolate_cell_list(list, 0);
	list = insert_cell_list(list, cell_a, 0);
	list = insert_cell_list(list, cell_b, 0);
}

void	rup_move(t_list *list)
{
	t_cell	*cell;

	cell = NULL;
	if (is_empty_list(list) || list->len < 2)
		return ;
	cell = isolate_cell_list(list, 0);
	list = insert_cell_list(list, cell, 1);
}

void	rdo_move(t_list *list)
{
	t_cell	*cell;

	cell = NULL;
	if (is_empty_list(list) || list->len < 2)
		return ;
	cell = isolate_cell_list(list, 1);
	list = insert_cell_list(list, cell, 0);
}

void	push_move(t_list *src, t_list *dest)
{
	t_cell	*cell;

	if (is_empty_list(src) || src->len == 0)
		return ;
	cell = isolate_cell_list(src, 0);
	dest = insert_cell_list(dest, cell, 0);
}
