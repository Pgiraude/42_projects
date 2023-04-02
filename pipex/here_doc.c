
#include "pipex.h"

char	*gnl_heredoc(char *limiter)
{
	int		fd_heredoc;
	char    *line;
	char    *new_line;

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

void	heredoc(int argc, char **argv)
{
	char	*line;

	if (!(argv[1] == "here_doc") || argc < 6)
		return ;
	fd_heredoc = open(".heredoc" O_CREAT | O_WRONLY | O_TRUNC, 0644);
	line = gnl_heredoc(argv[2]);
	ft_putstr_fd(line, fd_heredoc);
}