/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_aligned.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:46:47 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/14 16:28:30 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	check_is_aligned(t_cell *targ, t_cell *comp, int max_len, int mode)
{
	if (targ == NULL || comp == NULL)
		return (false);
	if (mode == 0)
	{
		if (targ->final_pos == comp->final_pos + 1)
			return (true);
		else if (targ->final_pos == 1 && comp->final_pos == max_len)
			return (true);
	}
	else if (mode == 1)
	{
		if (targ->final_pos == comp->final_pos - 1)
			return (true);
		else if (targ->final_pos == max_len && comp->final_pos == 1)
			return (true);
	}
	else if (mode == 2)
	{
		if (targ->final_pos == 1 && comp->final_pos == max_len)
			return (true);
	}
	return (false);
}
