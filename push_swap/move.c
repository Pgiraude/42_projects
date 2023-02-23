

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

/*-------------------------*/

void    P_move(DList *La, DList *Lb, int mode)
{
    if (mode == 0 && La->len >= 1)
        p_move(La, Lb);
    if (mode == 1 && Lb->len >= 1)
        p_move(Lb, La);    
}

void    S_move(DList *La, DList *Lb, int mode)
{
    if (mode == 0)
        swap_move(La);
    if (mode == 1)
        swap_move(Lb);
    if (mode == 2 && La->len >= 2 && Lb->len >= 2)
    {
        swap_move(La);
        swap_move(Lb);
    }
}

void    R_move(DList *La, DList *Lb, int mode)
{
    if (mode == 0)
        rup_move(La);
    if (mode == 1)
        rup_move(Lb);
    if (mode == 2 && La->len >= 2 && Lb->len >= 2)
    {
        rup_move(La);
        rup_move(Lb);
    }


    if (mode == 3)
        rdo_move(La);
    if (mode == 4)
        rdo_move(Lb);
    if (mode == 5 && La->len >= 2 && Lb->len >= 2)
    {
        rup_move(La);
        rup_move(Lb);
    }
}