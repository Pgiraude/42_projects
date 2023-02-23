

#include "push_swap.h"

void   fusion_Dlist(DList *Inf, DList *Piv, DList *Sup)
{
    if (!is_empty_Dlist(Inf))
    {
        Inf->last->next = Piv->first;
        Piv->last->back = Inf->last;
        Piv->first = Inf->first;
        Inf->first = NULL;
        Inf->last = NULL;
        Piv->len = Piv->len + Inf->len;
        free (Inf);
    }
    if (!is_empty_Dlist(Sup))
    {
        Sup->first->back = Piv->last;
        Piv->last->next = Sup->first;
        Piv->last = Sup->last;
        Sup->first = NULL;
        Sup->last = NULL;
        Piv->len = Piv->len + Sup->len;
        free (Sup);
    }
}

void   quick_sort(DList *A)
{
    DList *Sup;
    DList *Inf;
    List *tmp;

    Sup = NULL;
    Inf = NULL;
    // Sup = create_Dlist(Sup);
    // Inf = create_Dlist(Inf);

    while (A->last != A->first)
    {
        if (A->last->data > A->first->data)
        {
            tmp = A->first;
            A->first = A->first->next;
            A->first->back = NULL;
            tmp->next = NULL;
            tmp->back = NULL;
            A->len--;
            Inf = insert_cell_Dlist(Inf, tmp, 1);
        }
        else
        {
            tmp = A->first;
            A->first = A->first->next;
            A->first->back = NULL;
            tmp->next = NULL;
            tmp->back = NULL;
            A->len--;
            Sup = insert_cell_Dlist(Sup, tmp, 1);
        }
    }

    if (!is_empty_Dlist(Inf))
    {
        if (Inf->len != 1)
            quick_sort(Inf);
    }
    if (!is_empty_Dlist(Sup))
    {
        if (Sup->len != 1)
            quick_sort(Sup);
    }
    fusion_Dlist(Inf, A, Sup);
}