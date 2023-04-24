#include "../include/pipex.h"

void    error_manager(char *msg, int error_code)
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
		ft_printf("Error : command n°%s is empty\n", msg);
	else if (error_code == 6)
		ft_printf("Command %s not found : %s\n", msg, strerror(errno));
	else if (error_code == 7)
		ft_printf("Error : couldn't found a PATH\n");
	else if (error_code == 8) //child
		perror("Can't execut process");


}