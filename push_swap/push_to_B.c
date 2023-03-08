/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_B.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:17 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/08 18:48:08 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void    placeup_target_ListA(DDList *ALL, List *target)
{
    int nbr_move;
    if (target == NULL)
        return ;
    target->tag = false;
    if (target->costA > 0)
    {
        nbr_move = target->costA;
        while (nbr_move != 0)
        {
            ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, ra), 1);
            nbr_move--;
        }
    }
    if (target->costA < 0)
    {
        nbr_move = target->costA * -1;
        while (nbr_move != 0)
        {
            ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rra), 1);
            nbr_move--;
        }
    }
}

List    *target_to_process(DDList *ALL)
{
    List *cell;
    List *target;
    int sign;
    int lower_cost;

    target = NULL;
    cell = ALL->La->first;
    lower_cost = ALL->max_len;
    while (cell != NULL)
    {
        if (cell->costA >= 0)
            sign = 1;
        else
            sign = -1;
        if (lower_cost > cell->costA * sign && cell->tag == true)
        {
            lower_cost = cell->costA * sign;
            target = cell;
        }
        cell = cell->next;
    }
    return (target);
}

void    cost_getup_La(DList *ListA)
{
    List *cell;
    int paire;
    int i;

    paire = 0;
    if (ListA->len % 2 == 0)
        paire = 1;
    cell = ListA->first;
    i = 0;
    while (cell != NULL)
    {
        cell->move = false;
        if (i <= ListA->len / 2)
            cell->costA = i;
        if (i == ListA->len / 2 && paire == 1)
            cell->move = true;
        if (i > ListA->len / 2)
            cell->costA = i - ListA->len;
        i++;
        cell = cell->next;
    }
}

/*------------------------------------------------------------------*/


int see_further(List *cell, DDList *ALL)
{
    int i;

    i = 1;
    while (i++ <= 2)
    {
        if (cell->next == NULL)
            cell = ALL->La->first;
        else
            cell = cell->next;
    }
    return (cell->target_pos);
}

void    target_to_swapA(DDList *ALL)
{
    List *cell;
    List *cell_back;
    int further_pos;
    int found;

    cell = ALL->La->first;
    cell_back = ALL->La->last;
    while (cell != NULL)
    {
        found = 0;
        cell->tag = false;
        further_pos = see_further(cell_back, ALL);
        if (cell_back->target_pos == further_pos - 1 ||
         (cell_back->target_pos == ALL->max_len && further_pos == 1))
            found++;
        further_pos = see_further(cell, ALL);
        if (cell->target_pos == further_pos - 1 ||
         (cell->target_pos == ALL->max_len && further_pos == 1))
            found++;
        if (found == 2)
            cell->tag = true;
        cell_back = cell;
        cell = cell->next;
    }
}

/*---------------------------------------------*/


void    push_to_B(DDList *ALL)
{

    List *target;

    target_to_swapA(ALL);
    cost_getup_La(ALL->La);
    target = target_to_process(ALL);
    placeup_target_ListA(ALL, target);
    ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, sa), 1);

    // int i;
    // int nbr_pb;
    // nbr_pb = get_pb_optimisation(ALL);
    // target = NULL;
    // i = 1;
    // while(i <= nbr_pb)
    // {
    //     cost_getup_La(ALL->La);
    //     target = target_to_pushB(ALL);
    //     placeup_target_ListA(ALL, target);
    //     ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    //     i++;
    // }
}