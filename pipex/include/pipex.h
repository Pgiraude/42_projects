/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:13 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/13 16:49:50 by pgiraude         ###   ########.fr       */
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

typedef enum e_pipe
{
    READ,
    WRITE
}t_pipe;

typedef struct e_data
{
    int     file1;
    int     file2;
    char    **options;
    char    *paths;
    int     **tab_fd;
    int     index_cmd;
}t_data;

int	    open_file(int argc, char **argv, char **envp, t_data *data);
int	    get_command(int argc, char **argv, char **envp, t_data *data);
int	    prepare_pipe(t_data *data);
void	exit_clean(char **argv, t_data *data);
int     check_arguments(int argc, char **argv, int min_arg);

#endif