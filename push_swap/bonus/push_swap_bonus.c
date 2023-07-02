/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:07:03 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/17 15:09:05 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	do_move(char *move, t_list *list_a, t_list *list_b)
{
	if (ft_strcmp(move, "pa\n") == 0)
		return (all_move(list_a, list_b, pa));
	else if (ft_strcmp(move, "pb\n") == 0)
		return (all_move(list_a, list_b, pb));
	else if (ft_strcmp(move, "sa\n") == 0)
		return (all_move(list_a, list_b, sa));
	else if (ft_strcmp(move, "sb\n") == 0)
		return (all_move(list_a, list_b, sb));
	else if (ft_strcmp(move, "ss\n") == 0)
		return (all_move(list_a, list_b, ss));
	else if (ft_strcmp(move, "ra\n") == 0)
		return (all_move(list_a, list_b, ra));
	else if (ft_strcmp(move, "rra\n") == 0)
		return (all_move(list_a, list_b, rra));
	else if (ft_strcmp(move, "rb\n") == 0)
		return (all_move(list_a, list_b, rb));
	else if (ft_strcmp(move, "rrb\n") == 0)
		return (all_move(list_a, list_b, rrb));
	else if (ft_strcmp(move, "rr\n") == 0)
		return (all_move(list_a, list_b, rr));
	else if (ft_strcmp(move, "rrr\n") == 0)
		return (all_move(list_a, list_b, rrr));
	else
		return (-2);
}

int	ft_instruction_list(t_list *list_a, t_list *list_b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (do_move(move, list_a, list_b) == -2)
			return (free(move), EXIT_FAILURE);
		free(move);
		move = NULL;
		move = get_next_line(0);
	}
	return (0);
}

void	check_result(t_list *list_a, int max_len)
{
	t_cell	*cell;
	t_cell	*cell_back;

	cell_back = list_a->last;
	cell = list_a->first;
	if (list_a->len != max_len
		|| cell->final_pos != 1)
	{
		ft_printf("KO\n");
		return ;
	}
	while (cell != NULL)
	{
		if (check_is_aligned(cell, cell_back, max_len, 0) == false)
		{
			ft_printf("KO\n");
			return ;
		}
		cell_back = cell;
		cell = cell->next;
	}
	ft_printf("OK\n");
}

void	push_swap_bonus(t_ctrl *all, char **values)
{
	int	i;

	set_all_list(all);
	i = -1;
	while (values[++i])
		all->list_a = insert_data_list(all->list_a, ft_atoi(values[i]), 1);
	set_all_cell(all);
	get_final_pos(all);
	if (ft_instruction_list(all->list_a, all->list_b) == EXIT_FAILURE)
	{
		ft_printf("Error\n");
		return ;
	}
	check_result(all->list_a, all->max_len);
}

int	main(int argc, char **argv)
{
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
	push_swap_bonus(all, str_values);
	free_str_values(str_values);
	free_all_list(all->list_a);
	free_all_list(all->list_b);
	free_all_list(all->move);
	free(all);
}
