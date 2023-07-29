#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define BUFFER_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT                          \
	{                                    \
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0 \
	}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign : 1;

	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);
int handle_character(va_list ap, params_t *params);
int handle_integer(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);
int handle_unsigned_integer(va_list ap, params_t *params);
int handle_pointer(va_list ap, params_t *params);

int (*match_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

int handle_hexadecimal(va_list ap, params_t *params);
int handle_hexadecimal_upper_case(va_list ap, params_t *params);
int handle_binary(va_list ap, params_t *params);
int handle_octal(va_list ap, params_t *params);

int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int handle_rot13(va_list ap, params_t *params);

int is_digit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int handle_number_right_shift(char *str, params_t *params);
int handle_number_left_shift(char *str, params_t *params);

void init_sub_specifiers(params_t *params, va_list ap);

char *get_precision(char *p, params_t *params, va_list ap);

int _printf(const char *format, ...);

#endif
