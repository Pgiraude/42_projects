/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cost_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:08:55 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/17 13:19:42 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_paire(int len)
{
	int	paire;

	paire = 0;
	if (len % 2 == 0)
		paire = 1;
	return (paire);
}

void	calculate_bonus_cost(t_ctrl *all)
{
	t_cell	*cell;
	int		sign;
	int		i;

	cell = all->list_b->first;
	while (cell != NULL)
	{
		sign = 1;
		i = 0;
		if (i < cell->cost_a && i < cell->cost_b)
			while (i < cell->cost_a && i < cell->cost_b)
				i++;
		else if (i > cell->cost_a && i > cell->cost_b)
			while (i > cell->cost_a && i > cell->cost_b)
				i--;
		else if ((cell->move_a == true && i > cell->cost_b)
			|| (cell->move_b == true && i > cell->cost_a))
			while (i > cell->cost_b || i > cell->cost_a)
				i--;
		if (i > 0)
			sign = -1;
		cell->bonus_cost = i * sign;
		cell = cell->next;
	}
}

int	get_score(t_cell *target, t_cell *compare, int max_len, int mode)
{
	int	position;
	int	score;

	position = target->final_pos;
	score = 0;
	if (mode == 0)
	{
		while (position-- != compare->final_pos)
		{
			score++;
			if (position < 1)
				position = max_len;
		}
	}
	else
	{
		while (position++ != compare->final_pos)
		{
			score++;
			if (position > max_len)
				position = 1;
		}
	}
	return (score);
}
