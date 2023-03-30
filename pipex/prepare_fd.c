/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:51:48 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/30 17:26:00 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc < 5)
	{
		ft_printf("Error : need more arguments\n");
		return (1);
	}
	i = 2;
	while (i - 2 < argc - 3)
	{
		if (argv[i][0] == '\0')
		{
			ft_printf("Error : one argument is empty\n");
			return (1);
		}
		i++;
	}
	data->file1 = open(argv[1], O_RDONLY);
	if (data->file1 < 0)
	{
		ft_printf("Error : cannot open %s\n", argv[1]);
		return (2);
	}
	data->file2 = open(argv[argc - 1], O_WRONLY);
	if (data->file2 < 0)
	{
		ft_printf("Error : cannot open %s\n", argv[argc - 1]);
		return (3);
	}
	return (0);
}

int	prepare_pipe(t_data *data)
{
	int	*fd;
	int	i;

	data->tab_fd = malloc(sizeof(int *) * (data->nbr_cmd + 2));
	if (!data->tab_fd)
		return (1);
	i = 0;
	while (i <= data->nbr_cmd)
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

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->options[i])
	{
		ft_freestrings(data->options[i]);
		i++;
	}
	free(data->options);
	ft_freestrings(data->paths);
	i = 0;
	while (i <= data->nbr_cmd)
	{
		free (data->tab_fd[i]);
		i++;
	}
	free (data->tab_fd);
	close(data->file1);
	close(data->file2);
}