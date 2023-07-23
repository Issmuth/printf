#include "main.h"

int main()
{
	char *c = "we will";
	char b = 'a';
	int a, d;

	a = _printf("first %c try without %s specifiers or flags\n", b, c);
	printf("%d %d (this is the number of characters printed)\n", a);
	return (0);
}
