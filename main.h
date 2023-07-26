#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct frmt - format and functions structure
 * @format: format.
 * @func: corresponding function
 */
struct frmt
{
	char format;
	int (*func)(va_list list);
};

/*
 * typedef formfunc - type defenition for struct
 */
typedef struct frmt formfunc;

int _strlen(const char *str);
int _printf(const char *format, ...);
int print_arg(va_list list, char s);
int print_char(va_list list);
int print_string(va_list list);
char *_strdup(const char *str);
void print_int_str(int num, char *buffer);
#endif
