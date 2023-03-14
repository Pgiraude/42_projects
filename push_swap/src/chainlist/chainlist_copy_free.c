/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chainlist_copy_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:40:04 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 14:07:43 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*duplicate_list(t_list *list)
{
	t_list	*duplicate;
	t_cell	*cell;

	duplicate = NULL;
	duplicate = create_list(duplicate);
	cell = list->first;
	while (cell != NULL)
	{
		duplicate = insert_data_list(duplicate, cell->data, 1);
		cell = cell->next;
	}
	return (duplicate);
}

void	free_all_list(t_list *list)
{
	t_cell	*cell;

	if (is_empty_list(list))
		return ;
	while (list->first != list->last)
	{
		cell = list->first;
		list->first = list->first->next;
		list->first->back = NULL;
		cell->next = NULL;
		free (cell);
		cell = NULL;
	}
	if (list->first == list->last)
	{
		cell = list->first;
		if (list->len == 1)
			free(cell);
		free(list);
		list = NULL;
	}
}
