#include "main.h"

/**
 * _printf - printf replica
 * @format: string to be printed
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int len, i, j = 0;
	char specifier;
	va_list ap;
	
	if (format == NULL)
		return (-1);

	va_start(ap, format);
	len = _strlen(format);
	for (i = 0; i < len; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			j++;
		} else
		{	
			specifier = format[i + 1];
			j--;
			j += print_arg(ap, specifier);
			i++;
		}
	}
	return(j);
}
