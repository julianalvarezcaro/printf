#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct printf - prints depending on the formar specifiers.
 * @spef: format specifier.
 * @fun: pointer to the print function.
 */
typedef struct printf
{
	char *spef;
	int (*fun)(va_list);
} printf_t;


int _putchar(char c);
int _strlen(char *s);
int _strlen_from(const char *s, int from);

int _printf(const char *format, ...);
int (*get_fun(char c))(va_list);
int print_c(va_list arg);
int print_str(va_list arg);
int print_num_dec(va_list arg);
int print_num_int(va_list arg);
int print_per(va_list arg);
int spacesAux(const char *format, int *counter, int *loop);

#endif
