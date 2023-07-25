#include "handle_character.c"
#include "detect_spec.c"
#include "helpers.c"
#include <stdio.h>

/**
 * _printf - Print formatted string
 * @format: Text format
 * Return: Count of printed elements
 */
int _printf(const char *format, ...)
{
  int c = 0;
  int i = 0;
  char char_arr[] = {'a', 'b', 'c'};
  char *p = NULL;
  while (*format)
  {
    p + i = format;
    if (*format == '%')
    {
      detect_spec(p);
    }
    i++;
    format++;
  }

  // c += handle_character('o');
  return (0);
}
