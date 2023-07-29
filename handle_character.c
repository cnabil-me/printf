#include "main.h"
/**
 * _putchar - writes a character c to stdout
 * @c: The character to print
 * Return: (1) on success , (-1) on error.
 */
int _putchar(int ch)
{
	static int i;
	static char buffer_t[BUFFER_SIZE];

	if (ch == BUFFER_FLUSH || i >= BUFFER_SIZE)
	{
		write(1, buffer_t, i);
		i = 0;
	}
	if (ch != BUFFER_FLUSH)
		buffer_t[i++] = ch;
	return (1);
}
/**
 * print_percent - print percent (%) character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}
/**
 * handle_character - prints character
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int handle_character(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}
