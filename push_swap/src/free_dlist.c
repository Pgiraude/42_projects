/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:40:04 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 18:42:34 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_all_dlist(DList *list)
{
	List	*cell;

	if (is_empty_Dlist(list))
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
