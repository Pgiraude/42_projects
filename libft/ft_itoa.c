#include <stdio.h>
#include <stdlib.h>

int ft_len(int n)
{
    int len;

    len = 0;
    if (n < 10)
    {
        len = 1;
    }
    else
    {
        len = 1;
        while (n >= 10)
        {
            n = n / 10;
            len++;
        }
    }
    return (len);
}

char *ft_convert(int n, int sign)
{
    char *str;
    int len;

    len = ft_len(n) + sign;
    str = malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);

    str[len] = '\0';
    len--;
    while (len >= 0)
    {
        str[len] = (n % 10) + 48;
        n = n / 10;
        len--;
    }
    if (sign > 0)
    {
        str[0] = '-';
    }
    return(str);
}

char *ft_itoa(int n)
{
    int sign;
    char *str;

    sign = 0;
    if (n < 0)
    {
        sign = 1;
        n = n * -1;
    }
    str = ft_convert(n, sign);
    return(str);
}

int main()
{
    int n = -10;

    char *x;

    x = ft_itoa(n);
    printf("%s\n", x);
}