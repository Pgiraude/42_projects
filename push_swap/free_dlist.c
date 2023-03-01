/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:45:37 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/01 16:47:26 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_all_Dlist(DList *L)
{
    List *tmp;

    if (is_empty_Dlist(L))
        return ;
    while(L->first != L->last)
    {
        tmp = L->first;
        L->first = L->first->next;
        L->first->back = NULL;
        tmp->next = NULL;
        free (tmp);
        tmp = NULL;
    }
    if (L->first == L->last)
    {
        tmp = L->first;
        free(tmp);
        free(L);
        L = NULL;
    }
}