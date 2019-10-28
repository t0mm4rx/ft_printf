#include "printf.h"
#include <stdio.h>

int main ()
{
	int a = printf("%-10c", 'c');
	printf("\n");
	int flags[2] = {1, 0};
	int b = putchar2('c', 10, 0, flags);
	printf("\n%d\n%d", a, b);

}
