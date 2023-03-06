

#include "../push_swap.h"

void    ft_printpiles(DList *A, DList *B)
{
    List *tmpA;
    List *tmpB;

    if (is_empty_Dlist(A) && is_empty_Dlist(B))
        return ;

    if (is_empty_Dlist(A))
        tmpA = NULL;
    else
        tmpA = A->first;
    
    if (is_empty_Dlist(B))
        tmpB = NULL;
    else
        tmpB = B->first;

    while (tmpA != NULL || tmpB != NULL)
    {
        if (tmpA == NULL)
            ft_printf("[vide]");
        else
        {
            ft_printf("[%d]", tmpA->data);
            tmpA = tmpA->next;
        }
        ft_printf(" ");
        if (tmpB == NULL)
            ft_printf("[vide]\n");
        else
        {
            ft_printf("[%d]\n", tmpB->data);
            tmpB = tmpB->next;
        }
    }
}
