

#include "../push_swap.h"

void	ft_printpiles(t_list *A, t_list *B)
{
	t_cell *tmpA;
	t_cell *tmpB;

	if (is_empty_list(A) && is_empty_list(B))
		return ;

	if (is_empty_list(A))
		tmpA = NULL;
	else
		tmpA = A->first;
	
	if (is_empty_list(B))
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

void    printf_list(t_list *list)
{
    if (is_empty_list(list))
        return ;
    t_cell *tmp = list->first;

    while(tmp != NULL)
    {
        ft_printf("[%d] ", tmp->data);
        tmp = tmp->next;
    }
}

void	ft_print_move(e_move move)
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

void    ft_print_allmove(t_list *move)
{
	int		i;
	t_cell	*cell;

	if (move->len == 0)
		return ;
	cell = move->first;
	i = 1;
	while (i <= move->len)
	{
		ft_print_move(cell->data);
		cell = cell->next;
		i++;
	}
}
