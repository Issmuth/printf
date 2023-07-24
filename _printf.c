#include "main.h"

/**
 * _printf - printf replica
 * @format: string to be printed
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, printed = 0;
	va_list ap;

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			printed++;
		} else
		{
			i++;
			printed--;
			printed +=  print_arg(format, ap, &i);
		}
	}
	va_end(ap);
	return (printed);
}
