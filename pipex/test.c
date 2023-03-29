#include "pipex.h"

void    child(int cmd, pid_t pid)
{
    int val;

    val = 1;
    while (cmd > 0  || val == 1)
    {
        val = 0;
        if (pid == 0)
        {
            printf("i m the son of the son i = %d\n", cmd);
            if (cmd > 0)
            {
                pid = fork();
                cmd--;
            }
        }
        if (pid > 0 )
        {
            wait (NULL);
            printf("i m the son i = %d\n", cmd);
            break ;
        }
    }
}

int *inter(void)
{
    int *fd;

    fd = malloc(sizeof(int) * (2 + 1));

    fd[2] = '\0';
    return (fd);
}

int main(int argc, char **argv, char **env)
{
    pid_t   pid;
    int     cmd;
    int     test;

    cmd = 2;

    test = fork();
    cmd -= 2;
    if (pid == 0)
        child(cmd, test);
    if (test > 0)
    {
        wait (NULL);
        printf("i m the father\n");
    }

    int     **big_fd;
    cmd = 3;
    big_fd = malloc(sizeof(int*) * (cmd + 1));

    int i = 0;
    while (i < cmd)
    {
        big_fd[i] = inter();
        big_fd[i][0] = i;
        big_fd[i][1] = -i;
        i++;
    }
    big_fd[i] = NULL;

    i = 0;
    while (big_fd[1][i])
    {
        printf("test %d\n", big_fd[1][i]);
        i++;
    }
}