/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:17:25 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/11 18:39:14 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_strjoin_pipex(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(tmp, s2);
	free (tmp);
	free (s2);
	return (s1);
}

char	*gnl_heredoc(char *limiter)
{
	char	*line;
	char	*new_line;
	char	*tmp;

	new_line = NULL;
	line = NULL;
	while (1)
	{
		ft_printf("> ");
		new_line = get_next_line(STDIN_FILENO);
		if (new_line == NULL)
		{
			ft_printf("\nwarning: here-document delimited by end-of-file ");
			ft_printf("(wanted '%s')\n", limiter);
			return (line);
		}
		else if (ft_strnstr(new_line, limiter, ft_strlen(limiter)) \
			&& ft_strlen(limiter) == (ft_strlen(new_line) - 1))
			return (free(new_line), line);
		else
			line = ft_strjoin_pipex(line, new_line);
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
		ft_putstr_fd(line, data->file1);
	close (data->file1);
	data->file1 = open(".heredoc", O_RDONLY, 0644);
	data->file2 = open(argv[argc - 1], O_APPEND | O_CREAT | O_WRONLY, 0644);
	if (data->file2 < 0)
	{
		close(data->file1);
		ft_printf("Error : cannot open %s\n", argv[argc - 1]);
		return (free (line), 3);
	}
	return (free (line), 0);
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

int	open_file(int argc, char **argv, t_data *data)
{
	if (is_here_doc(argv))
	{
		if (argc < 5)
		{
			ft_printf("Error heredoc : to few arguments\n");
			return (1);
		}
		if (heredoc(argc, argv, data) != 0)
			return (2);
	}
	else
	{
		if (argc < 4)
		{
			ft_printf("Error no heredoc : to few arguments\n");
			return (1);
		}
		if (no_heredoc(argc, argv, data) != 0)
			return (4);
	}
	return (0);
}