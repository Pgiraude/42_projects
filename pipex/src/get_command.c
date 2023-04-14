/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:07:07 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/14 13:48:33 by pgiraude         ###   ########.fr       */
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

int	get_path(char **envp, char *path, char **options)
{
	char	*line_envp;
	char	**all_paths;
	char	*the_path;
	char	*cmd;
	int		i;

	line_envp = get_environnement(envp);
	if (line_envp == NULL)
		return (1);
	all_paths = ft_split(line_envp, ':');
	i = -1;
	while (all_paths[++i])
	{
		cmd = ft_strjoin("/", options[0]);
		the_path = ft_strjoin(all_paths[i], cmd);
		if (access(the_path, F_OK) == 0)
		{
			path = the_path;
			return (free (cmd), ft_freestrings(all_paths), 0);
		}
		free (the_path);
		free (cmd);
	}
	ft_printf("Command %s not found : %s", options[0], strerror(errno));
	return (ft_freestrings(all_paths), 2);
}

int	check_path(char *path, char **options)
{
	char	**tmp;
	int		i;

	path = options[0];
	options[0] = NULL;
	tmp = NULL;
	tmp = ft_split(path, '/');
	i = 0;
	while (tmp[i])
		i++;
	options[0] = ft_strdup(tmp[i - 1]);
	ft_freestrings(tmp);
	if (access(path, F_OK) == 0)
		return (0);
	ft_printf("Command %s not found : %s", options[0], strerror(errno));
	return (1);
}

int	get_command(int nbr_cmd, char **argv, char **envp, t_data *data)
{
	int	index;

	data->index_cmd = nbr_cmd - 1;
	data->path = NULL;
	data->options = NULL;
	data->options = ft_split(argv, ' ');
	if (ft_strchr(data->options[0], '/'))
		check_path(data->path, data->options);
	else
		get_path(envp, data->path, data->options);

	return (0);
}


	// while (++index <= data->index_cmd)
	// {
	// 	data->options[index] = ft_split(argv[index], ' ');
	// 	if (ft_strchr(data->options[index][0], '/'))
	// 		error += check_path(index, data);
	// 	else
	// 		error += get_path(envp, index, data);
	// 	if (error != 0)
	// 		return (get_command_error(index, argv, data));
	// }
	// data->options[index] = NULL;
	// data->paths[index] = NULL;