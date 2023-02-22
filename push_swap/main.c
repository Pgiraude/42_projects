/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/02/21 18:40:05 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// DList   *free_first_Dlist(DList *L)
// {
//     List *tmp = L->first;
    
//     if (is_empty_Dlist(L))
//         return (NULL);
//     if (L->first == L->last)
//     {
//         free(L);
//         L = NULL;
//         return (NULL);
//     }
    
//     L->first = L->first->next;
//     L->first->back = NULL;
//     tmp->next = NULL;
//     free (tmp);
//     tmp = NULL;
//     L->len--;
//     return (L);
// }
DList   *insert_lastquicksort_Dlist(DList *L, List *li)
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
    else
    {
        L->last->next = li;
        li->back = L->last;
        L->last = li;
    }
    L->len++;
    return (L);
}

DList   *insert_firstquicksort_Dlist(DList *L, List *li)
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
    else
    {
        L->first->back = li;
        li->next = L->first;
        L->first = li;
    }
    L->len++;
    return (L);
}

DList   *quick_sort(DList *A)
{
    DList *Sup;
    DList *Inf;
    List *tmp;

    Sup = create_Dlist();
    Inf = create_Dlist();
    
    
    if (A->len >= 2)
    {
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
                Inf = insert_lastquicksort_Dlist(Inf, tmp);
            }
            else
            {
                tmp = A->first;

                A->first = A->first->next;
                A->first->back = NULL;
                tmp->next = NULL;
                tmp->back = NULL;

                A->len--;
                Sup = insert_lastquicksort_Dlist(Sup, tmp);
            }
        }
        tmp = A->first;
        A->first = NULL;
        A->last = NULL;

        insert_firstquicksort_Dlist(Sup, tmp);
    }

    if (Inf->len <= 1)
        return (Inf);
    else
        quick_sort(Inf);
    
    printf_Dlist(Sup);
    return (A);
}

int main(int argc, char **argv)
{
    int i;
    int data;
    
    if (is_error(argc, argv))
    {
        ft_printf("Error\n");
        return (EXIT_FAILURE);
    }
    
    DList *Pile_a;
    DList *Pile_b;
    DList *Solution;
    Pile_a = create_Dlist();
    Pile_b = create_Dlist();
    Solution = create_Dlist();

    i = 1;
    while (i < argc)
    {
        data = ft_atoi(argv[i]);
        Pile_a = insert_last_Dlist(Pile_a, data);
        Solution = insert_last_Dlist(Solution, data);
        i++;
    }
    // ft_printpiles(Pile_a, Pile_b);
    Solution = quick_sort(Solution);

}
    