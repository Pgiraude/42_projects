/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:51:48 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/06 16:12:59 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


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

int	prepare_pipe(t_data *data)
{
	int	*fd;
	int	i;

	data->tab_fd = malloc(sizeof(int *) * (data->index_cmd + 2));
	if (!data->tab_fd)
		return (1);
	i = 0;
	while (i <= data->index_cmd)
	{
		fd = malloc(sizeof(int) * (2 + 1));
		if (!fd)
			return (2);
		fd[2] = '\0';
		data->tab_fd[i] = fd;
		i++;
	}
	data->tab_fd[i] = NULL;
	return (0);
}

void	free_all(char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (data->options[i])
	{
		ft_freestrings(data->options[i]);
		i++;
	}
	free(data->options);
	if (data->paths)
		ft_freestrings(data->paths);
	i = 0;
	while (i <= data->index_cmd)
	{
		free (data->tab_fd[i]);
		i++;
	}
	free (data->tab_fd);
	close(data->file1);
	close(data->file2);
	if (ft_strnstr(argv[1], "here_doc", 8) && ft_strlen(argv[1]) == 8)
		unlink (".heredoc");
	
}