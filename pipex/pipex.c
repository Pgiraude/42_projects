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

void	child_process(t_data data, int file1, char **envp, pid_t pid)
{

	while (data.nbr_cmd >= 0)
	{
		if (pid == 0)
		{
			if (data.nbr_cmd == 0)
			{
				dup2(file1, STDIN_FILENO);
				dup2(data.tab_fd[0][WRITE], STDOUT_FILENO);
				close(data.tab_fd[0][WRITE]);
				close(data.tab_fd[0][READ]);
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
			close(data.tab_fd[data.nbr_cmd][WRITE]);
			close(data.tab_fd[data.nbr_cmd][READ]);
			execve(data.paths[data.nbr_cmd], data.options[data.nbr_cmd], envp);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	pid_t	pid;
	int		*fd;
	int		i;
	char	*cmd;

	if (open_file(argc, argv, &data) != 0)
		return (1);
	if (get_command(argc, argv, envp, &data) != 0)
		return (2);
	if (prepare_pipe(&data)!= 0)
		return (3);

	ft_printf("path1=%s\n", data.paths[0]);
	ft_printf("path2=%s\n", data.paths[1]);




/*-----------start of processing---------------*/
	// int max;

	// data.nbr_cmd -= 1;
	// max = data.nbr_cmd;
	// pipe(data.tab_fd[data.nbr_cmd]);
	// pid = fork();

	// if (pid == 0)
	// {
	// 	child_process(data, file1, envp, pid);
	// }
	// if (pid > 0)
	// {
	// 	close(data.tab_fd[max][WRITE]);
	// 	dup2(file2, STDOUT_FILENO);
	// 	dup2(data.tab_fd[max][READ], STDIN_FILENO);
	// 	close(data.tab_fd[max][READ]);
	// 	execve(data.paths[data.nbr_cmd + 1], data.options[data.nbr_cmd + 1], envp);
	// }

	free_all(&data);
}