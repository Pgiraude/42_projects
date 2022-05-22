#include <stdio.h>
#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int len;
    char *ptr;

    len = 0;
    while (s[len])
    {
        len++;
    }

    ptr = malloc(sizeof(char) * (len + 1));
    if (!ptr)
        return (NULL);

    int i;

    i = 0;
    while (s[i])
    {
        ptr[i] = s[i];
        i++;
    }
    ptr[i] = '\0';

    i = 0;
    while (ptr[i])
    {
        ptr[i] = (*f)(i, ptr[i]);
        i++;
    }
    return (ptr);
}

char test(unsigned int i, char c)
{
    if (i > 4)
        c = '*';

    return(c);
}

int main()
{
    char str[] = "sale petit con";

    char *s;
    int i;
    char c;

    s = ft_strmapi(str, (test));

    printf("%s\n", s);
}