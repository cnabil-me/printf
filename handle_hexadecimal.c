#include "main.h"
/**
 * handle_hexadecimal - Handles and processes an hexadecimal argument.
 * @ap: The argument pointer.
 * @params: The parameters struct.
 *
 * Return: The number of characters printed.
 */
int handle_hexadecimal(va_list ap, params_t *params)
{
	unsigned long l;
	int c = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * handle_hexadecimal_upper_case - prints unsigned hexadecimal number (uppercase)
 * @ap: the argument pointer
 * @params: the parameters struct
 * Return: printed character count
 */
int handle_hexadecimal_upper_case(va_list ap, params_t *params)
{
	unsigned long l;
	int counter = 0;
	char *str;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (counter += print_number(str, params));
}

/**
 * handle_pointer - prints address
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int handle_pointer(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts((char *)"(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
