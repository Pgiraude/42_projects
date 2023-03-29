/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:06 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/21 16:58:59 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_environnement(char **envp)
{
	int	i;

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

void	child_process(t_data data, int file1, char **envp, pid_t pid)
{

	while (data.nbr_cmd >= 0)
	{
		if (pid == 0)
		{
			if (data.nbr_cmd == 0)
			{
				close(data.tab_fd[0][READ]);
				dup2(file1, STDIN_FILENO);
				dup2(data.tab_fd[0][WRITE], STDOUT_FILENO);
				close(data.tab_fd[0][WRITE]);
				execve(data.paths[0], data.options[0], envp);
			}
			else
			{
				data.nbr_cmd--;
				pipe(data.tab_fd[data.nbr_cmd]);
				pid = fork();
			}
		}
		if (pid > 0)
		{
			data.nbr_cmd++;
			wait(NULL);

			dup2(data.tab_fd[data.nbr_cmd - 1][READ], STDIN_FILENO);
			dup2(data.tab_fd[data.nbr_cmd][WRITE], STDOUT_FILENO);
			close(data.tab_fd[data.nbr_cmd - 1][READ]);
			close(data.tab_fd[data.nbr_cmd - 1][WRITE]);
			execve(data.paths[data.nbr_cmd], data.options[data.nbr_cmd], envp);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		file1;
	int		file2;
	pid_t	pid;
	int		*fd;
	int		i;
	char	*cmd;

	if (argc < 5)
	{
		ft_printf("Error : need more arguments\n");
		return (1);
	}
	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		ft_printf("Error : cannot open %s\n", argv[1]);
		return (2);
	}
	file2 = open(argv[argc - 1], O_WRONLY);
	if (file2 < 0)
	{
		ft_printf("Error : cannot open %s\n", argv[argc - 1]);
		return (3);
	}

	data.nbr_cmd = argc - 4;
	data.options = malloc(sizeof(char**) * (data.nbr_cmd + 1));
	if (!data.options)
		return (4);
	data.paths = malloc(sizeof(char*) * (data.nbr_cmd + 1));
	if (!data.paths)
		return (5);
	i = 0;
	while (i <= data.nbr_cmd)
	{
		data.options[i] = ft_split(argv[i + 2], ' ');
		cmd = NULL;
		cmd = ft_strjoin("/", data.options[i][0]);
		data.paths[i] = get_path(envp, cmd);
		free (cmd);
		if (data.paths[i] == NULL)
		{
			ft_printf("Error : couldn't found command %s\n", argv[i + 2]);
			while (i >= 0)
			{
				ft_freestrings(data.options[i]);
				i--;
			}
			free (data.options);
			ft_freestrings(data.paths);
			return (6);
		}
		i++;
	}
	data.options[i] = NULL;
	data.paths[i] = NULL;

	printf("path1=%s\n", data.paths[0]);
	printf("path2=%s\n", data.paths[1]);

	data.tab_fd = malloc(sizeof(int*) * (data.nbr_cmd + 2));
	if (!data.tab_fd)
		return (7);
	i = 0;
	while (i <= data.nbr_cmd)
	{
		fd = malloc(sizeof(int) * (2 + 1));
		if (!fd)
			return (8);
		fd[2] = '\0';
		data.tab_fd[i] = fd;
		i++;
	}
	data.tab_fd[i] = NULL;

/*-----------start of processing---------------*/
	int max;

	data.nbr_cmd -= 1;
	max = data.nbr_cmd;
	pipe(data.tab_fd[data.nbr_cmd]);
	pid = fork();

	if (pid == 0)
	{
		child_process(data, file1, envp, pid);
	}
	if (pid > 0)
	{
		close(data.tab_fd[max][WRITE]);
		dup2(file2, STDOUT_FILENO);
		dup2(data.tab_fd[max][READ], STDIN_FILENO);
		close(data.tab_fd[max][READ]);
		execve(data.paths[data.nbr_cmd + 1], data.options[data.nbr_cmd + 1], envp);
	}
}