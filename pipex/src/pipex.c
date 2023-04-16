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
	pid = fork();
	if (pid == 0)
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
		index++;
	}
	close(fd_read);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*cmd;
	int		i;

	if (open_file(argc, argv, &data) != 0)
		return (1);



	int first_cmd;
	if (is_here_doc(argv))
	{
		data.index_cmd = argc - 4 - 1;
		first_cmd = 3;
	}
	else
	{
		data.index_cmd = argc - 3 - 1;
		first_cmd = 2;
	}
	lunch_process(envp, argv + first_cmd, &data);



	// i = 0;
	// while (wait(NULL) != -1)
	// {
	// 	// wait(NULL);
	// 	ft_printf("waited for a child to finish\n");
	// 	i++;
	// }
	// ft_printf("all children finish\n");
	// exit_clean(argv, &data);
}
// wait(NULL) != -1 || errno != ECHILD