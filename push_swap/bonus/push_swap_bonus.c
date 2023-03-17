/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:07:03 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/16 16:56:36 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int do_move(char *move, t_ctrl *all)
{
	if (ft_strncmp(test, "pa\n", 3) == 0)
		return (all_move(all->list_a, all->list_b, pa));
	else if (ft_strncmp(test, "pb\n", 3) == 0)
		return (all_move(all->list_a, all->list_b, pb));
	else if (ft_strncmp(test, "sa\n", 3) == 0)
		return (all_move(all->list_a, all->list_b, sa));
	else if (ft_strncmp(test, "sb\n", 3) == 0)
		return (all_move(all->list_a, all->list_b, sb));
	else if (ft_strncmp(test, "ss\n", 3) == 0)
		return (all_move(all->list_a, all->list_b, ss));
	else if (ft_strncmp(test, "ra\n", 3) == 0)
		return (all_move(all->list_a, all->list_b, ra));
	else if (ft_strncmp(test, "rra\n", 4) == 0)
		return (all_move(all->list_a, all->list_b, rra));
	else if (ft_strncmp(test, "rb\n", 3) == 0)
		return (all_move(all->list_a, all->list_b, rb));
	else if (ft_strncmp(test, "rrb\n", 4) == 0)
		return (all_move(all->list_a, all->list_b, rrb));
	else if (ft_strncmp(test, "rr\n", 3) == 0)
		return (all_move(all->list_a, all->list_b, rr));
	else if (ft_strncmp(test, "rrr\n", 4) == 0)
		return (all_move(all->list_a, all->list_b, rrr));
	else
		return (-1);
}

int	ft_instruction_list(t_ctrl *all, )
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		do_move(move, all);
		free(move);
		move = get_next_line(0);
	}
}

void	check_result(t_ctrl *all)
{
	t_cell	*cell;
	t_cell	*cell_back;
	int		pos;

	pos = 1;
	cell_back = all->list_a->last;
	cell = all->list_a->first;
	if (all->list_a->len != all->max_len
		|| cell->final_pos != 1)
		ft_printf("KO!\n");
	while (cell != NULL)
	{
		if (check_is_aligned(cell, cell_back, all->max_len, 0) == false)
			ft_printf("KO!\n");
		cell_back = cell;
		cell = cell->next;
	}
	ft_printf("OK!\n");
}


int main(int argc, char **argv)
{
	int		i;
	t_ctrl	*all;
	char	**str_values;

	str_values = NULL;
	str_values = get_values(argc, argv);
	if (str_values == NULL)
	{
		return (EXIT_FAILURE);
	}
	if (is_error(str_values) == true)
	{
		free_str_values(str_values);
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	all = malloc(sizeof(*all));
	if (!all)
		return (EXIT_FAILURE);
	set_all_list(all);
	i = -1;
	while (values[++i])
		all->list_a = insert_data_list(all->list_a, ft_atoi(values[i]), 1);
	if (all->list_a->len == 1)
		return ;
	set_all_cell(all);
	get_final_pos(all);

	free_str_values(str_values);
	free_all_list(all->list_a);
	free_all_list(all->list_b);
	free_all_list(all->move);
	free(all);
}