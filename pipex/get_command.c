/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:07 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/11 13:43:18 by pgiraude         ###   ########.fr       */
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

int	get_command(int nbr_cmd, char **argv, char **envp, t_data *data)
{
	int		i;
	char	*cmd;

	data->index_cmd = nbr_cmd - 1;
	data->options = malloc(sizeof(char **) * (nbr_cmd + 1));
	if (!data->options)
		return (close(data->file1), close(data->file2), 4);
	data->paths = malloc(sizeof(char *) * (nbr_cmd + 1));
	if (!data->paths)
		return (close(data->file1), close(data->file2), 5);
	i = 0;
	while (i <= data->index_cmd)
	{
		
		data->options[i] = ft_split(argv[i], ' ');
		if (ft_strchr(data->options[i][0], '/'))
		{
			data->paths[i] = ft_strdup(data->options[i][0]);

			char **tmp;
			tmp = ft_split(data->options[i][0], '/');
			int y = -1;
			while (tmp[++y])
			data->options[i][0] = tmp[y - 1];
			
			if (access(data->paths[i], F_OK) == 0)
				return (0);
			else
				return (get_command_error(i, argv, data));
			printf("TEST\n");
		}
		else
		{
			cmd = NULL;
			cmd = ft_strjoin("/", data->options[i][0]);
			data->paths[i] = get_path(envp, cmd);
			free (cmd);
			if (data->paths[i] == NULL)
				return (get_command_error(i, argv, data));
		}
		i++;
	}
	data->options[i] = NULL;
	data->paths[i] = NULL;
	return (0);
}
