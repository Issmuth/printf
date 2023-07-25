#include "main.h"

int main()
{
	char *c = "almost there";
	char b = 'A';
	int a;
	int len = 0;
	int k = 40;

	a = _printf("first %c %s %d %i try without specifiers or flags\n", b, c, len, k);
	printf("%d(this is the number of characters printed)\n", a);
	return (0);
}
