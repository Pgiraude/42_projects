/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:17:25 by pgiraude          #+#    #+#             */
/*   Updated: 2023/07/20 12:25:23 by pgiraude         ###   ########.fr       */
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

	data->file1 = open(".heredoc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->file1 < 0)
		error_manager(".heredoc", NULL, 2);
	else
	{
		line = gnl_heredoc(argv[2]);
		if (line == NULL)
			ft_putstr_fd("", data->file1);
		else
			ft_putstr_fd(line, data->file1);
		free (line);
		close (data->file1);
		data->file1 = open(".heredoc", O_RDONLY, 0644);
	}
	data->file2 = open(argv[argc - 1], O_APPEND | O_CREAT | O_WRONLY, 0644);
	if (data->file2 < 0)
	{
		if (argv[argc - 1][0] == '\0')
			error_manager(NULL, NULL, 1);
		else if (argv[argc - 1])
			error_manager(argv[argc - 1], NULL, 2);
	}
	return (0);
}

int	no_heredoc(int argc, char **argv, t_data *data)
{
	data->file1 = open(argv[1], O_RDONLY);
	if (data->file1 < 0)
	{
		if (argv[1][0] == '\0')
			error_manager(NULL, NULL, 1);
		else if (argv[1])
			error_manager(argv[1], NULL, 2);
	}
	data->file2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (data->file2 < 0)
	{
		if (argv[argc - 1][0] == '\0')
			error_manager(NULL, NULL, 1);
		else if (argv[argc - 1])
			error_manager(argv[argc - 1], NULL, 2);
	}
	return (0);
}

int	open_file(int argc, char **argv, int *first_cmd, t_data *data)
{
	if (is_here_doc(argv))
	{
		if (argc < 5)
		{
			error_manager("few", NULL, 3);
			return (1);
		}
		heredoc(argc, argv, data);
		data->index_cmd = argc - 4 - 1;
		*first_cmd = 3;
	}
	else
	{
		if (argc < 4)
		{
			error_manager("few", NULL, 3);
			return (2);
		}
		no_heredoc(argc, argv, data);
		data->index_cmd = argc - 3 - 1;
		*first_cmd = 2;
	}
	return (0);
}
