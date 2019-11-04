#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main ()
{

	int nb = 10;
	//int size = 10;
	int width = 10;

	int flags[2] = {0, 0};
	int a = printf("%*p", width, &nb);
	printf("|\n");
	int b = putptr(&nb, width, 0, flags);
	printf("|\n");
	printf("%d / %d\n", a, b);
}
