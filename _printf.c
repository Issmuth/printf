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
	int i, printed = 0;
	va_list ap;
=======
	va_list args;
	int count = 0;
	char c;
	char *s;
>>>>>>> 25814635b5a9e7bda214c07976594250e393c283

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
		}
		format++;
	}
<<<<<<< HEAD
	va_end(ap);
	return (printed);
=======

	va_end(args);
	return (count);
>>>>>>> 25814635b5a9e7bda214c07976594250e393c283
}
