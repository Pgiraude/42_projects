#include <stdio.h>
#include <stdlib.h>


int ft_len(char const *x, char c, int i)
{
    int len;

    len = 0;
    while (x[i] && x[i] != c)
    {
        len++;
        i++;
    }
    return (len);
}

char ft_1st(char const *x, int i, int pos)
{
    char *str;
    int j;

    str = malloc(sizeof(char) * (i - pos + 1));

    j = 0;
    while (pos < i)
    {
        str[j] = x[pos];
        j++;
        pos++;
    }
    str[j] = '\0';
    return (str);
}



char **ft_split(char const *x, char c)
{
    int i;
    int pos;

    pos = 0;
    i = 0;
    while (x[i] == c)
    {
        i++;
    }
    while (x[i])
    {
        if (x[i] == c)
        {
            ft_1st(x, i, pos)
            while(x[i] == c)
            {
                i++;
            }
            pos = i;
        }
        else
        {
            i++;
        }
    }
}


int ft_nb_split(char const *x, char c)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (x[i] == c)
        i++;
    while (x[i])
    {
        if (x[i] == c)
        {
            count++;
            while(x[i] == c)
            {
                i++;
            }
        }
        else
        {
            i++;
            if (x[i] == '\0')
                count++;
        }
    }
    return (count);
}

int main()
{
    char s[] = "A+B+C";
    char c = '+';

    int x;

    x = ft_nb_split(s, c);
    printf("%d", x);
}