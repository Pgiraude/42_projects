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

int    opti_pb(DDList *ALL)
{
    int tab[ALL->La->len][3];
    List *lla;
    List *la;
    int pos;
    int z;
    int i;
    int score;
    int nbr_pb;


    lla = ALL->La->first;
    la = ALL->La->first;
    
    z = 0;

    while (z < ALL->La->len)
    {   
        i = 1;
        la = lla;
        lla->get_pb = false;
        pos = la->final_pos;
        score = 0;
        while (i <= ALL->La->len)
        {
            if (la->next == NULL)
            {
                la = ALL->La->first;
            }
            else
            {
                la = la->next;
            }
            if (la->final_pos == (pos + 1) || (pos == ALL->La->len && la->final_pos == 1))
            {
                pos = la->final_pos;
                score++;
            }
            i++;
        }
        tab[z][0] = score;
        tab[z][1] = z + 1;
        tab[z][2] = '\0';
        lla->cur_pos = z + 1;
        lla = lla->next;        
        z++;
    }
    
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
    while (mem[1] != la->cur_pos)
        la = la->next;
    pos = la->final_pos;
    i = 1;

    nbr_pb = 0;
    while (i < ALL->La->len)
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
        {
            nbr_pb++;
            la->get_pb = true;
        }
        i++;
    }
    if (la->next == NULL)
        la = ALL->La->first;
    else
        la = la->next;
    
    ft_printf("pivot = %d\n", la->data);
    return (nbr_pb);

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

void    get_score(DDList *ALL)
{
    List *la;
    int i;
    int impaire;

    la = ALL->La->first;
    i = 1;
    impaire = 0;
    if ((ALL->La->len % 2) != 0)
        impaire = 1;
    while (i <= ((ALL->La->len + impaire)/ 2))
    {
        if (la->get_pb == true)
        {
            la->costA = i;
            la->costB = 0;
        }
        else
        {
            la->costA = 0;
            la->costB = 0;
        }
        la = la->next;
        i++;
    }
    la = ALL->La->last;
    i = 1;
    while (i <= (ALL->La->len / 2))
    {
        if (la->get_pb == true)
        {
            la->costA = (i + 1) * -1;
            la->costB = 0;
        }
        else
        {
            la->costA = 0;
            la->costB = 0;
        }
        la = la->back;
        i++;
    }

    // if (ALL->La->first->get_pb == true)
    //     ft_printf("1 is true score = %d\n", ALL->La->first->costA);
    // if (ALL->La->first->next->get_pb == true)
    //     ft_printf("2 is true score = %d\n", ALL->La->first->next->costA);
    // if (ALL->La->first->next->next->get_pb == true)
    //     ft_printf("3 is true score = %d\n", ALL->La->first->next->next->costA);
    // if (ALL->La->first->next->next->next->get_pb == true)
    //     ft_printf("4 is true score = %d\n", ALL->La->first->next->next->next->costA);
    // if (ALL->La->first->next->next->next->next->get_pb == true)
    //     ft_printf("5 is true score = %d\n", ALL->La->first->next->next->next->next->costA);
    // if (ALL->La->first->next->next->next->next->next->get_pb == true)
    //     ft_printf("6 is true score = %d\n", ALL->La->first->next->next->next->next->next->costA);
}

void    place_up(DDList *ALL, List *target)
{
    int nbr_move;

    if (target->costA > 0)
    {
        nbr_move = target->costA;
        while (nbr_move != 1)
        {
            ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, ra), 1);
            nbr_move--;
        }
    }
    if (target->costA < 0)
    {
        nbr_move = target->costA * -1;
        while (nbr_move != 1)
        {
            ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rra), 1);
            nbr_move--;
        }
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

DList   copy_Dlist(DList *L)
{
    DList *copy;
    List *list;

    if (is_empty_Dlist(L))
        return (NULL);
    copy = NULL;
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

void    analyse(DDList *ALL, List *cell)
{
    DList *copy;

    copy = copy_Dlist(ALL->La);
    quick_sort(copy);
    
    
    la = ALL->La->first;
    i = 1;
    impaire = 0;
    if ((ALL->La->len % 2) != 0)
        impaire = 1;
    while (i <= ((ALL->La->len + impaire)/ 2))
    {
        if (la->get_pb == true)
        {
            la->costA = i;
            la->costB = 0;
        }
        else
        {
            la->costA = 0;
            la->costB = 0;
        }
        la = la->next;
        i++;
    }
    la = ALL->La->last;
    i = 1;
    while (i <= (ALL->La->len / 2))
    {
        if (la->get_pb == true)
        {
            la->costA = (i + 1) * -1;
            la->costB = 0;
        }
        else
        {
            la->costA = 0;
            la->costB = 0;
        }
        la = la->back;
        i++;
    }
}

void    mega_score(DDList *ALL)
{
    List *la;
    List *lb;
    List *cell;

    la = ALL->La->first;
    lb = ALL->Lb->first;
    
    cell = ALL->La->first;
    while (cell->next == NULL)
    {
        

        cell = cell->next;
    }

}

void    push_to_b(DDList *ALL)
{
    List *lfirst;
    List *llast;

    lfirst = ALL->La->first;
    llast = ALL->La->last;

    while (lfirst->costA == 0 && lfirst->next != NULL)
        lfirst = lfirst->next;
    while (llast->costA == 0 && llast->back != NULL)
        llast = llast->back;

    if (llast->costA < 0 && lfirst->costA < 0)
    {
        place_up(ALL, llast);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    }
    else if (lfirst->costA > 0 && llast->costA > 0)
    {
        place_up(ALL, lfirst);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    }
    else if (lfirst->costA < (llast->costA * -1))
    {
        place_up(ALL, lfirst);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    }
    else if ((llast->costA * -1) < lfirst->costA)
    {
        place_up(ALL, llast);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    }
    else
    {
        place_up(ALL, lfirst);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    }


}

void    algo(DDList *ALL)
{
    DList *Move1;
    DList *Move2;
    int nbr_pb;
    int i;

    Move1 = NULL;
    Move2 = NULL;

    insert_solution(ALL);
    nbr_pb = opti_pb(ALL);
    i = 1;
    while(i <= nbr_pb)
    {
        get_score(ALL);
        push_to_b(ALL);
        i++;
    }
    
    
    
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