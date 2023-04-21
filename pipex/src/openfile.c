/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:17:33 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/14 13:47:07 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	no_heredoc(int argc, char **argv, t_data *data)
{
	data->file1 = open(argv[1], O_RDONLY);
	if (data->file1 < 0)
	{
		if (argv[1][0] == '\0')
			error_manager(NULL, 1);
		else if (argv[1])
			error_manager(argv[1], 2);
			
		return (2);
	}
	data->file2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (data->file2 < 0)
	{
		close(data->file1);
		if (argv[argc - 1][0] == '\0')
			error_manager(NULL, 1);
		else if (argv[argc - 1])
			error_manager(argv[argc - 1], 2);
		return (3);
	}
	return (0);
}

int	open_file(int argc, char **argv, t_data *data)
{
	if (argc > 5)
	{
		error_manager("much", 3);
		return (1);
	}
	else if (argc < 5)
	{
		error_manager("few", 3);
		return (2);
	}
	no_heredoc(argc, argv, data);
	return (0);
}
