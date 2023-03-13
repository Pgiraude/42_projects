/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 18:42:34 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    DList *La;
    DList *Lb;
    DList *Solution;

    DDList *ALL;


    
    if (is_error(argc, argv))
    {
        ft_printf("Error\n");
        return (EXIT_FAILURE);
    }


    ALL = malloc(sizeof(*ALL));
    if (!ALL)
        return (EXIT_FAILURE);

    La = NULL;
    Lb = NULL;
    Solution = NULL;


    La = create_Dlist(La);
    Lb = create_Dlist(Lb);
    Solution = create_Dlist(Solution);

    i = 1;
    while (i < argc)
    {
        La = insert_data_Dlist(La, ft_atoi(argv[i]), 1);
        Solution = insert_data_Dlist(Solution, ft_atoi(argv[i]), 1);
        i++;
    }
    quick_sort(Solution);

    DList *Move;
    Move = NULL;
    Move = create_Dlist(Move);

    ALL->La = La;
    ALL->Lb = Lb;
    ALL->Solution = Solution;
    ALL->Move = Move;


    /*---print list---*/
    ft_printf("len A = %d le B = %d\n", La->len, Lb->len);
    ft_printpiles(La, Lb);
    /*---print list---*/

    /*---print list---*/
    /*---print list---*/

    /*---print solution---*/
    ft_printf("------\nquicksort = ");
    printf_Dlist(Solution);
    ft_printf("\n------\n");
    /*---print solution---*/



    push_swap(ALL);

    /*---type move---*/
    ft_printf("after algo =\n");
    ft_printpiles(La, Lb);
    ft_printf("\n------\n");
    /*---type move---*/

    ft_printf("sol = ");
    ft_print_allmove(Move);



    free_all_dlist(La);
    free_all_dlist(Lb);
    free_all_dlist(Solution);
    free_all_dlist(Move);
    free(ALL);
}
    