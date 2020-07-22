#include "holberton.h"

/**
 * get_fun - returns the function in charge of printing the type of arg given
 *
 * @c: Tells the data type that is going to be printed
 *
 * Return: Pointer to the function that will print
 */
int (*get_fun(char c))(va_list)
{
	printf_t ptrsFun[6] = {
		{"c", print_c},
		{"s", print_str},
		{"%", print_per},
		{"i", print_num_int},
		{"d", print_num_dec},
		{NULL, NULL}
	};

	int loop;

	for (loop = 0; ptrsFun[loop].spef != NULL; loop++)
	{
		if (c == *(ptrsFun[loop].spef))
			return (ptrsFun[loop].fun);
	}
	return (0);
}
