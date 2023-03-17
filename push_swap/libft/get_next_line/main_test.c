#include "get_next_line.h"

int main(void)
{
    int fd;
    char *result;
    
    fd = 0;
    result = get_next_line(fd);
    if (!result)
        printf("NULL\n");
    while (result)
    {
        printf("=%s", result);
        free(result);
        result = get_next_line(fd);
    }
}
