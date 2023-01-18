#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;
    char *result;

    fd = open("TEST.txt", O_RDONLY);
    result = get_next_line(fd);
    printf("Y%sY", result);
    free(result);

    result = get_next_line(fd);
    printf("X%sX", result);
    free(result);
}