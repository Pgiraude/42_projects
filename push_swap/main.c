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
    if (test->last->data == sa)
        All_move(La, Lb, sa);
    if (test->last->data == ra)
        All_move(La, Lb, rra);

}

Bool    check(DDList *ALL)
{
    List *A;
    List *S;
    int i;

    A = ALL->La->first;
    S = ALL->Solution->first;
    if (ALL->La->len != ALL->Solution->len)
        return (false);
    i = 1;
    while (i <= ALL->Solution->len)
    {
        if (A->data != S->data)
            return (false);
        A = A->next;
        S = S->next;
        i++;
    }
    ALL->found_sol = true;
    return (true);
}

int pb_recursive(DDList *ALL)
{
    int move;

    if (ALL->pa == true)
    {
        ALL->pa == false;
        return (-1);
    }
    if (ALL->Lb->len == ALL->max_len)
        return (-1);

    ALL->pb = true;
    move = All_move(ALL->La, ALL->Lb, pb);
    if (move == -1)
        return (move);
    ALL->Move = insert_data_Dlist(ALL->Move, pb, 1);
    // check(ALL);
    return (move);
}

void    recursive(DDList * ALL, int max_profondeur)
{
    static int      profondeur;
    static int      sol;
    int             move;
    List *tmp;

    profondeur++;
    if (profondeur <= max_profondeur)
    {
        if (ALL->La->len > 1 && ALL->found_sol == 0)
        {
            All_move(ALL->La, ALL->Lb, sa);
            ALL->Move = insert_data_Dlist(ALL->Move, sa, 1);
            check(ALL);
            if (ALL->found_sol == true)
            {
                ft_printf("R_move\n");
                return ;
            }
            recursive(ALL, max_profondeur);
        }


        if (ALL->La->len > 1 && ALL->found_sol == 0)
        {
            All_move(ALL->La, ALL->Lb, ra);
            ALL->Move = insert_data_Dlist(ALL->Move, ra, 1);
            check(ALL);
            if (ALL->found_sol == true)
            {
                ft_printf("R_move\n");
                return ;
            }
            recursive(ALL, max_profondeur);
        }

        if (ALL->Lb->len > 1 && ALL->found_sol == 0)
        {
            move = pb_recursive(ALL);
            if (ALL->found_sol == true)
                return ;
            if (move != -1)
                recursive(ALL, max_profondeur);
        }
    }

    if (ALL->found_sol == 0)
    {
        reset_Dlist(ALL->La, ALL->Lb, ALL->Move);
        if (ALL->Move->len > 0)
        {
            tmp = isolate_cell_Dlist(ALL->Move, 1);
            free (tmp);
        }
        profondeur--;
    }
}



void    algo(DDList *ALL)
{
    int max_profondeur;

    ALL->max_len = ALL->La->len;
    ALL->pa = false;
    ALL->pb = false;
    ALL->sa = false;
    ALL->sb = false;
    ALL->ss = false;
    ALL->ra = false;
    ALL->rra = false;
    ALL->rb = false;
    ALL->rrb = false;
    ALL->rr = false;
    ALL->rrr = false;
    ALL->found_sol = false;
    if (check(ALL))
        return ;
    max_profondeur = 1;
    while (ALL->Move->len == 0)
    {
        recursive(ALL, max_profondeur);
        ft_printf("ok\n");
        max_profondeur++;
    }
}

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
    ft_printf("------\n");
    printf_Dlist(Solution);
    ft_printf("\n------\n");
    /*---print solution---*/

    /*---type move---*/
    
    algo(ALL);
    printf_Dlist(La);
    ft_printf("\n------\n");
    /*---type move---*/

    ft_printf("sol = ");
    printf_Dlist(Move);



    free_all_Dlist(La);
    free_all_Dlist(Lb);
    free_all_Dlist(Solution);
    free_all_Dlist(Move);
    free(ALL);
}
    