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

int check_move(int argc, char **argv)
{
	if (ft_strncmp(test, "pa\n", 3) == 0)
		return (3);
	else if (ft_strncmp(test, "pb\n", 3) == 0)
		return (3);
	else if (ft_strncmp(test, "sa\n", 3) == 0)
		return (3);
	else if (ft_strncmp(test, "sb\n", 3) == 0)
		return (3);
	else if (ft_strncmp(test, "ss\n", 3) == 0)
		return (3);
	else if (ft_strncmp(test, "ra\n", 3) == 0)
		return (3);
	else if (ft_strncmp(test, "rra\n", 4) == 0)
		return (4);
	else if (ft_strncmp(test, "rb\n", 3) == 0)
		return (3);
	else if (ft_strncmp(test, "rrb\n", 4) == 0)
		return (4);
	else if (ft_strncmp(test, "rr\n", 3) == 0)
		return (3);
	else if (ft_strncmp(test, "rrr\n", 4) == 0)
		return (4);
	else
		return (-1);
}

int	

int main(int argc, char **argv)
{
	t_ctrl  *all;
	int		i;

	if (argc == 1)
		return (EXIT_FAILURE);
	else if (is_error(argc, argv) == true)
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	all = malloc(sizeof(*all));
	if (!all)
		return (EXIT_FAILURE);
	set_all_list(all);
	i = 1;
	while (i < argc)
	{
		all->list_a = insert_data_list(all->list_a, ft_atoi(argv[i]), 1);
		i++;
	}
	set_all_cell(all);
	get_final_pos(all);
}