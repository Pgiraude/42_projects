#include <stdio.h>
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *ptr;
    int i;

    i = 0;
    while(s[start + i] && i < len)
    {
        i++;
    }

    ptr = malloc(sizeof(char) * (i + 1));
    if (!ptr)
        return (NULL);

    i = 0;
    while (s[start + i] && i < len)
    {
        ptr[i] = s[start + i];
        i++;
    }
    ptr [i] = '\0';
    return (ptr);
}

int main()
{
    char s[] = "salutc";
    char *ptr;
    int i;

    ptr = ft_substr(s, 4, 3);

    i = 0;
    while (ptr[i])
    {
        printf("%i\n", ptr[i]);
        i++;
    }

}