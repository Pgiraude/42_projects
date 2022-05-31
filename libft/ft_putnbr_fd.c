#include <unistd.h>

void    ft_putchar(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putnbr_fd(int n, int fd)
{
    long int N;

    N = n;
    if (N < 0)
    {
        N = N * -1;
        ft_putchar('-', fd);
    }

    if (N > 9)
    {
        ft_putnbr_fd((N / 10), fd);
    }
    ft_putchar(((N % 10) + 48), fd);

}

int main()
{
    ft_putnbr_fd(684561, 1);
}