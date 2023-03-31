/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:07 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/30 17:08:50 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*get_path(char **envp, char *cmd)
{
	char	*line_envp;
	char	**paths;
	char	*the_path;
	int		i;

	i = 0;
	line_envp = NULL;
	line_envp = get_environnement(envp);
	if (line_envp == NULL)
		return (NULL);
	paths = ft_split(line_envp, ':');
	while (paths[i])
	{
		the_path = ft_strjoin(paths[i], cmd);
		i++;
		if (access(the_path, F_OK) == 0)
			return (ft_freestrings(paths), the_path);
		free (the_path);
	}
	return (ft_freestrings(paths), NULL);
}

int	get_command_error(int i, char **argv, t_data *data)
{
	ft_printf("Error : couldn't found command %s\n", argv[i + 2]);
	while (i >= 0)
	{
		ft_freestrings(data->options[i]);
		i--;
	}
	free (data->options);
	ft_freestrings(data->paths);
	return (6);
}

int	get_command(int argc, char **argv, char **envp, t_data *data)
{
	int		i;
	char	*cmd;

	data->index_cmd = argc - 4;
	data->options = malloc(sizeof(char **) * (data->index_cmd + 2));
	if (!data->options)
		return (4);
	data->paths = malloc(sizeof(char *) * (data->index_cmd + 2));
	if (!data->paths)
		return (5);
	i = 0;
	while (i <= data->index_cmd)
	{
		data->options[i] = ft_split(argv[i + 2], ' ');
		cmd = NULL;
		cmd = ft_strjoin("/", data->options[i][0]);
		data->paths[i] = get_path(envp, cmd);
		free (cmd);
		if (data->paths[i] == NULL)
			return (get_command_error(i, argv, data));
		i++;
	}
	data->options[i] = NULL;
	data->paths[i] = NULL;
	return (0);
}
