/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/09 12:38:46 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void    calculate_bonus_cost(DDList *ALL)
{
    List *cell;
    int sign;
    int i;

    cell = ALL->Lb->first;
    while (cell != NULL)
    {
        sign = 1;
        i = 0;
        if (i < cell->costA && i < cell->costB)
            while (i < cell->costA && i < cell->costB)
                i++;
        else if (i > cell->costA && i > cell->costB)
            while (i > cell->costA && i > cell->costB)
                i--;
        else if ((cell->moveA == true && i > cell->costB) || (cell->moveB == true && i > cell->costA))
            while (i > cell->costB || i > cell->costA)
                i--;
        if (i > 0)
            sign = -1;
        cell->bonus_cost = i * sign;        
        cell = cell->next;
    }
}

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


/*-------------------------------------------*/

int    costA_Lb(DDList *ALL, List *cellA_back, List *cellA, List *cellB)
{
    int cost;
    int i;

    cost = 0;
    i = 0;
    while (cellA != NULL)
    {
        if (cellA->aligne_back == false)
        {
            if (cellA->target_pos > cellB->target_pos)
                cost = i;
            else if (cellA_back->target_pos < cellB->target_pos)
                cost = i;
            else if (cellA->target_pos == 1 && cellB->target_pos == ALL->max_len)
                cost = i;
            else if (cellA_back->target_pos == ALL->max_len && cellB->target_pos == 1)
                cost = i;
        }
        i++;
        cellA_back = cellA;
        cellA = cellA->next;
    }
    return (cost);
}

void    costA_getposition_Lb(DList *ListA, DList *ListB, DDList *ALL)
{
    List *cellA;
    List *cellA_back;
    List *cellB;
    int cost;
    int paire;
    
    paire = 0;
    if (ListA->len % 2 == 0)
        paire = 1;
    cellB = ListB->first;
    while (cellB != NULL)
    {
        cellB->moveA = false;
        cellA_back = ListA->last;
        cellA = ListA->first;
        cost = costA_Lb(ALL, cellA_back, cellA, cellB);
        if (cost <= ListA->len / 2)
            cellB->costA = cost;
        if (cost == ListA->len / 2 && paire == 1)
            cellB->moveA = true;
        if (cost > ListA->len / 2)
            cellB->costA = cost - ListA->len;
        cellB = cellB->next;
    }
}

/*-------------------------------------*/



void    get_all_cost(DDList *ALL)
{
    is_aligned(ALL);
    costB_getup_Lb(ALL->Lb);
    costA_getposition_Lb(ALL->La, ALL->Lb, ALL);
    calculate_bonus_cost(ALL);
}