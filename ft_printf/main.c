#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	size_t len;

	len = ft_printf("%p", "ok");
	printf("\n%p len = %ld", "ok", len);
    printf("\n");
	len = ft_printf("%p", INT_MIN);
	printf("\n%p len = %ld", INT_MIN, len);
    printf("\n");
	len = ft_printf("%p", INT_MAX);
	printf("\n%p len = %ld", INT_MAX, len);
// reproduit le f(x) de printf

    printf("\n\n");
	len = ft_printf("%u", -1);
	printf("\n%u len = %ld", -1, len);
    printf("\n");
	len = ft_printf("%u", "coucou");
	printf("\n%u len = %ld", "coucou", len);
    printf("\n");
	len = ft_printf("%u", INT_MIN);
	printf("\n%u len = %ld", INT_MIN, len);
// reproduit le f(x) de printf meme si chelou

    printf("\n\n");
	len = ft_printf("%x", -12);
	printf("\n%x len = %ld", -12, len);
    printf("\n");
	len = ft_printf("%x", "coucou");
	printf("\n%x len = %ld", "coucou", len);
    printf("\n");
	len = ft_printf("%x", INT_MIN);
	printf("\n%x len = %ld", INT_MIN, len);
// reproduit le f(x) de printf meme si chelou


}
