#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define NULL_STRING "(null)"
#define PARAMS_INIT                          \
	{                                    \
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
	}
/**
 * struct parameters - sub specifier parameters
 * @unsign: 1 if plus unsign specified
 * @plus_flag: 1 if plus flag specified
 * @minus_flag: 1 if minus flag specified
 * @space_flag: 1 if space flag specified
 * @hashtag_flag: 1 if hashtag flag specified
 * @zero_flag: 1 if zero flag specified
 * @width: custom with specifier
 * @precision: costum precision specifier
 * @h_modifier: 1 if short modifier specified
 * @l_modifier: 1 if long modifier specified
 */
typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int minus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} params_t;

/**
 * struct specifier - specifier function map
 * @specifier: char specifier without %
 * @f: The associated function
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

// Handle numbers
int print_number(char *str, params_t *params);
int handle_integer(va_list ap, params_t *params);
int handle_unsigned_integer(va_list ap, params_t *params);
int handle_number_right_shift(char *str, params_t *params);
int handle_number_left_shift(char *str, params_t *params);

// Handle caracters

int handle_character(va_list ap, params_t *params);
int _puts(char *str);
int _putchar(int c);

// Handle string
int print_S(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int handle_rot13(va_list ap, params_t *params);

// Handle Hexadecimal
int handle_hexadecimal(va_list ap, params_t *params);
int handle_hexadecimal_upper_case(va_list ap, params_t *params);
int handle_pointer(va_list ap, params_t *params);

// Handle binary
int handle_binary(va_list ap, params_t *params);

// Handle Octal
int handle_octal(va_list ap, params_t *params);

// Handle specifiers
void init_sub_specifiers(params_t *params, va_list ap);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);
int get_modifier(char *s, params_t *params);
int (*match_specifier(char *s))(va_list ap, params_t *params);

// Helpers
char *get_precision(char *p, params_t *params, va_list ap);
char *convert(long int num, int base, int flags, params_t *params);
int _strlen(char *s);
int is_digit(int c);

// _Printf function
int _printf(const char *format, ...);

#endif
