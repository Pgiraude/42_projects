#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int j;
    int len1;
    int len2;
    char *str;

	len1 = 0;
	while (s1[len1])
	{
		len1++;
	}

    len2 = 0;
	while (s2[len2])
	{
		len2++;
	}

    str = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!str)
        return (NULL);
    
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
    {
            str[i + j] = s2[j];
            j++;
    }
    str[i + j] = '\0';
    return (str);
}
/*
int main()
{
    char s1[] = "salut";
    char s2[] = " comment vas tu?";

    char *str;
    int i;

    str = ft_strjoin(s1, s2);

    printf(str);
    printf("\n");
}
*/