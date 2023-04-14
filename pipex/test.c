/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:17:49 by pgiraude          #+#    #+#             */
/*   Updated: 2023/04/14 12:42:45 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include <string.h>


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
            {
                tmp = ft_split("sleep 1", ' ');
                perror("test perror fils 1");
            }
            else
            {
               tmp = ft_split("sleep 2", ' ');
               perror("test perror fils 2");
            }
            execve("/usr/bin/sleep", tmp, env);
        }
    }
    ft_printf("1=%d\n", errno);
    perror("test perror pour 1");
    i = 0;
	while (wait(NULL) != -1)
	{
		// wait(NULL);
		ft_printf("waited for a child to finish\n");
	}
    ft_printf("2=%d\n", errno);
    perror("test perror pour 2");
    ft_printf("3=%d\n", errno);
    // ft_printf("%s", strerror(errno));
    char *test = strerror(errno);
    ft_printf("test strerror : %s", test);
}
