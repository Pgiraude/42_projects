/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:44:13 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/11 18:53:12 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	p_move(t_list *list_a, t_list *list_b, e_move mode)
{
	if (mode == pa && list_b->len >= 1)
		push_move(list_b, list_a);
	else if (mode == pb && list_a->len >= 1)
		push_move(list_a, list_b);
	else
		return (-1);
	return (mode);
}

int	s_move(t_list *list_a, t_list *list_b, e_move mode)
{
	if (mode == sa && list_a->len >= 2)
		swap_move(list_a);
	else if (mode == sb && list_b->len >= 2)
		swap_move(list_b);
	else if (mode == ss && list_a->len >= 2 && list_b->len >= 2)
	{
		swap_move(list_a);
		swap_move(list_b);
	}
	else
		return (-1);
	return (mode);
}

int	r_move(t_list *list_a, t_list *list_b, e_move mode)
{
	if (mode == ra && list_a->len >= 2)
		rup_move(list_a);
	else if (mode == rb && list_b->len >= 2)
		rup_move(list_b);
	else if (mode == rr && list_a->len >= 2 && list_b->len >= 2)
	{
		rup_move(list_a);
		rup_move(list_b);
	}
	else if (mode == rra && list_a->len >= 2)
		rdo_move(list_a);
	else if (mode == rrb && list_b->len >= 2)
		rdo_move(list_b);
	else if (mode == rrr && list_a->len >= 2 && list_b->len >= 2)
	{
		rdo_move(list_a);
		rdo_move(list_b);
	}
	else
		return (-1);
	return (mode);
}

int	all_move(t_list *list_a, t_list *list_b, e_move mode)
{
	int	check_error;

	if (mode == pa || mode == pb)
		check_error = p_move(list_a, list_b, mode);
	else if (mode == sa || mode == sb || mode == ss)
		check_error = s_move(list_a, list_b, mode);
	else if (mode == ra || mode == rb || mode == rr)
		check_error = r_move(list_a, list_b, mode);
	else if (mode == rra || mode == rrb || mode == rrr)
		check_error = r_move(list_a, list_b, mode);
	else
		check_error = -1;
	return (check_error);
}
