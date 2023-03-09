/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_swap_optimisation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:28:58 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/09 16:29:30 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Bool    Lb_is_aligned_bigswap(DList *ListB, DDList *ALL)
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
    if (Lb_is_aligned_bigswap(ALL->Lb, ALL) == false)
        return (false);
    ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pa), 1);
    ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pa), 1);
    ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, ss), 1);
    return (true);
}

Bool    Lb_is_aligned_swap(DDList *ALL)
{
    List *cellb;
    List *cella;
    
    if (ALL->Lb->len < 2)
        return (false);
    cella = ALL->La->first;
    cellb = ALL->Lb->first;
    if (cella->aligne_next == false)
        return (false);
    if (!((cellb->target_pos == cellb->next->target_pos - 1) ||
    (cellb->target_pos == ALL->max_len && cellb->next->target_pos == 1)))
        return (false);
    cellb = cellb->next;
    if (!((cellb->target_pos == cella->target_pos - 1) ||
    (cellb->target_pos == ALL->max_len && cella->target_pos == 1)))
        return (false);
    return (true);
}

void    swap_optimisation(DDList *ALL)
{
    List *first_pos;
    
    if (Lb_is_aligned_swap(ALL) == true)
    {
        All_move(ALL->La, ALL->Lb, sb);
        All_move(ALL->La, ALL->Lb, pa);
        All_move(ALL->La, ALL->Lb, pa);
        if (ALL->Lb->len == 0)
        {
            first_pos = ALL->La->first;
            costA_getup_La(ALL->La);
            while (first_pos->target_pos != 1)
                first_pos = first_pos->next;
            if (first_pos->costA > 0)
            {
                All_move(ALL->La, ALL->Lb, sa);
                All_move(ALL->La, ALL->Lb, pb);
                All_move(ALL->La, ALL->Lb, pb);
                return ;
            }
        }
        ALL->Move = insert_data_Dlist(ALL->Move, sb, 1);
        ALL->Move = insert_data_Dlist(ALL->Move, pa, 1);
        ALL->Move = insert_data_Dlist(ALL->Move, pa, 1);
    }
}
