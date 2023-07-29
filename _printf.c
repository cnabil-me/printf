#include "main.h"

/**
 * _printf - Print formatted data to stdout
 * @format: string that contains the text to be written to stdout with format specifiers
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list arg_p;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(arg_p, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_sub_specifiers(&params, arg_p);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
			p++;
		p = get_width(p, &params, arg_p);
		p = get_precision(p, &params, arg_p);
		if (get_modifier(p, &params))
			p++;
		if (!match_specifier(p))
			sum += print_from_to(start, p, params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, arg_p, &params);
	}
	_putchar(BUFFER_FLUSH);
	va_end(arg_p);
	return (sum);
}
