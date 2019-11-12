#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main ()
{
	printf("%04.*d\n", 10, -446208263);
	ft_printf("%04.*d", 10, -446208263);
}
