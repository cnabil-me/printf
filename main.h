#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "helpers.h"

// Buffers

/*
Use a local buffer of 1024 chars in order to call write as little as possible.
*/

// Main print function prototype
int _printf(const char *format, ...);

// Helpers
int char_in_array(char ch, char char_arr[], int count);
int _putchar(char c);

// Spec Handler
int handle_speciﬁcations(const char *str, va_list value);

// Data types handlers
int handle_character(char *str, va_list argp);
int handle_string(char *str, va_list argp);
int handle_binary(char *str, va_list argp);
int handle_integer(char *str, va_list argp);
int handle_decimal(char *str, va_list argp);
int handle_float(char *str, va_list argp);
int handle_integer(char *str, va_list argp);
int handle_octal(char *str, va_list argp);
int handle_unsigned_binary_int(char *str, va_list argp);
int handle_unsigned_hexadecimal(char *str, va_list argp);
int handle_pointer_address(char *str, va_list argp);

#endif
