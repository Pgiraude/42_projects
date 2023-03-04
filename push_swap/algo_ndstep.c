
#include "push_swap.c"

int scoreLa(List *cell, DDList *ALL)
{
    List *La;
    int down;
    int up;

    La = ALL->first;
    up = 0;
    while (cell->final_pos > La->final_pos && up <= (La->len / 2))
    {
        up++;
        La = La->next;
    }
    La = ALL->last;
    down = 0
    while (cell->final_pos < La->final_pos && down < (La->len / 2))
    {
        down++;
        La = La->back;
    }
    if (down < up)
        return (down * -1);
    else
        return (up);
}

void    get_score_getup_Lb(DList *Lb, DDList *ALL)
{
    List *cell;
    int i;

    cell = Lb->first;
    i = 0;
    while (i <= (Lb->len/ 2))
    {
        cell->costB = i + 1;
        cell->costA = scoreLa(cell, ALL);
        cell = cell->next;
        i++;
    }
    cell = Lb->last;
    i = 0;
    while (i < (Lb->len / 2))
    {
        cell->costB = (i + 2) * -1;
        cell->costA = scoreLa(cell, ALL);
        cell = cell->back;
        i++;
    }
}

void    place_upLb(DDList *ALL, List *target)
{
    int nbr_move;

    if (target->costB > 0)
    {
        nbr_move = target->costB;
        while (nbr_move != 0)
        {
            ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rb), 1);
            nbr_move--;
        }
    }
    if (target->costB < 0)
    {
        nbr_move = target->costB * -1;
        while (nbr_move != 0)
        {
            ALL->Move = insert_data_Dlist(ALL->Move, All_move(ALL->La, ALL->Lb, rrb), 1);
            nbr_move--;
        }
    }
}