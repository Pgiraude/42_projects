
#include "push_swap.h"


void    Lb_is_aligned_next(DList *ListB, DDList *ALL)
{
    List *cell;
    List *next_cell;
    int i;

    if (ListB->len < 2)
        return ;
    cell = ListB->first;
    next_cell = ListB->first->next;
    i = 1;
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

    if (ListB->len < 2)
        return ;
    cell = ListB->last;
    back_cell = ListB->last->back;
    i = 1;
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

    if (ListA->len < 2)
        return ;
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

    if (ListA->len < 2)
        return ;
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

Bool    check_is_aligned(List *target, List *compare, int max_len, int mode)
{
    if (mode == 0)
    {
        if (target->target_pos == compare->target_pos + 1)
            return (true);
        else if (target->target_pos == 1 && compare->target_pos == max_len)
            return (true);
    }
    else if (mode == 1)
    {
        if (target->target_pos == compare->target_pos - 1)
            return (true);
        if (target->target_pos == max_len && compare->target_pos == 1)
            return (true);
    }
    return (false);
}

void    is_aligned(DDList *ALL)
{
    La_is_aligned_next(ALL->La, ALL);
    La_is_aligned_back(ALL->La, ALL);
    Lb_is_aligned_next(ALL->Lb, ALL);
    Lb_is_aligned_back(ALL->Lb, ALL);
}