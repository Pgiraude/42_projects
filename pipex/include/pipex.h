/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:13 by pgiraude          #+#    #+#             */
/*   Updated: 2023/05/01 18:57:08 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

typedef enum e_pipe
{
	READ,
	WRITE
}t_pipe;

typedef struct e_data
{
	int		file1;
	int		file2;
	char	**env;
	char	**options;
	char	*path;
	pid_t	*pid;
	int		index_cmd;
}t_data;

int		open_file(int argc, char **argv, int *first_cmd, t_data *data);
int		get_command(char *cmd, char **envp, t_data *data, int index);

void	exit_clean(t_data *data, int mode);
int		check_arguments(int argc, char **argv, int min_arg);
int		is_here_doc(char **argv);
void	wait_all_child(t_data *data);
void	error_manager(char *msg, t_data *data, int error_code);

#endif