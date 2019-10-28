#include "printf.h"
#include <stdio.h>

int main ()
{
	int a = printf("%-1.0c", 'A');
	printf("| %d\n", a);

	int flags[2] = {1, 0};
	int b = putchar2('A', 1, 0, flags);
	printf("| %d\n", b);
}
