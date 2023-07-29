#include "main.h"
/**
 * _putchar - Writes a character to the standard output (stdout).
 * @ch: The character to be written.
 * Return: On success, returns the character written (unsigned char cast to int).
 *         On error, returns -1 and sets errno (if applicable).
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
 * print_percent - Handle and prints the percent symbol.
 * @ap: The argument pointer (unused in this function).
 * @params: sub specifier parameter
 * Return: The number of characters printed (always 1).
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}
/**
 * handle_character - Handle and processes a character argument.
 * @ap: The argument pointer.
 * @params: sub specifier parameter
 * Return: The number of characters processed (always 1).
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
