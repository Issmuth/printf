#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct format - format and function structure
 * @fmt: format
 * @func: corresponding function
 *
 * Return: printed chars
 */

struct format
{
	char fmt;
	int (*func)(va_list list);
};

int _strlen(const char *str);
int _atoi(char *str);
int _printf(const char *format, ...);
int print_arg(const char *format, va_list list, int *j);
int print_char(va_list list);
int print_string(va_list list);
#endif
