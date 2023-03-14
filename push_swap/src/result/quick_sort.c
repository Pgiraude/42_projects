/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:08:02 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 12:16:38 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fusion_list(t_list *list_inf, t_list *pivot, t_list *list_sup)
{
	if (!is_empty_list(list_inf))
	{
		list_inf->last->next = pivot->first;
		pivot->last->back = list_inf->last;
		pivot->first = list_inf->first;
		list_inf->first = NULL;
		list_inf->last = NULL;
		pivot->len = pivot->len + list_inf->len;
		free (list_inf);
	}
	if (!is_empty_list(list_sup))
	{
		list_sup->first->back = pivot->last;
		pivot->last->next = list_sup->first;
		pivot->last = list_sup->last;
		list_sup->first = NULL;
		list_sup->last = NULL;
		pivot->len = pivot->len + list_sup->len;
		free (list_sup);
	}
}

void	quicksort_split(t_list *list, t_list **list_inf, t_list **list_sup)
{
	t_cell *cell;

	cell = list->first;
	if (list->last->data > list->first->data)
	{
		list->first = list->first->next;
		list->first->back = NULL;
		cell->next = NULL;
		cell->back = NULL;
		list->len--;
		*list_inf = insert_cell_list(*list_inf, cell, 1);
	}
	else
	{
		list->first = list->first->next;
		list->first->back = NULL;
		cell->next = NULL;
		cell->back = NULL;
		list->len--;
		*list_sup = insert_cell_list(*list_sup, cell, 1);
	}
}

void	quick_sort(t_list *list)
{
	t_list	*list_sup;
	t_list	*list_inf;

	list_sup = NULL;
	list_inf = NULL;
	while (list->last != list->first)
	{
		quicksort_split(list, &list_inf, &list_sup);
	}
	if (!is_empty_list(list_inf))
	{
		if (list_inf->len != 1)
			quick_sort(list_inf);
	}
	if (!is_empty_list(list_sup))
	{
		if (list_sup->len != 1)
			quick_sort(list_sup);
	}
	fusion_list(list_inf, list, list_sup);
}