/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:46:37 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 19:18:44 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_move(DList *list)
{
	List	*cell_a;
	List	*cell_b;

	cell_a = NULL;
	cell_b = NULL;
	if (is_empty_Dlist(list) || list->len < 2)
		return ;
	cell_a = isolate_cell_Dlist(list, 0);
	cell_b = isolate_cell_Dlist(list, 0);
	list = insert_cell_Dlist(list, cell_a, 0);
	list = insert_cell_Dlist(list, cell_b, 0);
}

void	rup_move(DList *list)
{
	List	*cell;

	cell = NULL;
	if (is_empty_Dlist(list) || list->len < 2)
		return ;
	cell = isolate_cell_Dlist(list, 0);
	list = insert_cell_Dlist(list, cell, 1);
}

void	rdo_move(DList *list)
{
	List	*cell;

	cell = NULL;
	if (is_empty_Dlist(list) || list->len < 2)
		return ;
	cell = isolate_cell_Dlist(list, 1);
	list = insert_cell_Dlist(list, cell, 0);
}

void	push_move(DList *src, DList *dest)
{
	List	*cell;

	if (is_empty_Dlist(src) || src->len == 0)
		return ;
	cell = isolate_cell_Dlist(src, 0);
	dest = insert_cell_Dlist(dest, cell, 0);
}
