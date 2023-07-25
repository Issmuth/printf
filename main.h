#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int print_arg(va_list list, char s);
int print_char(va_list list);
int print_string(va_list list);
char *_strdup(const char *str);
#endif
