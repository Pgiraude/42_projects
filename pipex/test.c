#include "pipex.h"


int main(int argc, char **argv, char **env)
{
    char *str;

    str = ft_strjoin(argv[1], argv[2]);

    printf("[%s]\n", str);

}