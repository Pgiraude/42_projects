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
void   biglast_insert_Dlist(DList *Inf, DList *Piv, DList *Sup)
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
        Piv->last->next = Sup->last;
        Piv->last = Sup->last;
        Sup->first = NULL;
        Sup->last = NULL;
        Piv->len = Piv->len + Sup->len;
        free (Sup);
    }
}

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

void   quick_sort(DList *A)
{
    DList *Sup;
    DList *Inf;
    List *tmp;

    Sup = create_Dlist();
    Inf = create_Dlist();
    
    is_empty_Dlist(Inf);
    
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
                ft_printf("start ajout SUP\n");
                Sup = insert_lastquicksort_Dlist(Sup, tmp);
                ft_printf("end ajout SUP\n");
            }
        }
        ft_printf("Start recursion\n");
        if (!is_empty_Dlist(Inf) || Inf->len != 1)
        {
            ft_printf("start recursif INF\n");
            quick_sort(Inf);
            ft_printf("end recursif INF\n");
            
        }
        if (!is_empty_Dlist(Sup) || Sup->len != 1)
        {
            ft_printf("start recursif SUP\n");
            quick_sort(Sup);
        }
        ft_printf("end recursif SUP\n");
        biglast_insert_Dlist(Inf, A, Sup);
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
    quick_sort(Solution);
    printf_Dlist(Solution);

}
    