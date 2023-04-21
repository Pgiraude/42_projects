#include "../include/pipex.h"

void    error_manager(char *msg, int error_code)
{
    if (msg)
        ft_printf("%s", msg);
    if (error_code == 1)
        ft_printf("Need a file to open: %s\n", strerror(errno));
    else if (error_code == 2)
        ft_printf("Cannot open %s: %s\n", msg, strerror(errno));
    else if (error_code == 3)
        ft_printf("Error : to %s arguments\n", msg);
    else if (error_code == 4)
        

}