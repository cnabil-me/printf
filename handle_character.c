#include "main.h"
/**
 * handle_character - print character and return the print count
 */

int handle_character(const char *str, char *value)
{
	// char c = (char)*value;

	if (*str)
	{
		if (*value)
		{
			return _putchar(*value);
		}
	}

	return 0;
}
