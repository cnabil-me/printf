#include "main.h"
/**
 * handle_character - print character and return the print count
 */

int handle_character(char *str, va_list argp)
{

  if (str)
    return _putchar(*str);
  return 0;
}