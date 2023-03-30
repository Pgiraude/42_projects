/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:13 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/30 16:47:24 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/include/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef enum e_pipe
{
    READ,
    WRITE
}t_pipe;

typedef struct e_data
{
    int     file1;
    int     file2;
    char    ***options;
    char    **paths;
    int     **tab_fd;
    int     nbr_cmd;
}t_data;

int	    open_file(int argc, char **argv, t_data *data);
int	    get_command(int argc, char **argv, char **envp, t_data *data);
int	    prepare_pipe(t_data *data);
void	free_all(t_data *data);

#endif