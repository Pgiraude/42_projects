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

void	free_all_dlist(DList *d_list)
{
	List	*tmp;

	if (is_empty_Dlist(d_list))
		return ;
	while (d_list->first != d_list->last)
	{
		tmp = d_list->first;
		d_list->first = d_list->first->next;
		d_list->first->back = NULL;
		tmp->next = NULL;
		free (tmp);
		tmp = NULL;
	}
	if (d_list->first == d_list->last)
	{
		tmp = d_list->first;
		free(tmp);
		free(d_list);
		d_list = NULL;
	}
}
