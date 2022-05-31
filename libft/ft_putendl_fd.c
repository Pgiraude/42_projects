#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putendl_fd(char *s, int fd)
{
        int i;

    i = 0;
    while(s[i])
    {
        ft_putchar(s[i], fd);
        i++;
    }
    ft_putchar('\n', fd);
}

int main()
{
    char s[] = "salut mec ;) patate";

    ft_putendl_fd(s, 1);
}