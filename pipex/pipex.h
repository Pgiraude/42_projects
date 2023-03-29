/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:13 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/21 16:49:44 by pgiraude         ###   ########.fr       */
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
    char    ***options;
    char    **paths;
    int     **tab_fd;
    int     nbr_cmd;
}t_data;

#endif