

#include "push_swap.h"

void    cost_getup_Lb(DList *ListB)
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

/*-------------------------------------*/

void    is_aligned_next(DList *ListA, DDList *ALL)
{
    List *cell;
    List *next_cell;
    int i;

    i = 1;
    cell = ListA->first;
    next_cell = ListA->first->next;
    while (i <= ListA->len)
    {
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

void    is_aligned_back(DList *ListA, DDList *ALL)
{
    List *cell;
    List *back_cell;
    int i;

    i = 1;
    cell = ListA->last;
    back_cell = ListA->last->back;
    while (i <= ListA->len)
    {
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
    is_aligned_next(ALL->La, ALL);
    is_aligned_back(ALL->La, ALL);
}

void    algo_2step(DDList *ALL)
{
    is_aligned(ALL);
    cost_getup_Lb(ALL->Lb);
}