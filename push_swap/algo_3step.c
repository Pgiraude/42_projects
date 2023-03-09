/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:35:36 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/09 14:07:04 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

Bool    Lb_is_aligned_swap(DList *ListB, DDList *ALL)
{
    List *cell;
    List *next_cell;
    int i;

    i = 1;
    if (ListB->len < 4)
        return (false);
    cell = ListB->first;
    next_cell = ListB->first->next;
    while (i <= 2)
    {
        if (!(cell->target_pos == next_cell->target_pos - 1 || 
        (cell->target_pos == ALL->max_len && next_cell->target_pos == 1)))
            return (false);
        if (i != 2)
        {
            cell = cell->next;
            next_cell = next_cell->next->next;
            if (cell->target_pos < next_cell->target_pos)
                return (false);
            cell = cell->next;
        }
        i++;
    }
    return (true);
}

Bool    bigswap_optimisation(DDList *ALL)
{
    List *cell;
    int i;

    if (ALL->Lb->len < 4)
        return (false);
    cell = ALL->Lb->first;
    i = 1;
    while (i <= 4)
    {
        if (cell->aligne_next == true)
            return (false);
        i++;
        cell = cell->next;
    }
    if (Lb_is_aligned_swap(ALL->Lb, ALL) == false)
        return (false);
    ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pa), 1);
    ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pa), 1);
    ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, ss), 1);
    return (true);
}

void    swap_optimisation(DDList *ALL)
{
    List *listB;

    if (ALL->Lb->len < 2 || ALL->La->len < 2)
        return ;
    listB = ALL->Lb->first;
    
}

/*-------------------------------------------------*/

List    *target_lower_cost(int costA, int costB, List *target)
{
    static List *last_target;
    static int  last_Tcost;
    int         Tcost;
    
    Tcost = costA + costB + target->bonus_cost;
    if (last_target == NULL)
    {
        ft_printf("test\n");
        last_target = target;
        last_Tcost = Tcost;
        return (last_target);
    }
    else if (Tcost < last_Tcost)
    {
        last_target = target;
        last_Tcost = Tcost;
    }
    else if (Tcost == last_Tcost && target->target_pos > last_target->target_pos)
    {
        last_target = target;
        last_Tcost = Tcost;
    }
    return (last_target);
}

List    *target_to_pushA(DDList *ALL)
{
    List *cell;
    List *target;
    int signA;
    int signB;

    target = NULL;
    cell = ALL->Lb->first;
    while (cell != NULL)
    {
        signB = 1;
        signA = 1;
        if (cell->costA < 0)
            signA = -1;
        if (cell->costB < 0)
            signB = -1;
        target = target_lower_cost((cell->costA * signA), (cell->costB * signB), cell);
        cell = cell->next;
    }
    return (target);
}

void    placeup_target_ListB(DDList *ALL, List *target)
{
    if (target == NULL)
        return ;
    while (target->costB > 0 && target->costA > 0)
    {
        target->moveB = false;
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rr), 1);
        target->costB--;
        target->costA--;
    }
    if (target->moveB == true && target->costA < 0)
        target->costB = target->costB * -1;
    while (target->costB < 0 && target->costA < 0)
    {
        target->moveB = false;
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rrr), 1);
        target->costB++;
        target->costA++;
    }

    while (target->costB > 0)
    {
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rb), 1);
        target->costB--;
    }
    while (target->costB < 0)
    {
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rrb), 1);
        target->costB++;
    }
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

void    algo_3step(DDList *ALL)
{
    List *target;
    // int loop;

    target = target_to_pushA(ALL);
    ft_printf("target=%d\n", target->data);
    
    // placeup_target_ListB(ALL, target);
    // if (bigswap_optimisation(ALL) == false)
    // {
    //     loop = 1;
    //     while (ALL->Lb->len > 0 && loop > 0)
    //     {
    //         if (ALL->Lb->first->aligne_next == true && ALL->Lb->first->next != NULL)
    //             loop++;
    //         ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pa), 1);
    //         loop--;
    //     }
    // }
}