#include "main.h"
/**
 * handle_decimal - handle decimal and return the print count
 * @str: the string formatter.
 * @value: The value to be printed.
 * Return: the number of characters printed except NULL
 */

int handle_decimal(const char *str, char *value)
{
	if (*str == 'd')
		printf("\n String is : %s and value is :%s\n", str, value);

	return (0);
}
