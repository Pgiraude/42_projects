#include "../include/pipex.h"

void	exit_clean(t_data *data, int mode)
{
	if (data->options)
		ft_freestrings(data->options);
	if (data->path)
		free(data->path);
	if (data->file1 != -1)
		close(data->file1);
	if (data->file2 != -1)
		close(data->file2);
	if (data->pid)
		free(data->pid);
	if (mode == 0)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

void    error_manager(char *msg, t_data *data, int error_code)
{
	if (error_code == 1)
		ft_printf("Need a file to open: %s\n", strerror(errno));
	else if (error_code == 2)
		ft_printf("Cannot open %s: %s\n", msg, strerror(errno));
	else if (error_code == 3)
		ft_printf("Error : to %s arguments\n", msg);
	else if (error_code == 4)
		perror("Error, couldn't fork\n");
	else if (error_code == 5) //get command
	{
		ft_printf("Error : command n°%s is empty\n", msg);
		free (msg);
		exit_clean(data, 1);
	}
	else if (error_code == 6)
		ft_printf("Command %s not found : %s\n", msg, strerror(errno));
	else if (error_code == 7)
		ft_printf("Error : couldn't found a PATH\n");
	else if (error_code == 8) //child
		exit_clean(data, 1);
	else if (error_code == 9)
	{
		ft_printf("Error : execv failed %s\n", strerror(errno));
		exit_clean(data, 1);
	}
}