#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main ()
{
	printf("%0*.*X|\n", -3, -9, 0);
	ft_printf("%0*.*X|\n", -3, -9, 0);
}
