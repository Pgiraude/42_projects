#include "pipex.h"

int main(int argc, char **argv, char **env)
{
    char *option[3] = {"ls", "-l", NULL};
    execve("/usr/bin/ls", option, env);
    return (0);
}