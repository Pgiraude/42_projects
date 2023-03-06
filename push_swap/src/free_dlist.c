
#include "../push_swap.h"

void    free_all_Dlist(DList *L)
{
    List *tmp;

    if (is_empty_Dlist(L))
        return ;
    while(L->first != L->last)
    {
        tmp = L->first;
        L->first = L->first->next;
        L->first->back = NULL;
        tmp->next = NULL;
        free (tmp);
        tmp = NULL;
    }
    if (L->first == L->last)
    {
        tmp = L->first;
        free(tmp);
        free(L);
        L = NULL;
    }
}