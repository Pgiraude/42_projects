
#include "../push_swap.h"

Bool	is_empty_Dlist(DList *list)
{
	if (list)
		return (false);
	else
		return (true);
}

DList	*create_Dlist(DList *list)
{
	if (is_empty_Dlist(list))
	{
		list = malloc(sizeof(*list));
		if (!list)
			return (NULL);
		list->len = 0;
		list->first = NULL;
		list->last = NULL;
		return (list);
	}
	return (list);
}

DList	*insertlast_data_Dlist(DList *list, int data)
{
	List	*cell;

	cell = malloc(sizeof(*cell));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
	cell->back = NULL;
	if (is_empty_Dlist(list) || list->len == 0)
	{
		list = create_Dlist(list);
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

DList	*insertfirst_data_Dlist(DList *list, int data)
{
	List	*cell;

	cell = malloc(sizeof(*cell));
	if (!cell)
		return (NULL);
	cell->data = data;
	cell->next = NULL;
	cell->back = NULL;
	if (is_empty_Dlist(list) || list->len == 0)
	{
		list = create_Dlist(list);
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

DList	*insert_data_Dlist(DList *list, int data, int mode)
{
	if (mode == 0)
		return(insertfirst_data_Dlist(list, data));
	else
		return(insertlast_data_Dlist(list, data));
}