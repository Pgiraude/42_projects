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

Bool    check(DList *La, DList *solution)
{
    List *A;
    List *S;
    int i;

    A = LA->first;
    S = solution->first;
    if (La->len != La->solution)
        return (false);
    i = 1;
    while (i <= solution)
    {
        if (A->data != S->data)
            return (false);
        A = A->next;
        S = S->next;
        i++;
    }
    return (true);
}

void    algo(DList *La, DList *Lb, DList *solution, DList *test)
{
    static int      profondeur;
    static int     saveA;
    static int     saveB;
    static int      sol;
    List *tmp;

    profondeur++;
    if (sol == 0 || profondeur <= 3)
    {
        if (La->len > 0 && saveB == 0)
        {
            saveA = 1;
            P_move(La, Lb, 0);
            insertlast_data_Dlist(test, 0);
            algo(La, Lb, solution);
            // ne peut pas etre la solution final
        }
        if (profondeur == 1)
        {
            tmp = isolate_cell_Dlist(test, 0);
            free (tmp);
        }


        if (Lb->len > 0 && saveA == 0)
        {
            saveB = 1;
            P_move(La, Lb, 1);
            test = insertlast_data_Dlist(test, 1);
            if (check(La, solution))
            {
                sol = 1;
                ft_printf("Pb_move\n");
                return ;
            }
            algo(La, Lb, solution);
        }
        if (profondeur == 1)
        {
            tmp = isolate_cell_Dlist(test, 0);
            free (tmp);
        }


        if (La->len > 1)
        {
            saveA = 0;
            saveB = 0;
            R_move(La, Lb, 0);
            test = insertlast_data_Dlist(test, 2);
            if (check(La, solution))
            {
                sol = 1;
                ft_printf("R_move\n");
                return ;
            }
            algo(La, Lb, solution);
        }
    }

    if (sol == 0)
    {
        tmp = isolate_cell_Dlist(test, 0);
        free (tmp);
        profondeur--;
    }

    
}

int main(int argc, char **argv)
{
    int i;
    int data;
    DList *La;
    DList *Lb;
    DList *Solution;

    
    if (is_error(argc, argv))
    {
        ft_printf("Error\n");
        return (EXIT_FAILURE);
    }

    La = NULL;
    Lb = NULL;
    Solution = NULL;


    La = create_Dlist(La);
    Lb = create_Dlist(Lb);
    Solution = create_Dlist(Solution);

    i = 1;
    while (i < argc)
    {
        data = ft_atoi(argv[i]);

        La = insert_data_Dlist(La, data, 1);
        Solution = insert_data_Dlist(Solution, data, 1);
        i++;
    }
    quick_sort(Solution);

    DList *test;
    test = NULL;
    test = create_Dlist(test);


    /*---print list---*/
    ft_printf("len A = %d le B = %d\n", La->len, Lb->len);
    ft_printpiles(La, Lb);
    /*---print list---*/

    /*---type move---*/
    algo(La, Lb, solution, test);
    /*---type move---*/

    /*---print list---*/
    printf_Dlist(Solution);
    /*---print list---*/

    /*---print solution---*/
    ft_printf("------\n");
    printf_Dlist(Solution);
    ft_printf("\n");
    /*---print solution---*/


    free_all_Dlist(La);
    free_all_Dlist(Lb);
    free_all_Dlist(Solution);
}
    