/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:51:48 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/27 21:27:45 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	check_arguments(int argc, char **argv, int min_arg)
{
	int	i;

	if (argc < min_arg + 1)
	{
		ft_printf("Error : need more arguments\n");
		return (1);
	}
	i = 1;
	while (i < argc - 1)
	{
		if (argv[i][0] == '\0')
		{
			ft_printf("Error : one argument is empty\n");
			return (2);
		}
		i++;
	}
	return (0);
}

int	is_here_doc(char **argv)
{
	if (ft_strnstr(argv[1], "here_doc", 8) && ft_strlen(argv[1]) == 8)
		return (1);
	else
		return (0);
}

void	wait_all_child(t_data *data)
{
	int		wstatus;
	pid_t	end_status;
	int		i;

	i = 0;
	while (i <= data->index_cmd)
	{
		end_status = waitpid(data->pid[i], &wstatus, 0);
		i++;
	}
}
