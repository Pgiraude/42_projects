#include "pipex.h"

void    child(int *i)
{
    pid_t   pid;

    pid = fork();
    while (*i++ < 2)
    {
        if (pid == 0)
        {
            printf("i m the son of the son i = %d\n", *i);
            pid = fork();
        }
        else if (pid > 0)
        {
            wait (NULL);
            printf("i m the son i = %d\n", *i);
        }
    }
}

int main(int argc, char **argv, char **env)
{
    pid_t   pid;
    int     i;
    
    i = 0;

    pid = fork();

    if (pid == 0)
        child(&i);
    if (pid > 0)
    {
        wait (NULL);
        printf("i m the father\n");
    }
}