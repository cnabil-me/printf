#include "main.h"

/**
 * match_specifier - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*match_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
	    {"c", handle_character},
	    {"d", handle_integer},
	    {"i", handle_integer},
	    {"s", print_string},
	    {"%", print_percent},
	    {"b", handle_binary},
	    {"o", handle_octal},
	    {"u", handle_unsigned_integer},
	    {"x", handle_hexadecimal},
	    {"X", handle_hexadecimal_upper_case},
	    {"p", handle_pointer},
	    {"S", print_S},
	    {"r", print_rev},
	    {"R", handle_rot13},
	    {NULL, NULL}};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}
