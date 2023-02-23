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
    ft_printpiles(Pile_a, Pile_b);
    quick_sort(Solution);
    ft_printf("------\n");
    printf_Dlist(Solution);

}
    