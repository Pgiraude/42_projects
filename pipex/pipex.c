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
			return (envp[i++] + 5);
		i++;
	}
	return (NULL);
}

char	*get_command(char **envp, char *cmd)
{
	char	*line_envp;
	char	**paths;
	char	*the_path;
	int		i;

	line_envp = get_environnement(envp);
	while (line_envp != NULL)
	{
		i = 0;
		paths = ft_split(line_envp, ':');
		while (paths[i])
		{
			
			the_path = ft_strjoin(paths[i], cmd);
			i++;
			if (access(the_path, F_OK) == 0)
				return (the_path);
		}
		line_envp = get_environnement(envp);
	}
	return (NULL);
}

t_data	parsing(char *command, t_data data)
{
	data.cmd = ft_split(command, ' ');
}

int	main(int argc, char **argv, char **envp)
{
	// int		i;

	int		file1;
	int		file2;
	t_data	data;
	char	*path;
	char	*path2;
	char	*start_cmd;
	pid_t	pid;
	int		fd[2];
	char	***big_tab;
	int		i;

	data.cmd = NULL;

	big_tab = malloc(sizeof(char**) * (argc - 3 + 1));
	if (!big_tab)
		return (1);
	i = 2;
	while (i <= argc - 2)
	{
		big_tab[i - 2] = ft_split(argv[i], ' ');
		i++;
	}
	big_tab[i - 2] = NULL;

	start_cmd = big_tab[0][0];

	path = get_command(envp, ft_strjoin("/", start_cmd));

	printf("path1=%s + big_tab=%s\n", path, big_tab[1][0]);
	start_cmd = NULL;
	start_cmd = big_tab[1][0];

	path2 = get_command(envp, ft_strjoin("/", start_cmd));

	printf("path2=%s\n", path2);

	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[argc - 1], O_WRONLY);
	pipe(fd);

	pid = fork();

	if (pid == 0)
	{
		close(fd[0]);
		dup2(file1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execve(path, big_tab[0], envp);
	}
	if (pid > 0)
	{
		close(fd[1]);
		dup2(file2, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execve(path2, big_tab[1], envp);
	}
	// if (argc < 5)
	// {
	// 	ft_printf("Error, not enough argument\n");
	// 	return (1); 
	// }

// 	file1 = open(argv[1], O_RDONLY);
// 	if (file1 < 0)
// 	{
// 		ft_printf("Error, cannot open fd1=%s\n", argv[1]);
// 		return (1);
// 	}

// 	file2 = open(argv[argc - 1], O_WRONLY | O_RDONLY);
// 	if (file2 < 0)
// 	{
// 		ft_printf("Error, cannot open file2=%s\n", argv[4]);
// 		return (1);
// 	}


// 	i = 0;
// 	while (envp[i])
// 	{
// 		// ft_printf("variable d'environnement =%s\n", envp[i]);
// 		i++;
// 	}

// /*  test pipe */
// 	// char buffer[12];
// 	int	pid_fd[2];
// 	pipe(pid_fd);

// 	// write(pid_fd[1], "Pipe : test\n", ft_strlen("Pipe : test\n"));

// 	// read(pid_fd[0], buffer, 11);
// 	// printf("%s", buffer);
// /*  test pipe */

// 	pid = fork();
// 	// if (pid < 0)
// 	// {
// 	// 	ft_printf("fork failed\n");
// 	// 	return (1);
// 	// }

// 	if (pid == 0)
// 	{
// 		/* test redirection*/
// 		char *str;
// 		int	len;
// 		str = NULL;
// 		str = "I come from the child\n";

// 		ft_printf("\n-----------\n");
// 		ft_printf("i m the son ->print avant test\n");
// 		close(pid_fd[0]);

// 		len = ft_strlen(str);
// 		write(pid_fd[1], &len, sizeof(int));
// 		write(pid_fd[1], &str, sizeof(char) * len);
// 		close(pid_fd[1]);
// 	}
// 	if (pid != 0)
// 	{
// 		char *str;
// 		// char string[20];
// 		int		len;

// 		str = NULL;
// 		wait(NULL);
// 		ft_printf("\n-----------\n");		
// 		ft_printf("i m the father\n");
// 		close(pid_fd[1]);

// 		// dup2(pid_fd[0], STDIN_FILENO);
// 		dup2(file2, STDOUT_FILENO);

// 		read(pid_fd[0], &len, sizeof(int));
// 		read(pid_fd[0], &str, sizeof(char) * len);

// 				ft_printf("Father : %s", str);
// 		// close(pid_fd[0]);


// 		close(pid_fd[0]);

// 		close(file2);


// 	}

}