

#include "../push_swap.h"

void	ft_printpiles(DList *A, DList *B)
{
	List *tmpA;
	List *tmpB;

	if (is_empty_Dlist(A) && is_empty_Dlist(B))
		return ;

	if (is_empty_Dlist(A))
		tmpA = NULL;
	else
		tmpA = A->first;
	
	if (is_empty_Dlist(B))
		tmpB = NULL;
	else
		tmpB = B->first;

	while (tmpA != NULL || tmpB != NULL)
	{
		if (tmpA == NULL)
			ft_printf("[vide]");
		else
		{
			ft_printf("[%d]", tmpA->data);
			tmpA = tmpA->next;
		}
		ft_printf(" ");
		if (tmpB == NULL)
			ft_printf("[vide]\n");
		else
		{
			ft_printf("[%d]\n", tmpB->data);
			tmpB = tmpB->next;
		}
	}
}

void	ft_print_move(Move move)
{
	if (move == pa)
		ft_printf("pa\n");
	if (move == pb)
		ft_printf("pb\n");
	if (move == sa)
		ft_printf("sa\n");
	if (move == sb)
		ft_printf("sb\n");
	if (move == ss)
		ft_printf("ss\n");
	if (move == ra)
		ft_printf("ra\n");
	if (move == rra)
		ft_printf("rra\n");
	if (move == rb)
		ft_printf("rb\n");
	if (move == rrb)
		ft_printf("rrb\n");
	if (move == rr)
		ft_printf("rr\n");
	if (move == rrr)
		ft_printf("rrr\n");
}

void    ft_print_allmove(DList *Move)
{
	int		i;
	List	*cell;

	if (Move->len == 0)
		return ;
	cell = Move->first;
	i = 1;
	while (i <= Move->len)
	{
		ft_print_move(cell->data);
		cell = cell->next;
		i++;
	}
}
