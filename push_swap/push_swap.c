/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:49:14 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/16 13:52:40 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_all_cell(DDList *ALL)
{
    List *listA;

    listA = ALL->La->first;
    ALL->max_len = ALL->La->len;
    while(listA != NULL)
    {
        listA->costA = 0;
        listA->costB = 0;
        listA->target_pos = 0;
        listA->get_pb = false;
        listA->move = false;
            Bool aligne_back;
            aligne_next;
        listA = listA->next;
    }
}

void    push_swap(DDList *ALL)
{
    set_all_cell(ALL);
}