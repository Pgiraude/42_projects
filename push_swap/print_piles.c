

#include "push_swap.h"

void    ft_print_pile(DList *A, DList *B)
{
    List *tmpA = A->first;
    List *tmpB = B->first;

    while (tmpA != NULL || tmpB != NULL)
    {
        
    }
}

void    printf_Dlist(DList *L)
{
    if (is_empty_Dlist(L))
        return ;
    List *tmp = L->first;

    while(tmp != NULL)
    {
        ft_printf("[%d] ", tmp->data);
        tmp = tmp->next;
    }
}