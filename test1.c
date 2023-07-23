#include "main.h"

int main()
{
	char *c = "we will";
	int a;

	a = _printf("first %s try without specifiers or flags\n", c);
	printf("%d (this is the number of characters printed)\n", a);
	return (0);
}
