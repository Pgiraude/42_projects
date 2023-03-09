/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_B.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:17 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/09 17:07:22 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

void    placeup_target_ListA(DDList *ALL, List *target)
{
    if (target == NULL)
        return ;
    target->tag = false;
    while (target->costA > 0)
    {
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, ra), 1);
        target->costA--;
    }

    while (target->costA < 0)
    {
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rra), 1);
        target->costA++;
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

int    target_to_swapA(DDList *ALL)
{
    List *cell;
    List *cell_back;
    int further_pos;
    int nbr_swap;

    nbr_swap = 0;
    cell = ALL->La->first;
    cell_back = ALL->La->last;
    while (cell != NULL)
    {
        cell->tag = false;
        further_pos = see_further(cell_back, ALL);
        if (cell_back->target_pos == further_pos - 1 ||
        (cell_back->target_pos == ALL->max_len && further_pos == 1))
        {
            further_pos = see_further(cell, ALL);
            if (cell->target_pos == further_pos - 1 ||
            (cell->target_pos == ALL->max_len && further_pos == 1))
            {
                cell->tag = true;
                nbr_swap++;
            }
        }
        cell_back = cell;
        cell = cell->next;
    }
    return (nbr_swap);
}

/*---------------------------------------------*/


void    push_to_B(DDList *ALL)
{
    List *target;
    int i;
    int nbr;

    nbr = target_to_swapA(ALL);
    while (nbr != 0)
    {
        costA_getup_La(ALL->La);
        target = target_to_process(ALL);
        placeup_target_ListA(ALL, target);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, sa), 1);
        nbr = target_to_swapA(ALL);
    }

    nbr = get_pb_optimisation(ALL);
    while(i <= nbr)
    {
        costA_getup_La(ALL->La);
        target = target_to_process(ALL);
        placeup_target_ListA(ALL, target);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
        i++;
    }
}