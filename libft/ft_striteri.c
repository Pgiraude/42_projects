
#include <stdio.h>
#include <stdlib.h>

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int i;

    i = 0;
    while (s[i])
    {
        s[i] = (*f)(i, s);
        i++;
    }
}

void   *test(unsigned int i, char *c)
{
    return(99);

}

int main()
{
    char s[] = "salut ca va?";
    char *x;

    ft_striteri(s, (test));

    printf(s);

}