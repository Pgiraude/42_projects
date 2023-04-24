/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:06 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/14 13:50:32 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	lunch_child(int fd_stdin, int index, char *cmd, t_data *data, char **envp)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	data->pid[index] = fork();
	if (data->pid[index] == -1)
		error_manager(NULL, 4);
	if (data->pid[index] == 0)
	{
		get_command(cmd, envp, data, index);
		dup2(fd_stdin, STDIN_FILENO); //recupère le pipe fd[READ] du précédant child
		if (index == data->index_cmd)
			dup2(data->file2, STDOUT_FILENO);
		else
			dup2(fd[WRITE], STDOUT_FILENO); //on écrit dans le pipe qui suit
		close(fd[WRITE]);
		close(fd[READ]);
		execve(data->path, data->options, envp);
		error_manager(NULL, 8);
	}
	close(fd[WRITE]); //on vient de write dans le process fils ce qui nous interesse donc on close dans process 
		return (fd[READ]); //on voudra read le pipe dans un autre process fils donc on recup ici dans process père
}

int	lunch_process(char **envp, char **all_cmd, t_data *data)
{
	int		index;
	int		fd_read;
	int		last_read;

	fd_read = data->file1;
	index = 0;
	while (index <= data->index_cmd)
	{
		last_read = fd_read;
		fd_read = lunch_child(fd_read, index, all_cmd[index], data, envp);
		close(last_read);
		if (data->pid[index] <= 0)
			return (1);
		index++;
	}
	close(fd_read);
	wait_all_child(data);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*cmd;
	int		i;

	data.path = NULL;
	data.options = NULL;
	if (open_file(argc, argv, &data) != 0)
		return (1);
	data.index_cmd = argc - 3 - 1;
	data.pid = malloc(sizeof(pid_t) * (data.index_cmd + 2));
	if (!data.pid)
		return (1);
	data.pid[data.index_cmd + 1] = '\0';
	lunch_process(envp, argv + 2, &data);



	// i = 0;
	// while (wait(NULL) != -1)
	// {
	// 	// wait(NULL);
	// 	ft_printf("waited for a child to finish\n");
	// 	i++;
	// }
	// ft_printf("all children finish\n");
	exit_clean(argv, &data);
}
// wait(NULL) != -1 || errno != ECHILD