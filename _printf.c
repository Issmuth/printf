#include "main.h"

/**
 * _printf - printf replica
 * @format: string to be printed
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, is_negative = 0, pos = 0, num;
	char c, buffer[20];
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
				case 'd':
					num = va_arg(args, int);
					if (num < 0)
					{
						is_negative = 1;
						num = -num;
					}
					do {
						buffer[pos++] = (num % 10) + '0';
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

	va_end(args);
	return (count);
}
