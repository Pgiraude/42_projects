/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:07:30 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 14:07:30 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

e_bool	is_empty_list(t_list *list)
{
	if (list)
		return (false);
	else
		return (true);
}

t_list	*create_list(t_list *list)
{
	if (is_empty_list(list))
	{
		list = malloc(sizeof(*list));
		if (!list)
			return (NULL);
		list->len = 0;
		list->first = NULL;
		list->last = NULL;
		return (list);
	}
	return (list);
}

t_list	*insertlast_data_list(t_list *list, int data)
{
	t_cell	*cell;

	cell = malloc(sizeof(*cell));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
	cell->back = NULL;
	if (is_empty_list(list) || list->len == 0)
	{
		list = create_list(list);
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

t_list	*insertfirst_data_list(t_list *list, int data)
{
	t_cell	*cell;

	cell = malloc(sizeof(*cell));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
	cell->back = NULL;
	if (is_empty_list(list) || list->len == 0)
	{
		list = create_list(list);
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

t_list	*insert_data_list(t_list *list, int data, int mode)
{
	if (mode == 0)
		return(insertfirst_data_list(list, data));
	else
		return(insertlast_data_list(list, data));
}