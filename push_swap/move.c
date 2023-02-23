

#include "push_swap.h"

void    swap_move(DList *L)
{
    List *cellA;
    List *cellB;

    cellA = NULL;
    cellB = NULL;
    if (is_empty_Dlist(L) || L->len < 2)
        return ;
    cellA = isolate_cell_Dlist(L, 0);
    cellB = isolate_cell_Dlist(L, 0);
    L = insert_cell_Dlist(L, cellA, 0);
    L = insert_cell_Dlist(L, cellB, 0);
}

void    rup_move(DList *L)
{
    List *cell;

    cell = NULL;
    if (is_empty_Dlist(L) || L->len < 2)
        return ;
    cell = isolate_cell_Dlist(L, 0);
    L = insert_cell_Dlist(L, cell, 1);
}

void    rdo_move(DList *L)
{
    List *cell;

    cell = NULL;
    if (is_empty_Dlist(L) || L->len < 2)
        return ;
    cell = isolate_cell_Dlist(L, 1);
    L = insert_cell_Dlist(L, cell, 0);
}

void    p_move(DList *src, DList *dest)
{
    List *cell;

    if (is_empty_Dlist(src) || src->len == 0)
        return ;
    cell = isolate_cell_Dlist(src, 0);
    dest = insert_cell_Dlist(dest, cell, 0);
}