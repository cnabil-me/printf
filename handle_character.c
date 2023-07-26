#include "main.h"
/**
 * handle_character - Handle and print character and return the print count
 * @str: the string formatter.
 * @value: The value to be printed.
 * Return: the number of characters printed except NULL
 */

int handle_character(const char *str, char *value)
{
	if (*str)
	{
		if (*value)
		{
			return (_putchar(*value));
		}
	}

	return (0);
}
