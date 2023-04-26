/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:17:33 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/26 18:04:54 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

int	open_file(int argc, char **argv, t_data *data)
{
	int	error;

	if (argc > 5)
	{
		error_manager("much", NULL, 3);
		return (1);
	}
	else if (argc < 5)
	{
		error_manager("few", NULL, 3);
		return (2);
	}
	
	no_heredoc(argc, argv, data);
	return (0);
}
