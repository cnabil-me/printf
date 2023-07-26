#include "main.h"
/**
 * handle_decimal - handle decimal and return the print count
 * @str: the string formatter.
 * @value: The value to be printed.
 * Return: the number of characters printed except NULL
 */

int handle_decimal(const char *str, char *value)
{
	int count = 0;

	while (*value)
	{
		if (*str)
		{
			count += _putchar(*value);
		}
		value++;
	}
	return (count);
}
