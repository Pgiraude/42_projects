#include "get_next_line.h"

int main(void)
{
    int fd;
    char *result;
    int     i;

    fd = open("TEST.txt", O_RDONLY);
    i = 0;
    while (i < 8)
    {
        result = get_next_line(fd);
        printf("N°%d =%s", (i + 1), result);
        free(result);
        i++;
    }
}