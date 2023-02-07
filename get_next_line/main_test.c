#include "get_next_line.h"

int main(void)
{
    int fd;
    char *result;


    int     i;

    fd = open("TEST2.txt", O_RDONLY);
    i = 1;
    while (i <= 3)
    {
        result = get_next_line(fd);
        printf("1N°%d =%s", (i), result);
        free(result);
        i++;
    }

    // fd = open("TEST.txt", O_RDONLY);
    // result = get_next_line(fd);
    // while (result)
    // {
    //     if (result)
    //         printf("%s", result);
    //     free(result);
    //     result = get_next_line(fd);
    // }
}