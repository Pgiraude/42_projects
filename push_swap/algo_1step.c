

#include "push_swap.h"

void    placeup_target_ListA(DDList *ALL, List *target)
{
    int nbr_move;

    if (target->costA > 0)
    {
        nbr_move = target->costA;
        while (nbr_move != 0)
        {
            ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, ra), 1);
            nbr_move--;
        }
    }
    if (target->costA < 0)
    {
        nbr_move = target->costA * -1;
        while (nbr_move != 0)
        {
            ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rra), 1);
            nbr_move--;
        }
    }
}

List    *target_to_pushB(DDList *ALL)
{
    List *cell;
    List *target;
    int sign;
    int lower_cost;

    target = NULL;
    cell = ALL->La->first;
    lower_cost = ALL->max_len;
    while (cell != NULL)
    {
        if (cell->costA >= 0)
            sign = 1;
        else
            sign = -1;
        
        if (lower_cost > cell->costA * sign && cell->get_pb == true)
        {
            lower_cost = cell->costA * sign;
            target = cell;
        }
        cell = cell->next;
    }
    return (target);
}

void    cost_getup_La(DList *ListA)
{
    List *cell;
    int paire;
    int i;

    paire = 0;
    if (ListA->len % 2 == 0)
        paire = 1;
    cell = ListA->first;
    i = 0;
    while (cell != NULL)
    {
        cell->move = false;
        if (i <= ListA->len / 2)
            cell->costA = i;
        if (i == ListA->len / 2 && paire == 1)
            cell->move = true;
        if (i > ListA->len / 2)
            cell->costA = i - ListA->len;
        i++;
        cell = cell->next;
    }
}

/*------------------------------------------------------------------*/

int    get_pb_optimisation(DDList *ALL)
{
    int tab[ALL->La->len][3];
    List *tmp_1;
    List *tmp_2;
    int pos;
    int pivot_pos;
    int i;
    int score;
    int nbr_pb;


    tmp_1 = ALL->La->first;
    tmp_2 = ALL->La->first;
    pivot_pos = 0;
    while (tmp_1 != NULL)
    {   
        i = 1;
        tmp_2 = tmp_1;
        pos = tmp_2->target_pos;
        score = 0;
        while (i <= ALL->La->len)
        {
            if (tmp_2->next == NULL)
                tmp_2 = ALL->La->first;
            else
                tmp_2 = tmp_2->next;
            if (tmp_2->target_pos == (pos + 1) || (pos == ALL->La->len && tmp_2->target_pos == 1))
            {
                pos = tmp_2->target_pos;
                score++;
            }
            i++;
        }
        tab[pivot_pos][0] = score;
        tab[pivot_pos][1] = pivot_pos + 1;
        tab[pivot_pos][2] = '\0';
        tmp_1 = tmp_1->next;        
        pivot_pos++;
    }
    
    int *mem;

    pivot_pos = 0;
    mem = tab[pivot_pos];
    while (pivot_pos < ALL->La->len)
    {
        if (tab[pivot_pos][0] > mem[0])
            mem = tab[pivot_pos];
        pivot_pos++;
        
    }
    i = 1;
    tmp_2 = ALL->La->first;
    while (i < mem[1])
    {
        tmp_2 = tmp_2->next;
        i++;
    }
    pos = tmp_2->target_pos;
    i = 1;

    nbr_pb = 0;
    while (i < ALL->La->len)
    {
        if (tmp_2->next == NULL)
            tmp_2 = ALL->La->first;
        else
            tmp_2 = tmp_2->next;
        if (tmp_2->target_pos == (pos + 1) || (pos == ALL->La->len && tmp_2->target_pos == 1))
        {
            tmp_2->get_pb = false;
            pos = tmp_2->target_pos;
        }
        else
        {
            nbr_pb++;
            tmp_2->get_pb = true;
        }
        i++;
    }
    if (tmp_2->next == NULL)
        tmp_2 = ALL->La->first;
    else
        tmp_2 = tmp_2->next;
    
    ft_printf("pivot = %d\n", tmp_2->data);
    return (nbr_pb);
}

void    algo_1step(DDList *ALL)
{
    int i;
    int nbr_pb;
    List *target;

    nbr_pb = get_pb_optimisation(ALL);
    target = NULL;
    i = 1;
    while(i <= nbr_pb)
    {
        cost_getup_La(ALL->La);
        target = target_to_pushB(ALL);
        placeup_target_ListA(ALL, target);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
        i++;
    }
}