/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:07 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/27 21:25:56 by pgiraude         ###   ########.fr       */
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

int	get_path(char **envp, char **path, char ***options)
{
	char	*line_envp;
	char	**all_paths;
	char	*the_path;
	char	*cmd;
	int		i;

	line_envp = get_environnement(envp);
	if (line_envp == NULL)
		return (error_manager(NULL, NULL, 7), 7);
	all_paths = ft_split(line_envp, ':');
	i = -1;
	while (all_paths[++i])
	{
		cmd = ft_strjoin("/", *options[0]);
		the_path = ft_strjoin(all_paths[i], cmd);
		if (access(the_path, F_OK) == 0)
		{
			*path = the_path;
			return (free (cmd), ft_freestrings(all_paths), 0);
		}
		free (the_path);
		free (cmd);
	}
	error_manager(*options[0], NULL, 6);
	return (ft_freestrings(all_paths), 6);
}

int	check_path(char **path, char ***options)
{
	char	**tmp;
	int		i;

	*path = *options[0];
	*options[0] = NULL;
	tmp = NULL;
	tmp = ft_split(*path, '/');
	i = 0;
	while (tmp[i])
		i++;
	*options[0] = ft_strdup(tmp[i - 1]);
	ft_freestrings(tmp);
	if (access(*path, F_OK) == 0)
		return (0);
	error_manager(*options[0], NULL, 6);
	return (6);
}

int	get_command(char *cmd, char **envp, t_data *data, int index)
{
	char	*tmp;

	data->path = NULL;
	data->options = NULL;
	if (cmd[0] == '\0')
	{
		tmp = ft_itoa(index + 1);
		error_manager(tmp, NULL, 5);
		free (tmp);
		return (5);
	}
	data->options = ft_split(cmd, ' ');
	if (ft_strchr(data->options[0], '/'))
		return (check_path(&data->path, &data->options));
	else
		return (get_path(envp, &data->path, &data->options));
	return (0);
}
