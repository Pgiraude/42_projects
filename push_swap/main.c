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

void    reset_Dlist(DList *La, DList *Lb, DList *test)
{
    if (test->len == 0)
        return ;
    if (test->last->data == 0)
        S_move(La, Lb, 0);
    if (test->last->data == 1)
        P_move(La, Lb, 0);
    if (test->last->data == 2)
        R_move(La, Lb, 3);

}

Bool    check(DList *La, DList *solution)
{
    List *A;
    List *S;
    int i;

    A = La->first;
    S = solution->first;
    if (La->len != solution->len)
        return (false);
    i = 1;
    while (i <= solution->len)
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
    static int      sol;
    List *tmp;

        if (check(La, solution))
        {
            sol = 1;
            return ;
        }

    profondeur++;
    if (profondeur <= 4)
    {
        if (La->len > 1 && saveA == 0 && sol == 0)
        {
            saveA = 1;
            S_move(La, Lb, 0);
            test = insert_data_Dlist(test, 0, 1);
            if (check(La, solution))
            {
                sol = 1;
                ft_printf("S_move\n");
                return ;
            }
            algo(La, Lb, solution, test);
            // ne peut pas etre la solution final
        }
        if (test->len == 1 && sol == 0 && profondeur == 1)
        {
            tmp = isolate_cell_Dlist(test, 0);
            free (tmp);
        }

        if (La->len > 1 && sol == 0)
        {
            saveA = 0;
            R_move(La, Lb, 0);
            test = insert_data_Dlist(test, 2, 1);
            if (check(La, solution))
            {
                sol = 1;
                ft_printf("R_move\n");
                return ;
            }
            algo(La, Lb, solution, test);
        }
    }

    if (sol == 0)
    {
        
        reset_Dlist(La, Lb, test);
        // printf("test\n");
        if (test->len > 0)
            tmp = isolate_cell_Dlist(test, 1);
        // printf("endtest\n");
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

    /*---print list---*/
    /*---print list---*/

    /*---print solution---*/
    ft_printf("------\n");
    printf_Dlist(Solution);
    ft_printf("\n------\n");
    /*---print solution---*/

    /*---type move---*/
    algo(La, Lb, Solution, test);
    ft_printf("\n------\n");
    /*---type move---*/

    ft_printf("sol = ");
    printf_Dlist(test);



    free_all_Dlist(La);
    free_all_Dlist(Lb);
    free_all_Dlist(Solution);
    free_all_Dlist(test);
}
    