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
		perror("TEST cannot open file");
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
		return (1);
	if (argc > 5)
	{
		ft_printf("Error : to much arguments\n");
		return (3);
	}
	no_heredoc(argc, argv, data);
	if (get_command(2, argv + 2, envp, data) != 0)
	{
		return (2);
	}
	return (0);
}
