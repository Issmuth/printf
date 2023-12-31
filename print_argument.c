#include "main.h"

/**
 * print_char - prints a character
 * @list: list of arguments
 *
 * Return: Always 1 if printed (successfully) -1 if fails
 */

int print_char(va_list list)
{
	char c;

	c = va_arg(list, int);
	if (c == '\0')
		return (0);

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
	char *str = va_arg(list, char*);
	int i, len;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		write(1, &str[i], 1);
	}
	len = _strlen(str);

	return (len);
}

/**
 * print_digits - prints out the digits passed
 * @list: list of all the arguments
 *
 * Return: number of digits to be printed
 */
int print_digits(va_list list)
{
	int num = va_arg(list, int);
	int pos = 0;
	int is_negative = 0;
	int count = 0;
	char *buffer;


	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	buffer = malloc(num * sizeof(char));
	if (buffer == NULL)
	{
		printf("Memory allocation failed");
		return (-1);
	}

	do {
		buffer[pos++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
	{
		buffer[pos++] = '-';
	}
	while (pos > 0)
	{
		pos--;
		write(1, &buffer[pos], 1);
		count++;
	}
	free(buffer);
	return (count);
}

/**
 * print_integers - prints only intergers alone
 * @list: list of arguments passed
 * Return: a number to be printed
 */
int print_integers(va_list list)
{
	int num = va_arg(list, int);
	int j = 0;
	int b;
	char *buffer;

	if (num < 0)
		b = num * -1;

	buffer = malloc(b * sizeof(char));

	if (buffer == NULL)
	{
		printf("Memory allocation failed");
		return (-1);
	}

	print_int_str(num, buffer);
	j = write(1, buffer, _strlen(buffer));
	free(buffer);
	return (j);
}

/**
 * print_arg - prints the argument passed
 * based on the specifier
 * @list: list of arguments
 * @s: specifier
 *
 * Return: number of character printed
 * according to the argument
 */

int print_arg(va_list list, char s)
{
	int count, i, j = 0;
	formfunc spec[] = {
		{'c', print_char}, {'s', print_string},
		{'d', print_digits}, {'i', print_integers},
		{'\0', NULL}
	};

	for (i = 0; spec[i].format != '\0'; i++)
	{
		if (spec[i].format == s)
		{
			count = spec[i].func(list);
			j++;
			return (count);
		}
	}
	if (j == 0)
	{
		write(1, "%", 1);
		write(1, &s, 1);
		return (2);
	}
	return (0);
}
