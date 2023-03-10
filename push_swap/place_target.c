

#include "push_swap.h"

void	placeup_target_lista(DDList *ALL, List *target)
{
	if (target == NULL)
		return ;
	target->tag = false;
	while (target->costA > 0)
	{
		all_move(ALL->La, ALL->Lb, ra);
		ALL->Move = insert_data_Dlist(ALL->Move, ra, 1);
		target->costA--;
	}
	while (target->costA < 0)
	{
		all_move(ALL->La, ALL->Lb, rra);
		ALL->Move = insert_data_Dlist(ALL->Move, rra, 1);
		target->costA++;
	}
}

void    placeup_bigmove_listb(DDList *ALL, List *target)
{
    while ((target->costB < 0 && target->costA < 0)
        || (target->moveA == true && target->costB < 0)
            || (target->moveB == true && target->costA < 0))
    {
        if (target->moveA == true)
        {
            target->costA = target->costA * -1;
            target->moveA = false;
        }
        if (target->moveB == true)
        {
            target->costB = target->costB * -1;
            target->moveB = false;
        }
        all_move(ALL->La, ALL->Lb, rrr);
        ALL->Move = insert_data_Dlist(ALL->Move, rrr, 1);
        target->costA++;
        target->costB++;
        target->bonus_cost++;
    }
}

void    placeup_remain_listb(DDList *ALL, List *target)
{
    while (target->costB > 0)
    {
        all_move(ALL->La, ALL->Lb, rb);
        ALL->Move = insert_data_Dlist(ALL->Move, rb, 1);
        target->costB--;
    }
    while (target->costB < 0)
    {
        all_move(ALL->La, ALL->Lb, rrb);
        ALL->Move = insert_data_Dlist(ALL->Move, rrb, 1);
        target->costB++;
    }
    while (target->costA > 0)
    {
        all_move(ALL->La, ALL->Lb, ra);
        ALL->Move = insert_data_Dlist(ALL->Move, ra, 1);
        target->costA--;
    }
    while (target->costA < 0)
    {
        all_move(ALL->La, ALL->Lb, rra);
        ALL->Move = insert_data_Dlist(ALL->Move, rra, 1);
        target->costA++;
    }
}

void    placeup_target_listb(DDList *ALL, List *target)
{
    if (target == NULL)
        return ;
    placeup_bigmove_listb(ALL, target);
    while (target->costB > 0 && target->costA > 0)
    {
        all_move(ALL->La, ALL->Lb, rr);
        ALL->Move = insert_data_Dlist(ALL->Move, rr, 1);
        target->costB--;
        target->costA--;
        target->bonus_cost++;
    }
    placeup_remain_listb(ALL, target);
    target->moveA = false;
    target->moveB = false;
}
