/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:17:49 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/12 18:34:04 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"


int main(int argc, char **argv, char **env)
{
    char    *str;
    pid_t   pid;
    pid_t   pid2;
    int     i;
    

    pid = 1;
    i = 0;
    while (i++ < 2 && pid != 0)
    {
        pid = fork();
        if (pid == 0)
        {
            char **tmp;
            if (i == 1)
                tmp = ft_split("sleep 10", ' ');
            else
            {
                pid2 = fork();
                tmp = ft_split("sleep 1", ' ');
            }
            execve("/usr/bin/sleep", tmp, env);
        }
    }
    i = 0;
	while (wait(NULL) != -1)
	{
		// wait(NULL);
		ft_printf("waited for a child to finish\n");
	}
    
}
