#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main ()
{

	int nb = -50;
	int size = 5;
	int width = 100;

	int flags[2] = {0, 0};
	int a = printf("%*.*u", width, size, nb);
	printf("|\n");
	int b = putunbr(nb, width, size, flags);
	printf("|\n");
	printf("%d / %d\n", a, b);
}
