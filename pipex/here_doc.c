
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
		else if (ft_strchr(new_line, limiter) && ft_strlen(limiter) == ft_strlen(new_line - 1))
		{
			return (free(new_line), line);
		}
		else
			line = ft_strjoin(line, new_line);
	}
}

void	heredoc(int argc, char **argv, t_data *data)
{
	char	*line;
	if (check_arguments(argc, argv, 5) != 0)
		return (1);
	data->file1 = open(".heredoc" O_CREAT | O_WRONLY | O_TRUNC, 0644);
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
	

	data->file2 = open(argv[argc - 1], O_APPEND | O_CREAT | O_WRONLY, 0644);
	if (data->file2 < 0)
	{
		close(data->file1);
		ft_printf("Error : cannot open %s\n", argv[argc - 1]);
		return (3);
	}
	return (0);
}