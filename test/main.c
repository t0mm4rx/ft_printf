#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main ()
{
	printf("%0*.*X|\n", -3, -9, 0);
	ft_printf("%0*.*X|\n", -3, -9, 0);

	printf("F%0*.*x%-i%*X\n", -5, -9, 0, -2147483647, 8, 0);
	ft_printf("F%0*.*x%-i%*X\n", -5, -9, 0, -2147483647, 8, 0);
}
