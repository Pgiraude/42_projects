

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



/*---------------------------------------------*/
int    get_pb_tag(List *pivot, DDList *ALL)
{
    int last_pos;
    int i;
    int nbr_pb;

    last_pos = pivot->target_pos;
    i = 1;
    nbr_pb = 0;
    while (i++ < ALL->La->len)
    {
        if (pivot->next == NULL)
            pivot = ALL->La->first;
        else
            pivot = pivot->next;
        if (pivot->target_pos == (last_pos + 1) ||
         (last_pos == ALL->La->len && pivot->target_pos == 1))
            last_pos = pivot->target_pos;
        else
        {
            nbr_pb++;
            pivot->get_pb = true;
        }
    }
    if (pivot->next == NULL)
        pivot = ALL->La->first;
    else
        pivot = pivot->next;
    ft_printf("pivot = %d\n", pivot->data);
    return (nbr_pb);
}

int get_pb_score(List *pivot, DDList *ALL)
{
    int i;
    int score;
    int save_target_pos;

    i = 1;
    score = 0;
    save_target_pos = pivot->target_pos;
    while (i++ <= ALL->La->len)
    {
        if (pivot->next == NULL)
            pivot = ALL->La->first;
        else
            pivot = pivot->next;
        if (pivot->target_pos == (save_target_pos + 1) ||
         (save_target_pos == ALL->La->len && pivot->target_pos == 1))
        {
            save_target_pos = pivot->target_pos;
            score++;
        }
    }
    return (score);
}

int    get_pb_optimisation(DDList *ALL)
{
    List *pivot;
    int best_score[3];
    int score;

    pivot = ALL->La->first;
    while (pivot != NULL)
    {   
        score = get_pb_score(pivot, ALL);
        if (score > best_score[0])
        {
            best_score[0] = score;
            best_score[1] = pivot->target_pos;
        }
        pivot = pivot->next;        
    }
    best_score[2] = '\0';
    pivot = ALL->La->first;
    while (pivot->target_pos != best_score[1])
        pivot = pivot->next;
    return (get_pb_tag(pivot, ALL));
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