#include "main.h"

/**
 * _printf - printf replica
 * @format: string to be printed
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
<<<<<<< HEAD
	va_list args;
	int count = 0;
	char c;
	char *s;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char) va_arg(args, int);
					write(1, &c, 1);
					count++;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						return (-1);

					while (*s)
					{
						write(1, s, 1);
						s++;
						count++;
					}
					break;
				default:
					write(1, format, 1);
					count++;
					break;
			}
		} else
		{
			write(1, format, 1);
			count++;
=======
	int len, i, j = 0;
	char specifier;
	va_list ap;

	/* check if the format is which in our case is a string */
	if (format == NULL)
		return (-1);

	/* the arguments we are going to pass on are given the alias ap which is an argument list */
	va_start(ap, format);
	/* keeping track of the whole string of chars provided */
	len = _strlen(format);
	/* loopin over the whole string */
	for (i = 0; i < len; i++)
	{
		/* checking if we have a special char of type '%' */
		if (format[i] != '%')
		{
			/* if not just print out the whole string of chars */
			write(1, &format[i], 1);
			j++;
		} else
		/* checking if we have the special char in our list of strings in the pointer *fomart */
		{	
			/* now check the next char after the special char '%' */
			specifier = format[i + 1];
			/* delete the chars */
			j--;
			/* now add the value which is supposed to be there from the list of given arguments */
			j += print_arg(ap, specifier);
			/* even after there still continue adding the rest of chars available */
			i++;
>>>>>>> dc1616e5ce3af0f38e3e6ca66a06ee899c7242d2
		}
		format++;
	}
<<<<<<< HEAD

	va_end(args);
	return (count);
=======
	/* now j contains both the list of argumenst passed and the strings of chars which were present inside the _printf() */
	return(j);
>>>>>>> dc1616e5ce3af0f38e3e6ca66a06ee899c7242d2
}
