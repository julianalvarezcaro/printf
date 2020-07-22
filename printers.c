#include "holberton.h"

/**
  * print_c - prints a char
  *
  * @arg: va_list with the arguments
  *
  * Return: chars printed
  */
int print_c(va_list arg)
{
	_putchar(va_arg(arg, int));
	return (1);
}

/**
  * print_str - prints a string
  *
  * @arg: va_list with the args
  *
  * Return: chars printed
  */
int print_str(va_list arg)
{
	char *str;
	int loop;

	str = va_arg(arg, char *);

	if (str == NULL)
		str = "(null)";

	for (loop = 0; str[loop] != '\0'; loop++)
		_putchar(str[loop]);

	return (loop);
}

/**
  * print_per - prints a porcentage
  *
  * @arg: va_list with the args
  *
  * Return: chars printed
  */
int print_per(va_list __attribute__((unused)) arg)
{
	_putchar('%');
	return (1);
}
