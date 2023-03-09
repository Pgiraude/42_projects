
#include "push_swap.h"


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