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
	int		fd;
	int		fd2;

	// if (argc < 5)
	// {
	// 	ft_printf("Error, not enough argument\n");
	// 	return (1); 
	// }

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error, cannot open fd1=%s\n", argv[1]);
		return (1);
	}

	fd2 = open(argv[2], O_WRONLY);
	if (fd2 < 0)
	{
		ft_printf("Error, cannot open fd2=%s\n", argv[4]);
		return (1);
	}



	i = 0;
	while (envp[i])
	{
		// ft_printf("variable d'environnement =%s\n", envp[i]);
		i++;
	}

	char buffer[12];
	int	pfd[2];
	pipe(pfd);

	write(pfd[1], "test pipe\n", ft_strlen("test pipe\n"));
	
	read(pfd[0], buffer, 11);
	printf("%s", buffer);

	pid = fork();
	if (pid < 0)
	{
		ft_printf("fork failed\n");
		return (1);
	}

	if (pid == 0)
	{
		ft_printf("i m the son PID =%d\n", pid);
	}
	if (pid != 0)
	{
		ft_printf("i m the father PID =%d\n", pid);
	}
}