/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/09 10:14:22 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void    costB_getup_Lb(DList *ListB)
{
    List *cell;
    int paire;
    int i;

    paire = 0;
    if (ListB->len % 2 == 0)
        paire = 1;
    cell = ListB->first;
    i = 0;
    while (cell != NULL)
    {
        cell->moveB = false;
        if (i <= ListB->len / 2)
            cell->costB = i;
        if (i == ListB->len / 2 && paire == 1)
            cell->moveB = true;
        if (i > ListB->len / 2)
            cell->costB = i - ListB->len;
        i++;
        cell = cell->next;
    }
}

void    costA_getposition_Lb(DList *ListA, DList *ListB, DDList *ALL)
{
    List *cellA;
    List *cellA_back;
    List *cellB;
    int mem;
    int i;
    int paire;
    
    paire = 0;
    if (ListA->len % 2 == 0)
        paire = 1;

    cellB = ListB->first;
    while (cellB != NULL)
    {

        mem = 0;
        cellA_back = ListA->last;
        cellA = ListA->first;
        i = 0;
        while (cellA != NULL)
        {
            if (cellA->aligne_back == true)
            {
                if (i != ListA->len - 1)
                    i++;
                cellA_back = cellA;
                cellA = cellA->next;
            }
            else
            {
                if (cellA->target_pos > cellB->target_pos)
                    mem = i;
                else if (cellA_back->target_pos < cellB->target_pos)
                    mem = i;
                else if (cellA->target_pos == 1 && cellB->target_pos == ALL->max_len)
                    mem = i;
                else if (cellA_back->target_pos == ALL->max_len && cellB->target_pos == 1)
                    mem = i;
                if (i != ListA->len - 1)
                    i++;
                cellA_back = cellA;
                cellA = cellA->next;
            }
        }
        

        if (mem <= ListA->len / 2)
            cellB->costA = mem;
        if (mem == ListA->len / 2 && paire == 1)
            cellB->moveA = true;
        if (mem > ListA->len / 2)
            cellB->costA = mem - ListA->len;
        cellB = cellB->next;
    }
}

/*-------------------------------------*/



void    get_all_cost(DDList *ALL)
{
    is_aligned(ALL);
    costB_getup_Lb(ALL->Lb);
    costA_getposition_Lb(ALL->La, ALL->Lb, ALL);
}