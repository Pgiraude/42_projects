

#include "../push_swap.h"

void	fusion_Dlist(DList *Inf, DList *Piv, DList *Sup)
{
	if (!is_empty_Dlist(Inf))
	{
		Inf->last->next = Piv->first;
		Piv->last->back = Inf->last;
		Piv->first = Inf->first;
		Inf->first = NULL;
		Inf->last = NULL;
		Piv->len = Piv->len + Inf->len;
		free (Inf);
	}
	if (!is_empty_Dlist(Sup))
	{
		Sup->first->back = Piv->last;
		Piv->last->next = Sup->first;
		Piv->last = Sup->last;
		Sup->first = NULL;
		Sup->last = NULL;
		Piv->len = Piv->len + Sup->len;
		free (Sup);
	}
}

void	quicksort_split(DList *list, DList **list_inf, DList **list_sup)
{
	List *cell;

	cell = list->first;
	if (list->last->data > list->first->data)
	{
		list->first = list->first->next;
		list->first->back = NULL;
		cell->next = NULL;
		cell->back = NULL;
		list->len--;
		*list_inf = insert_cell_Dlist(*list_inf, cell, 1);
	}
	else
	{
		list->first = list->first->next;
		list->first->back = NULL;
		cell->next = NULL;
		cell->back = NULL;
		list->len--;
		*list_sup = insert_cell_Dlist(*list_sup, cell, 1);
	}
}

void	quick_sort(DList *list)
{
	DList	*list_sup;
	DList	*list_inf;

	list_sup = NULL;
	list_inf = NULL;
	while (list->last != list->first)
	{
		quicksort_split(list, &list_inf, &list_sup);
	}
	if (!is_empty_Dlist(list_inf))
	{
		if (list_inf->len != 1)
			quick_sort(list_inf);
	}
	if (!is_empty_Dlist(list_sup))
	{
		if (list_sup->len != 1)
			quick_sort(list_sup);
	}
	fusion_Dlist(list_inf, list, list_sup);
}