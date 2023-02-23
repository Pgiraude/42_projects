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

int main(int argc, char **argv)
{
    int i;
    int data;
    DList *Pile_a;
    DList *Pile_b;
    DList *Solution;
    DList *tmp;
    
    if (is_error(argc, argv))
    {
        ft_printf("Error\n");
        return (EXIT_FAILURE);
    }
    Pile_a = NULL;
    Pile_b = NULL;
    Solution = NULL;

    Pile_a = create_Dlist(Pile_a);
    Pile_b = create_Dlist(Pile_b);
    Solution = create_Dlist(Solution);

    i = 1;
    while (i < argc)
    {
        data = ft_atoi(argv[i]);

        Pile_a = insert_data_Dlist(Pile_a, data, 1);
        Solution = insert_data_Dlist(Solution, data, 1);
        i++;
    }



    /*---type move---*/
    R_move(Pile_a, Pile_b, 0);
    /*---type move---*/

    /*---print result---*/
    ft_printf("len A = %d le B = %d\n", Pile_a->len, Pile_b->len);
    ft_printpiles(Pile_a, Pile_b);
    /*---print result---*/

    /*---print solution---*/
    quick_sort(Solution);
    ft_printf("------\n");
    printf_Dlist(Solution);
    ft_printf("\n");
    /*---print solution---*/


    free_all_Dlist(Pile_a);
    free_all_Dlist(Pile_b);
    free_all_Dlist(Solution);
}
    