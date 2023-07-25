#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
int _printf(const char *format, ...);
<<<<<<< HEAD
=======
int print_arg(va_list list, char s);
int print_char(va_list list);
int print_string(va_list list);
char *_strdup(const char *str);
>>>>>>> dc1616e5ce3af0f38e3e6ca66a06ee899c7242d2
#endif
