/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:03:40 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/01 13:44:33 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Bool    check_alignement_3(DDList *ALL)
{
    int i;
    List *sol;
    List *la;

    la = ALL->La->first;
    sol = ALL->Solution->first;
    while (la->data != sol->data)
        sol = sol->next;
    i = 0;
    while (i <= 2)
    {
        if (la->data != sol->data)
            return (false);
        la = la->next;
        sol = sol->next;
        if (sol == NULL)
            sol = ALL->Solution->first;
        i++;
    }
    return (true);
}

void    reset_Dlist(DList *La, DList *Lb, DList *Move)
{
    List *tmp;
    int i;

    if (Move->len == 0)
        return ;
    tmp = Move->last;
    i = 1;
    while (i <= Move->len)
    {
        if (tmp->data == pa)
            All_move(La, Lb, pb);
        if (tmp->data == pb)
            All_move(La, Lb, pa);
        if (tmp->data == sa)
            All_move(La, Lb, sa);
        if (tmp->data == ra)
            All_move(La, Lb, rra);
        if (tmp->data == rra)
            All_move(La, Lb, ra);
        if (tmp->data == rb)
            All_move(La, Lb, rrb);
        tmp = tmp->back;
        i++;
    }
}

Bool    check(DList *La, DList *Solution)
{
    List *A;
    List *S;
    int i;

    A = La->first;
    S = Solution->first;
    if (La->len != Solution->len)
        return (false);
    i = 1;
    while (i <= Solution->len)
    {
        if (A->data != S->data)
            return (false);
        A = A->next;
        S = S->next;
        i++;
    }
    return (true);
}

void    algo(DDList *ALL)
{
    DList *Move1;
    DList *Move2;

    Move1 = NULL;
    Move2 = NULL;
    if (check(ALL->La, ALL->Solution))
        return ;
    if (check_alignement_3(ALL))
    {
        while (check(ALL->La, ALL->Solution) == false)
            Move1 = insert_data_Dlist(Move1, All_move(ALL->La, ALL->Lb, ra), 1);
        reset_Dlist(ALL->La, ALL->Lb, Move1);
        while (check(ALL->La, ALL->Solution) == false)
            Move2 = insert_data_Dlist(Move2, All_move(ALL->La, ALL->Lb, rra), 1);
        reset_Dlist(ALL->La, ALL->Lb, Move2);

        if (Move1->len <= Move2->len)
            ALL->Move = Move1;
        else
            ALL->Move = Move2;
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
    ft_printf("------\nSolution = ");
    printf_Dlist(Solution);
    ft_printf("\n------\n");
    /*---print solution---*/

    /*---type move---*/
    
    algo(ALL);
    ft_printf("after algo La = ");
    printf_Dlist(La);
    ft_printf("\n------\n");
    /*---type move---*/

    ft_printf("sol = ");
    ft_printresult(ALL->Move);



    free_all_Dlist(La);
    free_all_Dlist(Lb);
    free_all_Dlist(Solution);
    free_all_Dlist(Move);
    free(ALL);
}
    