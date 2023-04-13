/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:07 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/13 16:52:39 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_environnement(char **envp)
{
	int	i;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

int	get_path(char **envp, int index, t_data *data)
{
	char	*line_envp;
	char	**paths;
	char	*the_path;
	char	*cmd;
	int		i;

	line_envp = get_environnement(envp);
	if (line_envp == NULL)
		return (1);
	paths = ft_split(line_envp, ':');
	i = -1;
	while (paths[++i])
	{
		cmd = ft_strjoin("/", data->options[index][0]);
		the_path = ft_strjoin(paths[i], cmd);
		if (access(the_path, F_OK) == 0)
		{
			data->paths[index] = the_path;
			return (free (cmd), ft_freestrings(paths), 0);
		}
		free (the_path);
		free (cmd);
	}
	return (ft_freestrings(paths), 2);
}

int	get_command_error(int i, char **argv, t_data *data)
{
	ft_printf("Error : couldn't found command %s\n", argv[i]);
	while (i >= 0)
	{
		ft_freestrings(data->options[i]);
		i--;
	}
	free (data->options);
	ft_freestrings(data->paths);
	close(data->file1);
	close(data->file2);
	return (6);
}

int	check_path(int index, t_data *data)
{
	char	**tmp;
	int		i;

	data->paths[index] = data->options[index][0];
	data->options[index][0] = NULL;
	tmp = NULL;
	tmp = ft_split(data->paths[index], '/');
	i = 0;
	while (tmp[i])
		i++;
	data->options[index][0] = ft_strdup(tmp[i - 1]);
	ft_freestrings(tmp);
	if (access(data->paths[index], F_OK) == 0)
		return (0);
	return (1);
}

int	get_command(int nbr_cmd, char **argv, char **envp, t_data *data)
{
	int	index;
	int	error;

	data->index_cmd = nbr_cmd - 1;


	index = -1;
	error = 0;

	data->options = ft_split(argv, ' ');
	if (ft_strchr(data->options[0], '/'))
		error += check_path(index, data);
	else
		error += get_path(envp, index, data);

	
	while (++index <= data->index_cmd)
	{
		data->options[index] = ft_split(argv[index], ' ');
		if (ft_strchr(data->options[index][0], '/'))
			error += check_path(index, data);
		else
			error += get_path(envp, index, data);
		if (error != 0)
			return (get_command_error(index, argv, data));
	}
	data->options[index] = NULL;
	data->paths[index] = NULL;
	return (0);
}
