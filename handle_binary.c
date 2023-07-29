#include "main.h"
/**
 * handle_binary - function to print an unsigned binary number
 * @ap: pointer to point struct
 * @params: sub specifier parameter
 * Return: Return the number of bytes printed
 */
int handle_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}
