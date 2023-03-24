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


int	main(int argc, char **argv, char **envp)
{
	int		i;
	pid_t	pid;
	int		file1;
	int		file2;

	// if (argc < 5)
	// {
	// 	ft_printf("Error, not enough argument\n");
	// 	return (1); 
	// }

	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		ft_printf("Error, cannot open fd1=%s\n", argv[1]);
		return (1);
	}

	file2 = open(argv[2], O_WRONLY);
	if (file2 < 0)
	{
		ft_printf("Error, cannot open file2=%s\n", argv[4]);
		return (1);
	}


	i = 0;
	while (envp[i])
	{
		// ft_printf("variable d'environnement =%s\n", envp[i]);
		i++;
	}

/*  test pipe */
	char buffer[12];
	int	pid_fd[2];
	pipe(pid_fd);

	write(pid_fd[1], "Pipe : test\n", ft_strlen("Pipe : test\n"));

	// read(pid_fd[0], buffer, 11);
	// printf("%s", buffer);
/*  test pipe */

	pid = fork();
	// if (pid < 0)
	// {
	// 	ft_printf("fork failed\n");
	// 	return (1);
	// }

	if (pid == 0)
	{
		/* test redirection*/
		ft_printf("\n\n");
		close(pid_fd[1]);	
		ft_printf("i m the son PID =%d ->print avant test\n", pid);
		dup2(pid_fd[0], STDOUT_FILENO);
		dup2(file2, STDIN_FILENO);
		close(pid_fd[0]);
		close(file2);
		ft_printf("Child : is it print in the file?\n");
	}
	if (pid != 0)
	{
		ft_printf("\n\n");		
		ft_printf("i m the father PID =%d\n", pid);
		ft_printf("test printf father?\n");
	}

}