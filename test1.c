#include "main.h"

int main()
{
	char *c = "almost there";
	char b = 'A';
	int a;
	int len = 0;

	a = _printf("first %c %s %d try without specifiers or flags\n", b, c, len);
	_printf("%d (this is the number of characters printed)\n", a);
	_printf("%d\n", a);
	return (0);
}
