
#include "pipex.h"

char	*gnl_heredoc(char *limiter)
{
	char    *line;
	char    *new_line;

	new_line = NULL;
	line = NULL;
	while (1)
	{
		ft_printf("> ");
		new_line = get_next_line(STDIN_FILENO);
		if (new_line == NULL)
		{
			ft_printf("warning: here-document delimited by end-of-file (wanted `%s')\n", limiter);
			return (line);
		}
		else if (ft_strnstr(new_line, limiter, ft_strlen(limiter)) \
			&& ft_strlen(limiter) == (ft_strlen(new_line) - 1))
			return (free(new_line), line);
		else
			line = ft_strjoin(line, new_line);
	}
}

int	heredoc(int argc, char **argv, t_data *data)
{
	char	*line;

	data->file1 = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->file1 < 0)
	{
		ft_printf("Error : cannot create .heredoc\n");
		return (2);
	}
	line = gnl_heredoc(argv[2]);
	if (line == NULL)
		ft_putstr_fd("", data->file1);
	else
	{
		ft_putstr_fd(line, data->file1);
		free (line);
	}
	close (data->file1);
	data->file1 = open(".heredoc", O_RDONLY);
	data->file2 = open(argv[argc - 1], O_APPEND | O_CREAT | O_WRONLY, 0644);
	if (data->file2 < 0)
	{
		close(data->file1);
		ft_printf("Error : cannot open %s\n", argv[argc - 1]);
		return (3);
	}
	return (0);
}

int	no_heredoc(int argc, char **argv, t_data *data)
{
	data->file1 = open(argv[1], O_RDONLY);
	if (data->file1 < 0)
	{
		ft_printf("Error : cannot open %s\n", argv[1]);
		return (2);
	}
	data->file2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (data->file2 < 0)
	{
		close(data->file1);
		ft_printf("Error : cannot open %s\n", argv[argc - 1]);
		return (3);
	}
	return (0);
}

int	open_file(int argc, char **argv, char **envp, t_data *data)
{
	if (check_arguments(argc, argv, 4) != 0)
		return (3);
	if (ft_strnstr(argv[1], "here_doc", 8) && ft_strlen(argv[1]) == 8)
	{
		if (check_arguments(argc, argv, 5) != 0)
			return (1);
		if (heredoc(argc, argv, data) != 0)
			return (2);
		if (get_command((argc - 4), argv + 3, envp, data) != 0)
			return (3);
	}
	else
	{
		if (no_heredoc(argc, argv, data) != 0)
			return (4);
		if (get_command((argc - 3), argv + 2, envp, data) != 0)
			return (5);
	}
	return (0);
}