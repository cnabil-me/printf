#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdarg.h>

// Main print function prototype
int _printf(const char *format, ...);

// Buffers
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"

// Structure

/**
 * struct spec_convert - matchig function handler based on specifier
 * @spec: the specifier after `%`
 * @func: pointer to the according function
 * Return: the number of characters printed except NULL
 */

typedef struct spec_convert
{
	char spec;					     // d,f,s
	int (*according_func)(const char *str, char *value); // handler

} spec_convert;

// Helpers
int char_in_array(char ch, char char_arr[], int count);
int _putchar(char c);
int string_to_decimal(char *s);

// Spec Handler
int handle_spec(const char *str, char *value);

// Data types handlers
int handle_character(const char *str, char *value);
int handle_string(const char *str, char *value);
int handle_binary(const char *str, char *value);
int handle_integer(const char *str, char *value);
int handle_decimal(const char *str, char *value);
int handle_float(const char *str, char *value);
int handle_integer(const char *str, char *value);
int handle_octal(const char *str, char *value);
int handle_unsigned_binary_int(const char *str, char *value);
int handle_unsigned_hexadecimal(const char *str, char *value);
int handle_pointer_address(const char *str, char *value);

#endif
