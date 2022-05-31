#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    while(s[i])
    {
        ft_putchar(s[i], fd);
        i++;
    }
}

int main()
{
    char s[] = "salut mec ;)";

    ft_putstr_fd(s, 1);
}