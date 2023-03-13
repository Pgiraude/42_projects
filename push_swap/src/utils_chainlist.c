
#include "../push_swap.h"


List	*isolate_lastcell_Dlist(DList *list)
{
	List	*cell;

	cell = NULL;
	if (is_empty_Dlist(list))
		return (NULL);
	if (list->len != 1)
		return (NULL);
	if (list->first == list->last)
	{
		cell = list->first;
		cell->next = NULL;
		cell->back = NULL;
		list->first = NULL;
		list->last = NULL;
		list->len--;
	}
	return (cell);
}

DList	*insertlast_cell_Dlist(DList *list, List *cell)
{
	if (is_empty_Dlist(list))
	{
		list = malloc(sizeof(*list));
		if (!list)
			return (NULL);
		list->len = 0;
		list->first = cell;
		list->last = cell;
	}
	else if (list->len == 0)
	{
		list->first = cell;
		list->last = cell;
	}
	else
	{
		list->last->next = cell;
		cell->back = list->last;
		list->last = cell;
	}
	list->len++;
	return (list);
}

DList	*insertfirst_cell_Dlist(DList *list, List *cell)
{
	if (is_empty_Dlist(list))
	{
		list = malloc(sizeof(*list));
		if (!list)
			return (NULL);
		list->len = 0;
		list->first = cell;
		list->last = cell;
	}
	else if (list->len == 0)
	{
		list->first = cell;
		list->last = cell;
	}
	else
	{
		list->first->back = cell;
		cell->next = list->first;
		list->first = cell;
	}
	list->len++;
	return (list);
}

/*--------------------Utils-------------------------*/

DList	*insert_cell_Dlist(DList *list, List *cell, int mode)
{
	if (mode == 0)
		list = insertfirst_cell_Dlist(list, cell);
	else
		list = insertlast_cell_Dlist(list, cell);
	return (list);
}

List	*isolate_cell_Dlist(DList *list, int Mode)
{
	List	*cell;

	cell = isolate_lastcell_Dlist(list);
	if (cell != NULL)
		return (cell);
	if (Mode == 0)
	{
		cell = list->first;
		list->first = list->first->next;
		list->first->back = NULL;
		cell->next = NULL;
		cell->back = NULL;
		list->len--;
	}
	if (Mode != 0)
	{
		cell = list->last;
		list->last = list->last->back;
		list->last->next = NULL;
		cell->next = NULL;
		cell->back = NULL;
		list->len--;
	}
	return (cell);
}