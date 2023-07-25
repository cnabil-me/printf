#ifndef HELPERS_H
#define HELPERS_H

#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

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

/**
 * char_in_array - check if a char is in array
 */
int char_in_array(char ch, char char_arr[], int count)
{
  int i;

  for (i = 0; i < count; i++)

    if (char_arr[i] == ch)
      return (1);

  return (0);
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1 and -1 on error.
 */
int _putchar(char c)
{
  return (write(1, &c, 1));
}
/**
 * struct spec_convert - matchig function handler based on specifier
 * @spec: the specifier after `%`
 * @func: pointer to the according function
 */
typedef struct spec_convert
{
  char spec;
  int (*func)(char *str, va_list argp);
} spec;

spec *create_spec_array()
{
  // int i = 0;
  spec *spec_array = malloc(10 * sizeof(spec));

  spec_array[0].spec = 'c';
  spec_array[0].func = handle_character;

  return spec_array;
}

#endif