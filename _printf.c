#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
  int count = 0;
  va_list args;
  va_start(args, format);
  spec *spec_array = create_spec_array();

  while (*format != '\0')
  {
    if (*format == '%')
    {

      handle_speciﬁcations(format + 1, args);
    }
    else
    {
      putchar(*format);
      count++;
    }
    format++;
  }

  va_end(args);
  free(spec_array);
  return count;
}