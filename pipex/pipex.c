/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:15:06 by pgiraude          #+#    #+#             */
/*   Updated: 2023/03/21 16:58:59 by pgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int argc, char **argv, char **envp)
{
	int	i;
	pid_t	pid;

	// if (argc < 5)
	// {
	// 	ft_printf("Not enough argument\n");
	// 	return (1); 
	// }
	
	i = 0;
	while (envp[i])
	{
		// ft_printf("variable d'environnement =%s\n", envp[i]);
		i++;
	}
	pid = fork();

	if (pid == 0)
	{
		ft_printf("i m the son PID =%d\n", pid);
	}
	if (pid != 0)
	{
		ft_printf("i m the father PID =%d\n", pid);
	}
}