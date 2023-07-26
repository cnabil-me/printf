#include "main.h"
/**
 * _printf - print formated text
 * @format: the format
 * Return: counter of printed chars
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list ap;
	char c;

	va_start(ap, format);

	while (*format)
	{

		if (*format == '%')
		{

			if (*(format + 1) == '%')
			{
				count += _putchar('%');
				format += 2;
				continue;
			}
			else
			{
				if (*(format + 1) == 'c')
				{
					c = (char)va_arg(ap, int);
					count += handle_spec(format + 1, &c);
				}
				else
				{
					count += handle_spec(format + 1, va_arg(ap, char *));
				}
				format++;
			}
			format++;
			continue;
		}
		else
		{
			count += _putchar(*format);
			format++;
		}
	}

	va_end(ap);

	return (count);
}
