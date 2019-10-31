#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main ()
{

	int nb = 10;
	int size = -89;
	int width = 0;

	int flags[2] = {0, 0};
	int a = printf("%*.*d", width, size, nb);
	printf("|\n");
	int b = putnbr(nb, width, size, flags);
	printf("|\n");
	printf("%d / %d\n", a, b);
}
