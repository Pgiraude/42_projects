
#include "push_swap.h"


List    *isolate_lastcell_Dlist(DList *L)
{
    List *cell;

    cell = NULL;
    if (is_empty_Dlist(L))
        return (NULL);
    if (L->len != 1)
        return (NULL);
    if (L->first == L->last)
    {
        cell = L->first;
        cell->next = NULL;
        cell->back = NULL;
        L->first = NULL;
        L->last = NULL;
        L->len--;
    }
    return (cell);
}

List    *isolate_cell_Dlist(DList *L, int Mode)
{
    List *cell;

    cell = isolate_lastcell_Dlist(L);
    if (cell != NULL)
        return (cell);
    if (Mode == 0)
    {
        cell = L->first;
        L->first = L->first->next;
        L->first->back = NULL;
        cell->next = NULL;
        cell->back = NULL;
        L->len--;
    }
    if (Mode != 0)
    {
        cell = L->last;
        L->last = L->last->back;
        L->last->next = NULL;
        cell->next = NULL;
        cell->back = NULL;
        L->len--;
    }
    return (cell);
}



DList   *insertlast_cell_Dlist(DList *L, List *li)
{
    if (is_empty_Dlist(L))
    {
        L = malloc(sizeof(*L));
        if (!L)
            return (NULL);
        L->len = 0;
        L->first = li;
        L->last = li;
    }
    else if (L->len == 0)
    {
        L->first = li;
        L->last = li;
    }
    else
    {
        L->last->next = li;
        li->back = L->last;
        L->last = li;
    }
    L->len++;
    return (L);
}

DList   *insertfirst_cell_Dlist(DList *L, List *li)
{
    if (is_empty_Dlist(L))
    {
        L = malloc(sizeof(*L));
        if (!L)
            return (NULL);
        L->len = 0;
        L->first = li;
        L->last = li;
    }
    else if (L->len == 0)
    {
        L->first = li;
        L->last = li;
    }
    else
    {
        L->first->back = li;
        li->next = L->first;
        L->first = li;
    }
    L->len++;
    return (L);
}

DList    *insert_cell_Dlist(DList *L, List *cell, int mode)
{
    if (mode == 0)
        L = insertfirst_cell_Dlist(L, cell);
    else
        L = insertlast_cell_Dlist(L, cell);
    return (L);
}