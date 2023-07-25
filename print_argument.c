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
	char buffer[20];
	/* Assuming the largest int can be represented in 19 characters*/
	int pos = 0, is_negative = 0, count = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
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
		putchar(buffer[pos]);
		count++;
	}
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
	switch (s)
	{
		case 'c':
		{
			print_char(list);
			break;
		}
		case 's':
		{
			print_string(list);
			break;
		}
		case 'd':
		{
			print_digits(list);
			break;

		}
		default:
			 printf("Invalid datatype format %c", s);
	}
}

