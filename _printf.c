#include "main.h"

int _printf(const char *format, ...)
{
	int count = 0;
	va_list ap;

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
				count += handle_spec(format + 1, va_arg(ap, char *));
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
