

#include "push_swap.h"

void    p_move(DList *src, DList *dest)
{
    List *cell;

    if (is_empty_Dlist(src) || src->len == 0)
        return ;
    cell = isolate_cell_Dlist(src, 0);
    dest = insert_cell_Dlist(dest, cell, 0);
}