
#include "push_swap.c"

typedef struct controler
{
    struct Cellule *bck;
    struct Cellule *cur;
    struct Cellule *nxt;
}controler;

int cost_La(List *cell, DDList *ALL)
{
    controler *ctl_up;
    controler *ctl_down;

    ctl_up->bck = ALL->La->last;
    ctl_up->cur = ALL->La->first;
    ctl_up->nxt = ALL->La->first->next;

    ctl_down->bck = ALL->La->last->back;
    ctl_down->cur = ALL->La->last;
    ctl_down->nxt = ALL->La->first;
    while (ctl_up->cur == ctl_down->bck)
    {
        if (ctl_up->bck->final_pos - ctl_up->cur->final_pos != 1)
        {
            if (ctl_up->bck->final_pos < cell->final_pos)
        }
    }

}

int scoreLa(List *cell, DDList *ALL)
{
    List *La;
    int down;
    int up;
    int impaire;

    impaire = 0;
    if (ALL->La->len % 2 != 0)
        impaire = 1;

    La = ALL->La->first;
    up = 0;
    while (up < (ALL->La->len / 2))
    {
        if (cell->final_pos == (La->final_pos - 1))
            return (up);
        if (cell->final_pos == (La->final_pos + 1))
            return (up + 1);
        La = La->next;
        up++;
    }

    La = ALL->La->last;
    down = 0;
    while (down < ((ALL->La->len / 2) + impaire))
    {
        if (cell->final_pos == (La->final_pos + 1))
            return (down * -1);
        down++;
        La = La->back;
    }

    List *tmp;

    tmp = ALL->La->last;
    La = ALL->La->first;
    up = 0;
    while (up <= (ALL->La->len / 2))
    {
        if (tmp->final_pos == La->final_pos + 1)
        {
            La = La->next;
            tmp = La->back;
            up++;
        }
        else if (cell->final_pos < La->final_pos)
            break;
        else
        {
            up++;
            La = La->next;
        }
    }
    tmp = ALL->La->first;
    La = ALL->La->last;
    down = 0;
    while  (down < ((ALL->La->len / 2) + impaire))
    {
        if (tmp->final_pos == La->final_pos + 1)
        {
            La = La->back;
            tmp = La->next;
            down++;
        }
        else if (cell->final_pos > La->final_pos)
            break;
        else
        {
            down++;
            La = La->back;
        }
    }
    ft_printf("down = %d up = %d\n", down, up);
    if (down < up)
        return (down * -1);
    else
        return (up);
}

void    get_cost_Lb(DList *Lb, DDList *ALL)
{
    List *cell;
    int i;

    cell = Lb->first;
    i = 0;
    ft_printf("Lb len = %d\n", Lb->len);
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
void    ft_is_aligne(DDList *ALL)
{
    List *L;

    L = ALL->La->first;
    if (ALL->La->last->final_pos == L->final_pos + 1)
    while (L->next == NULL)
    {

    }
}

void    algo_2step(DDList *ALL)
{
    ft_is_aligne(ALL);
    get_cost_Lb(ALL->Lb, ALL);
    ft_printf("A = %d B = %d\n", ALL->Lb->first->next->costA, ALL->Lb->first->next->costB);
}