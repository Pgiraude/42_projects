

#include "../push_swap.h"

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

void    push_move(DList *src, DList *dest)
{
    List *cell;

    if (is_empty_Dlist(src) || src->len == 0)
        return ;
    cell = isolate_cell_Dlist(src, 0);
    dest = insert_cell_Dlist(dest, cell, 0);
}

/*-------------------------*/

int    P_move(DList *La, DList *Lb, Move mode)
{
    if (mode == pa && Lb->len >= 1)
        push_move(Lb, La);
    else if (mode == pb && La->len >= 1)
        push_move(La, Lb);
    else
        return (-1);
    return (mode);
}

int    S_move(DList *La, DList *Lb, Move mode)
{
    if (mode == sa && La->len >= 2)
        swap_move(La);
    else if (mode == sb && Lb->len >= 2)
        swap_move(Lb);
    else if (mode == ss && La->len >= 2 && Lb->len >= 2)
    {
        swap_move(La);
        swap_move(Lb);
    }
    else
        return (-1);
    return (mode);
}

int    R_move(DList *La, DList *Lb, Move mode)
{
    if (mode == ra && La->len >= 2)
        rup_move(La);
    else if (mode == rb && Lb->len >= 2)
        rup_move(Lb);
    else if (mode == rr && La->len >= 2 && Lb->len >= 2)
    {
        rup_move(La);
        rup_move(Lb);
    }
    else if (mode == rra && La->len >= 2)
        rdo_move(La);
    else if (mode == rrb && Lb->len >= 2)
        rdo_move(Lb);
    else if (mode == rrr && La->len >= 2 && Lb->len >= 2)
    {
        rup_move(La);
        rup_move(Lb);
    }
    else
        return (-1);
    return (mode);
}

int    all_move(DList *La, DList * Lb, Move mode)
{
    int check_error;

    if (mode == pa || mode == pb)
        check_error = P_move(La, Lb, mode);
    else if (mode == sa || mode == sb || mode == ss)
        check_error = S_move(La, Lb, mode);
    else if (mode == ra || mode == rb || mode == rr)
        check_error = R_move(La, Lb, mode);
    else if (mode == rra || mode == rrb || mode == rrr)
        check_error = R_move(La, Lb, mode);
    else
        check_error = -1;
    return (check_error);
}