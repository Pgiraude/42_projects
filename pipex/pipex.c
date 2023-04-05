/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:06 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/30 16:53:12 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_process(int index_cmd, char **envp, pid_t pid, t_data *data)
{
	if (pid == 0)
	{
		dup2(data->file1, STDIN_FILENO);
		dup2(data->tab_fd[0][WRITE], STDOUT_FILENO);
		close(data->tab_fd[0][WRITE]);
		close(data->tab_fd[0][READ]);
		execve(data->paths[0], data->options[0], envp);
	}
	if (pid > 0)
	{
		// wait(NULL);
		dup2(data->tab_fd[index_cmd][READ], STDIN_FILENO);
		dup2(data->tab_fd[index_cmd + 1][WRITE], STDOUT_FILENO);
		close(data->tab_fd[index_cmd][READ]);
		close(data->tab_fd[index_cmd][WRITE]);
		close(data->tab_fd[index_cmd + 1][WRITE]);
		close(data->tab_fd[index_cmd + 1][READ]);
		execve(data->paths[index_cmd + 1], data->options[index_cmd + 1], envp);
	}
}

int	loop_process(t_data *data, char **envp, pid_t pid)
{
	while (1)
	{
		if (pid == 0)
		{
			if (data->index_cmd == 0)
			{
				execve_process(data->index_cmd, envp, pid, data);
				return (2);
			}
			else
			{
				data->index_cmd--;
				if (pipe(data->tab_fd[data->index_cmd]) < 0)
					return (1);
				pid = fork();
			}
		}
		if (pid > 0)
		{
			execve_process(data->index_cmd, envp, pid, data);
			return (3);
		}
	}
}

int	lunch_process(char **envp, t_data *data)
{
	int 	max;
	pid_t	pid;

	data->index_cmd -= 1;
	max = data->index_cmd;
	if (pipe(data->tab_fd[data->index_cmd]) < 0)
		return (1);
	pid = fork();
	if (pid == 0)
		loop_process(data, envp, pid);
	if (pid > 0)
	{
		close(data->tab_fd[max][WRITE]);
		dup2(data->file2, STDOUT_FILENO);
		dup2(data->tab_fd[max][READ], STDIN_FILENO);
		close(data->tab_fd[max][READ]);
		execve(data->paths[max + 1], data->options[max + 1], envp);
	}
	ft_printf("Error : execution of processus didn't work\n");
	free_all(data);
	return (2);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	pid_t	pid;
	char	*cmd;

	if (open_file(argc, argv, envp, &data) != 0)
		return (1);
	if (prepare_pipe(&data) != 0)
		return (4);
	pid = fork();
	if (pid == 0)
		lunch_process(envp, &data);
	wait(NULL);
	free_all(&data);
}