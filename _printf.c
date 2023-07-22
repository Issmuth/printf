#include "main.h"

/**
 * _printf - printf replica
 * @format: string to be printed
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int len;

	len = _strlen(format);
	write(1, format, len));
	return(len);
}
