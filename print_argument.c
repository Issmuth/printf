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

int print_arg(va_list list, char s)
{
	
	if (s == 'c')
		return (print_char(list));

	if (s == 's')
		return (print_string(list));
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
	return(write(1, &c, 1));
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

	len = _strlen(va_arg(list, char *));
	str = malloc( sizeof(char) * len);
	str = va_arg(list, char *);
	write(1, str, len);
	return (len);
}
