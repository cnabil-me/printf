#include "main.h"

/**
 * handle_string - Handle and print strings and return the print count
 * @str: the string formatter.
 * @value: The value to be printed.
 * Return: the number of characters printed except NULL
 */

int handle_string(const char *str, char *value)
{
	int count = 0;

	if (!*str)
		return (0);

	if (*str == 's')

		while (*value)
		{
			count += _putchar(*value);
			value++;
		}

	return (count);
}
