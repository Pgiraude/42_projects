/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:06 by pgiraude          #+#    #+#             */
/*   Updated: 2023/07/20 12:26:19 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	exec_child(int fd_stdin, int *fd, int index, t_data *data)
{
	if (index == data->index_cmd)
		dup2(data->file2, STDOUT_FILENO);
	else
		dup2(fd[WRITE], STDOUT_FILENO);
	dup2(fd_stdin, STDIN_FILENO);
	close(fd[WRITE]);
	close(fd[READ]);
	data->pid[index] = execve(data->path, data->options, data->env);
	if (index != 0)
		close (fd_stdin);
	error_manager(NULL, data, 9);
}

int	launch_child(int fd_stdin, int index, char *cmd, t_data *data)
{
	int		fd[2];

	if (pipe(fd) == -1)
		error_manager(NULL, data, 4);
	data->pid[index] = fork();
	if (data->pid[index] == -1)
		error_manager(NULL, data, 4);
	if (data->pid[index] == 0)
	{
		if ((fd_stdin == -1) || (index == data->index_cmd && data->file2 == -1) \
			|| get_command(cmd, data->env, data, index) != 0)
		{
			if (index != 0)
				close (fd_stdin);
			close(fd[WRITE]);
			close(fd[READ]);
			error_manager(NULL, data, 8);
		}
		exec_child(fd_stdin, fd, index, data);
	}
	close(fd[WRITE]);
	return (fd[READ]);
}

int	launch_process(char **all_cmd, t_data *data)
{
	int		index;
	int		fd_read;
	int		last_read;

	fd_read = data->file1;
	index = 0;
	while (index <= data->index_cmd)
	{
		last_read = fd_read;
		fd_read = launch_child(fd_read, index, all_cmd[index], data);
		if (last_read != -1)
			close(last_read);
		index++;
	}
	close(fd_read);
	wait_all_child(data);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		first_cmd;

	data.path = NULL;
	data.options = NULL;
	data.env = envp;
	if (open_file(argc, argv, &first_cmd, &data) != 0)
		return (1);
	data.pid = malloc(sizeof(pid_t) * (data.index_cmd + 2));
	if (!data.pid)
		return (1);
	data.pid[data.index_cmd + 1] = '\0';
	launch_process(argv + first_cmd, &data);
	if (is_here_doc(argv) && first_cmd == 3)
		unlink (".heredoc");
	exit_clean(&data, 0);
}
