/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:45:29 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/02 18:22:15 by pgiraude         ###   ########.fr       */
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
    i = 1;
    while (i <= ALL->La->len)
    {
        if (la->data != sol->data)
            return (false);
        if (sol->next == NULL)
            sol = ALL->Solution->first;
        else
            sol = sol->next;
        la = la->next;
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

void    insert_solution(DDList * ALL)
{
    int x;
    int y;
    List *la;
    List *sol;

    la = ALL->La->first;
    x = 1;
    while (x <= ALL->La->len)
    {
        y = 1;
        sol = ALL->Solution->first;
        while (sol->data != la->data)
        {
            sol = sol->next;
            y++;
        }
        la->final_pos = y;
        la = la->next;
        x++;
    }
}

void    get_cur_pos(DDList *ALL)
{
    List *la;
    int cur_pos;

    la = ALL->La->first;
    cur_pos = 1;
    while (cur_pos <= ALL->La->len)
    {
        ALL->La->first->cur_pos = cur_pos;
        cur_pos++;
        la = la->next;
    }
}

// void    push_to_b_recursive(List **lfirst, List **last)
// {
//     while (lfirst->costA == 0 && lfirst->next != NULL)
//         lfirst = lfirst->next;
//     while (llast->costA == 0 && llast->back != NULL)
//         llast = llast->back;
    
//     if ((llast->costA * -1) == lfirst->costA && llast->costA != 0)
//     {
//         place_up(ALL, llast);
//         All_move(ALL->La, ALL->Lb, pb);
//     }
// }

DList   *copy_Dlist(DList *L)
{
    DList *copy;
    List *list;

    copy = NULL;
    if (is_empty_Dlist(L))
        return (copy);
    list = L->first;
    copy = create_Dlist(copy);
    if (L->len == 0)
        return (copy);
    while (list->next != NULL)
    {
        copy = insert_data_Dlist(copy, list->data, 1);
        list = list->next;
    }
    return (copy);
}

// void    analyse(DDList *ALL, List *cell)
// {

// }

void    mega_score(DDList *ALL)
{
    List *cell;
    int i;
    
    cell = ALL->La->first;
    i = 1;
    while (cell->next == NULL)
    {
        cell->costA = i - cell->final_pos;
        cell->costB = 0;
        cell = cell->next;
        i++;
    }
    cell = ALL->Lb->first;
    i = 1;
    while (cell->next == NULL)
    {
        
    }

}


void    algo(DDList *ALL)
{
    DList *Move1;
    DList *Move2;


    Move1 = NULL;
    Move2 = NULL;
    insert_solution(ALL);

    algo_1step(ALL);
    algo_2step(ALL);
    
    
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