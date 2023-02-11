#include "get_next_line.h"

int main(void)
{
    int fd;
    char *result;


    int     i;
    
    fd = open("TEST.txt", O_RDONLY);
    i = 1;
    result = get_next_line(fd);
    if (!result)
        printf("NULL\n");
    while (result)
    {
        printf("1N°%d =%s", (i), result);
        free(result);
        result = get_next_line(fd);
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

// bonus
    // int	main(void)
// {
//     int fd;
    // int	fd2;
//     char *result;
//     int     i;

//     fd = open("TEST.txt", O_RDONLY);
//     fd2 = open("TEST2.txt", O_RDONLY);
//     i = 1;
//     while (i <= 1)
//     {
//         result = get_next_line(fd);
//         printf("1N°%d =%s", (i), result);
//         free(result);
//         i++;
//     }


//     // i = 1;
//     // while (i <= 1)
//     // {
//     //     result = get_next_line(fd2);
//     //     printf("2N°%d =%s", (i), result);
//     //     free(result);
//     //     i++;
//     // }

//     // i = 1;
//     // while (i <= 1)
//     // {
//     //     result = get_next_line(fd);
//     //     printf("1N°%d =%s", (i), result);
//     //     free(result);
//     //     i++;
//     // }

//     // i = 1;
//     // while (i <= 1)
//     // {
//     //     result = get_next_line(fd2);
//     //     printf("2N°%d =%s", (i), result);
//     //     free(result);
//     //     i++;
//     // }
// }