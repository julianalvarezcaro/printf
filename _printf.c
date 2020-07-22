#include "holberton.h"

/**
 * validateMultiplePercent - the percentage must go with a pair
 *
 * @format: string format for printing
 *
 * Return: a flag if the
 */
int validateMultiplePercent(const char *format)
{
	int iterator;
	int numberOfPercents;

	numberOfPercents = 1;
	for (iterator = 0; format[iterator] != '\0'; iterator++)
	{
		if (format[iterator] == '%' && format[iterator + 1] == '%')
		{
			while (format[iterator + 1] == '%')
			{
				numberOfPercents++;
				iterator++;
			}
			if (numberOfPercents % 2 != 0 && format[iterator + 1] == '\0')
				return (0);
		}
	}
	return (1);
}

/**
 * _printf - prints the given arguments
 *
 * @format: Tells what it is going to print
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list valist;
	int loop, counter = 0;
	int (*printer)(va_list);

	if ((!format) || (format[0] == '%' && format[1] == '\0') ||
	    !(validateMultiplePercent(format)))
		return (-1);
	va_start(valist, format);
	for (loop = 0; format[loop] != '\0'; loop++)
	{
		/*Entra a revisar si ve primero un % */
		if (format[loop] == '%')
		{
			++loop;
			printer = get_fun(format[loop]);
			if (printer != 0)
				counter += (*printer)(valist);
			else
			{
				_putchar('%');
				_putchar(format[loop]);
				counter += 2;
			}
		}
		/*Implementar la impresion del string normal*/
		else
		{
			_putchar(format[loop]);
			counter++;
		}
	}
	va_end(valist);
	return (counter);
}
