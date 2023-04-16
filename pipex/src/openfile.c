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
			ft_printf("Need a file to open: %s\n", strerror(errno));
		else if (argv[1])
			ft_printf("Cannot open %s: %s\n", argv[1], strerror(errno));
		return (2);
	}
	data->file2 = open(argv[argc - 1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (data->file2 < 0)
	{
		close(data->file1);
		if (argv[argc - 1][0] == '\0')
			ft_printf("Need a file to open: %s\n", strerror(errno));
		else if (argv[argc - 1])
			ft_printf("Cannot open %s: %s\n", argv[argc - 1], strerror(errno));
		return (3);
	}
	return (0);
}

int	open_file(int argc, char **argv, t_data *data)
{
	if (argc > 5)
	{
		ft_printf("Error : to much arguments\n");
		return (3);
	}
	no_heredoc(argc, argv, data);
	return (0);
}
