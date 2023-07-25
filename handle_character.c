#include "main.h"
/**
 * handle_character - print character and return the print count
 */

int handle_character(const char *str, char *value)
{

	if (*value && *str)
		return _putchar(*str);

	return 0;
}
