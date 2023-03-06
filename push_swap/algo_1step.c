
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

void    algo_1step(DDList *ALL)
{
    int i;
    int nbr_pb;


    nbr_pb = opti_pb(ALL);

    if (ALL->La->first->get_pb == true)
        ft_printf("pos 1 is true score = %d\n", ALL->La->first->costA);
    if (ALL->La->first->next->get_pb == true)
        ft_printf("pos 2 is true score = %d\n", ALL->La->first->next->costA);
    if (ALL->La->first->next->next->get_pb == true)
        ft_printf("pos 3 is true score = %d\n", ALL->La->first->next->next->costA);
    if (ALL->La->first->next->next->next->get_pb == true)
        ft_printf("pos 4 is true score = %d\n", ALL->La->first->next->next->next->costA);
    if (ALL->La->first->next->next->next->next->get_pb == true)
        ft_printf("pos 5 is true score = %d\n", ALL->La->first->next->next->next->next->costA);
    if (ALL->La->first->next->next->next->next->next->get_pb == true)
        ft_printf("pos 6 is true score = %d\n", ALL->La->first->next->next->next->next->next->costA);
    i = 1;
    while(i <= nbr_pb)
    {
        get_score_getup_La(ALL->La);
        push_to_b(ALL);
        i++;
    }
}