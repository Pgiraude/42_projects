/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:07:49 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/17 11:09:48 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_move(t_move move)
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

void	ft_print_allmove(t_list *move)
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
