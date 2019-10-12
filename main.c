#include <stdio.h>

int main ()
{
	int i = 15;
	char s[] = "Hello world !";
	char s2[] = "How are you doing ?";
	printf("%030s %s\n", s, s2);
	printf("%*i\n", 50, i);
	printf("\n");
}
