/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/08 18:35:41 by pgiraude         ###   ########.fr       */
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
        cell->move = false;
        if (i <= ListB->len / 2)
            cell->costB = i;
        if (i == ListB->len / 2 && paire == 1)
            cell->move = true;
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

    // int paire; si je rajoute autre booléen
    // paire = 0;
    // if (ListA->len % 2 == 0)
    //     paire = 1;

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
        // if (mem == ListB->len / 2 && paire == 1) si je rajoute autre booleen
        //     cell->move = true;
        if (mem > ListA->len / 2)
            cellB->costA = mem - ListA->len;
        cellB = cellB->next;
    }
}

/*-------------------------------------*/

void    Lb_is_aligned_next(DList *ListB, DDList *ALL)
{
    List *cell;
    List *next_cell;
    int i;

    i = 1;
    cell = ListB->first;
    next_cell = ListB->first->next;
    while (i <= ListB->len)
    {
        cell->aligne_next = false;
        if (next_cell == NULL)
            next_cell = ListB->first;
        if (cell->target_pos == next_cell->target_pos + 1)
            cell->aligne_next = true;
        else if (cell->target_pos == 1 && next_cell->target_pos == ALL->max_len)
            cell->aligne_next = true;
        next_cell = next_cell->next;
        cell = cell->next;
        i++;
    }
}

void    Lb_is_aligned_back(DList *ListB, DDList *ALL)
{
    List *cell;
    List *back_cell;
    int i;

    i = 1;
    cell = ListB->last;
    back_cell = ListB->last->back;
    while (i <= ListB->len)
    {
        cell->aligne_back = false;
        if (back_cell == NULL)
            back_cell = ListB->last;
        if (cell->target_pos == back_cell->target_pos - 1)
            cell->aligne_back = true;
        else if (cell->target_pos == ALL->max_len && back_cell->target_pos == 1)
            cell->aligne_back = true;
        back_cell = back_cell->back;
        cell = cell->back;
        i++;
    }
}

void    La_is_aligned_next(DList *ListA, DDList *ALL)
{
    List *cell;
    List *next_cell;
    int i;

    i = 1;
    cell = ListA->first;
    next_cell = ListA->first->next;
    while (i <= ListA->len)
    {
        cell->aligne_next = false;
        if (next_cell == NULL)
            next_cell = ListA->first;
        if (cell->target_pos == next_cell->target_pos - 1)
            cell->aligne_next = true;
        else if (cell->target_pos == ALL->max_len && next_cell->target_pos == 1)
            cell->aligne_next = true;
        next_cell = next_cell->next;
        cell = cell->next;
        i++;
    }
}

void    La_is_aligned_back(DList *ListA, DDList *ALL)
{
    List *cell;
    List *back_cell;
    int i;

    i = 1;
    cell = ListA->last;
    back_cell = ListA->last->back;
    while (i <= ListA->len)
    {
        cell->aligne_back = false;
        if (back_cell == NULL)
            back_cell = ListA->last;
        if (cell->target_pos == back_cell->target_pos + 1)
            cell->aligne_back = true;
        else if (cell->target_pos == 1 && back_cell->target_pos == ALL->max_len)
            cell->aligne_back = true;
        back_cell = back_cell->back;
        cell = cell->back;
        i++;
    }
}

void    is_aligned(DDList *ALL)
{
    La_is_aligned_next(ALL->La, ALL);
    La_is_aligned_back(ALL->La, ALL);

    Lb_is_aligned_next(ALL->Lb, ALL);
    Lb_is_aligned_back(ALL->Lb, ALL);
}

void    algo_2step(DDList *ALL)
{
    is_aligned(ALL);
    costB_getup_Lb(ALL->Lb);
    costA_getposition_Lb(ALL->La, ALL->Lb, ALL);
}