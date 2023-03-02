/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:45:29 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/02 16:39:59 by pgiraude         ###   ########.fr       */
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

void    opti_pb(DDList *ALL)
{
    int tab[ALL->La->len][3];
    List *lla;
    List *la;
    int pos;
    int z;
    int i;
    int count;


    lla = ALL->La->first;
    la = ALL->La->first;
    
    z = 0;

    while (z < ALL->La->len)
    {   
        printf("test2\n");
        i = 1;
        la = lla;
        pos = la->final_pos;
        while (i <= ALL->La->len)
        {
            if (la->next == NULL)
            {
                printf("test1\n");
                la = ALL->La->first;
            }
            else
            {
                    printf("test\n");
                la = la->next;
            }
            if (la->final_pos == (pos + 1) || (pos == ALL->La->len && la->final_pos == 1))
            {
                pos = la->final_pos;
                count++;
            }
            la = la->next;
            i++;
        }
        tab[z][0] = count;
        tab[z][1] = z + 1;
        tab[z][2] = '\0';
        lla->cur_pos = z + 1;
        lla = lla->next;        
        z++;
    }
        printf("test\n");
    int *mem;

    z = 0;
    mem = tab[z];
    while (z < ALL->La->len)
    {
        if (tab[z][0] > mem[0])
            mem = tab[z];
        z++;
    }
    la = ALL->La->first;
    while (mem[1] == la->cur_pos)
        la = la->next;
    pos = la->final_pos;
    i = 1;
    while (i <= ALL->La->len)
    {
        if (la->next == NULL)
            la = ALL->La->first;
        else
            la = la->next;
        if (la->final_pos == (pos + 1) || (pos == ALL->La->len && la->final_pos == 1))
        {
            la->get_pb = false;
            pos = la->final_pos;
        }
        else
            la->get_pb = true;
        la = la->next;
        i++;
    }
}

void    algo(DDList *ALL)
{
    DList *Move1;
    DList *Move2;

    Move1 = NULL;
    Move2 = NULL;

    insert_solution(ALL);
    opti_pb(ALL);
    
    
    
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