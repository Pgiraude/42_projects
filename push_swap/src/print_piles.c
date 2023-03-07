

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

void    ft_printresult(DList *Move)
{
    int i;
    List *tmp;

    if (Move->len == 0)
        return ;
    tmp = Move->first;
    i = 1;
    while (i <= Move->len)
    {
        if (tmp->data == pa)
            ft_printf("pa\n");
        if (tmp->data == pb)
            ft_printf("pb\n");
        if (tmp->data == sa)
            ft_printf("sa\n");
        if (tmp->data == sb)
            ft_printf("sb\n");
        if (tmp->data == ss)
            ft_printf("ss\n");
        if (tmp->data == ra)
            ft_printf("ra\n");
        if (tmp->data == rra)
            ft_printf("rra\n");
        if (tmp->data == rb)
            ft_printf("rb\n");
        if (tmp->data == rrb)
            ft_printf("rrb\n");
        if (tmp->data == rr)
            ft_printf("rr\n");
        if (tmp->data == rrr)
            ft_printf("rrr\n");
        tmp = tmp->next;
        i++;
    }
}
