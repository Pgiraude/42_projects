

#include "push_swap.h"

void    place_upLa(DDList *ALL, List *target)
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

void    push_to_b(DDList *ALL)
{
    List *lfirst;
    List *llast;

    lfirst = ALL->La->first;
    llast = ALL->La->last;

    while (lfirst->get_pb == false && lfirst->next != NULL)
        lfirst = lfirst->next;
    while (llast->get_pb == false && llast->back != NULL)
        llast = llast->back;

    if (llast->costA < 0 && lfirst->costA < 0)
    {
        place_upLa(ALL, llast);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    }
    else if (lfirst->costA > 0 && llast->costA > 0)
    {
        place_upLa(ALL, lfirst);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    }
    else if (lfirst->costA < (llast->costA * -1))
    {
        place_upLa(ALL, lfirst);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    }
    else if ((llast->costA * -1) < lfirst->costA)
    {
        place_upLa(ALL, llast);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    }
    else
    {
        place_upLa(ALL, lfirst);
        ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, pb), 1);
    }
}

void    get_score_getup_La(DList *La)
{
    List *cell;
    int i;
    int paire;

    cell = La->first;
    i = 0;
    paire = 0;
    if ((La->len % 2) == 0)
        paire = 1;
    while (i <= ((La->len / 2) - paire))
    {
        cell->costA = i;
        cell->costB = 0;
        cell = cell->next;
        i++;
    }
    cell = La->last;
    i = 1;
    while (i <= (La->len / 2))
    {
        cell->costA = i * -1;
        cell->costB = 0;
        cell = cell->back;
        i++;
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
    ft_printf("%d\n", mem[1]);
    i = 1;
    tmp_2 = ALL->La->first;
    while (i < mem[1])
    {
        tmp_2 = tmp_2->next;
        i++;
    }
    pos = tmp_2->target_pos;
    i = 1;

    ft_printf("%d\n", tmp_2->data);
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


    nbr_pb = get_pb_optimisation(ALL);

    i = 1;
    while(i <= nbr_pb)
    {
        get_score_getup_La(ALL->La);
        push_to_b(ALL);
        i++;
    }
}