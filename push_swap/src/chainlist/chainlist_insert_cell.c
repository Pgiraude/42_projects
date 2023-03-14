/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist_insert_cell.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:07:24 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 14:09:16 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*insertlast_cell_list(t_list *list, t_cell *cell)
{
	if (is_empty_list(list))
	{
		list = malloc(sizeof(*list));
		if (!list)
			return (NULL);
		list->len = 0;
		list->first = cell;
		list->last = cell;
	}
	else if (list->len == 0)
	{
		list->first = cell;
		list->last = cell;
	}
	else
	{
		list->last->next = cell;
		cell->back = list->last;
		list->last = cell;
	}
	list->len++;
	return (list);
}

t_list	*insertfirst_cell_list(t_list *list, t_cell *cell)
{
	if (is_empty_list(list))
	{
		list = malloc(sizeof(*list));
		if (!list)
			return (NULL);
		list->len = 0;
		list->first = cell;
		list->last = cell;
	}
	else if (list->len == 0)
	{
		list->first = cell;
		list->last = cell;
	}
	else
	{
		list->first->back = cell;
		cell->next = list->first;
		list->first = cell;
	}
	list->len++;
	return (list);
}

t_list	*insert_cell_list(t_list *list, t_cell *cell, int mode)
{
	if (mode == 0)
		list = insertfirst_cell_list(list, cell);
	else
		list = insertlast_cell_list(list, cell);
	return (list);
}

t_cell	*isolate_lastcell_list(t_list *list)
{
	t_cell	*cell;

	cell = NULL;
	if (is_empty_list(list))
		return (NULL);
	if (list->len != 1)
		return (NULL);
	if (list->first == list->last)
	{
		cell = list->first;
		cell->next = NULL;
		cell->back = NULL;
		list->first = NULL;
		list->last = NULL;
		list->len--;
	}
	return (cell);
}

t_cell	*isolate_cell_list(t_list *list, int Mode)
{
	t_cell	*cell;

	cell = isolate_lastcell_list(list);
	if (cell != NULL)
		return (cell);
	if (Mode == 0)
	{
		cell = list->first;
		list->first = list->first->next;
		list->first->back = NULL;
		cell->next = NULL;
		cell->back = NULL;
		list->len--;
	}
	if (Mode != 0)
	{
		cell = list->last;
		list->last = list->last->back;
		list->last->next = NULL;
		cell->next = NULL;
		cell->back = NULL;
		list->len--;
	}
	return (cell);
}