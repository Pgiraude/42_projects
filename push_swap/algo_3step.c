

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

Bool    swap_optimisation(DDList *ALL)
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

List    *target_to_pushA(DDList *ALL)
{
    List *cell;
    List *target;
    int signA;
    int signB;
    int lower_cost;

    target = NULL;
    cell = ALL->Lb->first;
    lower_cost = ALL->max_len;
    while (cell != NULL)
    {
        if (cell->costA >= 0)
            signA = 1;
        else
            signA = -1;
        if (cell->costB >= 0)
            signB = 1;
        else
            signB = -1;
        if (lower_cost > (cell->costA * signA + cell->costB * signB))
        {
            lower_cost = cell->costA * signA + cell->costB * signB;
            target = cell;
        }
        cell = cell->next;
    }
    return (target);
}

void    placeup_target_ListB(DDList *ALL, List *target)
{


    while (target->costB > 0 && target->costA > 0)
    {
        target->move = false;
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rr), 1);
        target->costB--;
        target->costA--;
    }
    if (target->move == true && target->costA < 0)
        target->costB = target->costB * -1;
    while (target->costB < 0 && target->costA < 0)
    {
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
    int loop;

    target = target_to_pushA(ALL);
    placeup_target_ListB(ALL, target);
    if (swap_optimisation(ALL) == false)
    {
        loop = 1;
        while (ALL->Lb->len > 0 && loop > 0)
        {
            if (ALL->Lb->first->aligne_next == true && ALL->Lb->first->next != NULL)
                loop++;
            ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pa), 1);
            loop--;
        }
    }
}