#include "holberton.h"

/**
 *print_num_dec - print numbers.
 *@arg: va_list with the arguments.
 *Return: return number of characters printed.
 */
int print_num_dec(va_list arg)
{
	int characterCounter, num, pos, numCountHelper, numPh, cVal;
	char *printable;

	characterCounter = 0;
	pos = 0;
	num = va_arg(arg, int);
	if (num == 0)
	{
		_putchar(48);
		++characterCounter;
		return (characterCounter);
	}
	numCountHelper = (num > 0) ? (num) : ((num) * -1);
	numPh = (num > 0) ? (num) : ((num) * -1);
	while (numCountHelper != 0)
	{
		characterCounter++;
		numCountHelper /= 10;
	}

	printable = malloc(characterCounter * sizeof(char));
	if (printable == NULL)
		return (characterCounter);
	while (numPh != 0)
	{
		cVal = ((numPh < 0 ? (numPh * -1) : numPh) % 10);
		printable[pos] = '0' + (cVal < 0 ? (cVal * -1) : cVal);
		numPh /= 10;
		pos++;
	}
	if (num < 0)
		_putchar('-');
	pos = 0;
	for (pos = characterCounter - 1; pos >= 0; pos--)
		_putchar(printable[pos]);
	if (num < 0)
		characterCounter++;
	free(printable);
	return (characterCounter);
}

/**
 *print_num_int - print num int.
 *@arg: va_list with the arguments.
 *Return: return number of characters printed.
 */
int print_num_int(va_list arg)
{
	return (print_num_dec(arg));
}

