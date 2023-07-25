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
	write(1, &c, 1);
	return (1);
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
	int pos = 0;
	int is_negative = 0;
	int count = 3;
	char *buffer;
	/* Assuming the largest int can be represented in 19 characters*/
	buffer = malloc(num * sizeof(char));

	if (buffer == NULL)
	{
		printf("Memory allocation failed");
		return (-1);
	}

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
	int i;
	int j = 3;
	char *buffer;

	buffer = malloc(num * sizeof(char));

	if (buffer == NULL)
	{
		printf("Memory allocation failed");
		return (-1);
	}

	print_int_str(num, buffer);

	for (i = 0; buffer[i] != '\0'; i++)
	{
		write(1, &buffer[i], 1);
		j++;
	}
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
	int count;
	switch (s)
	{
		case 'c':
		{
			count = print_char(list);
			break;
		}
		case 's':
		{
			count = print_string(list);
			break;
		}
		case 'd':
		{
			count = print_digits(list);
			break;

		}
		case 'i':
		{
			count = print_integers(list);
			break;
		}
		default:
		{
			printf("Invalid datatype format %c", s);
			break;
		}
	}
	return (count);
}
