#include "main.h"

int main()
{
	char *c = "almost there";
	char b = 'A';
	int a, d;
	int len = 0;

	a = _printf("first %c %s %d try without specifiers or flags\n", b, c, len);
	printf("%d %d (this is the number of characters printed)\n", a);
	_printf("%d\n", a);
	return (0);
}
