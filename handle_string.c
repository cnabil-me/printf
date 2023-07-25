#include "main.h"
/**
 * handle_string - print character and return the print count
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
