#include "printf.h"
#include "libft.h"
#include <stdio.h>

int main ()
{
	//int a = 3;
	//int a = ft_printf("Nb1: |%10.2d|, Nb2: |%-5.5d|, hex: |%x|, HEX: |%10.20X|, Str: |%10.2s|, char: |%3c|, ptr: |%20p|, %%\n", 1, 2, 542, 542, "Tom", 'c', &a);
	//int b = printf("Nb1: |%10.2d|, Nb2: |%-5.5d|, hex: |%x|, HEX: |%10.20X|, Str: |%10.2s|, char: |%3c|, ptr: |%20p|, %%\n", 1, 2, 542, 542, "Tom", 'c', &a);

	//ft_printf("printf: %*.*s\n", 10, 10, "Hello World!");
	//printf("printf: %*.*s\n", 10, 10, "Hello World!");

	//int a = ft_printf("%-10.5%\n");
	//int b = printf("%-10.5%\n");

	//int a = ft_printf("%-10.*s\n", 20, "Hello World");
	//int b = printf("%-10.*s\n", 20, "Hello World");

	//printf("%d, %d\n", a, b);

	//ft_printf("%10s\n", NULL);
	//printf("%10s\n", NULL);

	//ft_printf("|%x| |%X|\n", 0, 0);
	//printf("|%d| |%X|\n", 0, 0);

	//ft_printf("%x  %x\n", -5, -2147483647);
	//printf("%x  %x\n", -5, -2147483647);

	ft_printf("%09i\n", 0);
	printf("%09i\n", 0);

	ft_printf("%020i\n", -2147483647);
	printf("%020i\n", -2147483647);

	ft_printf("%-6.4d\n", 1);
	printf("%-6.4d\n", 1);
}
