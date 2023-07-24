#include "main.h"
/**
 * print_arg - prints the argument passed
 * based on the specifier
 * @list: list of arguments
 * @s: ...
 *
 * Return: number of character printed
 * according to the argument
 */

int print_arg(const char *frmt, va_list list, int *j)
{
	int i = 0, printed;
	struct format _format[] = {
		{'c', print_char},
		{'s', print_string},
		{'\0', NULL}
	};

	for (i = 0; _format[i].fmt != '\0'; i++)
	{
		if (frmt[*j] == _format[i].fmt)
		{
			printed = _format[i].func(list);
			return (printed);
		}
	}
}

/**
 * print_char - prints a character
 * @list: list of arguments
 *
 * Returns: 1 if printed successfully -1 if fails
 */
int print_char(va_list list)
{
	char c;

	c = va_arg(list, int);
	return (write(1, &c, 1));
}

/**
 * print_string - prints string
 * @list: list of arguments
 *
 * Return: number of characters printed
 */

int print_string(va_list list)
{
	int len;
	char *str;

	str = va_arg(list, char *);
	len = _strlen(str);
	write(1, str, len);
	return (len);
}
