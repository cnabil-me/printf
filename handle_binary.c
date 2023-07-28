#include "main.h"
/**
 * handle_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
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
