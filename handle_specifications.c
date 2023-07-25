#include "main.h"
#include "helpers.h"
#include <stdio.h>
#include "handle_character.c"

int handle_speciﬁcations(const char *str, va_list value)
{
  spec *spec_array = create_spec_array();
  while (*str)
  {
    printf("Specifier is : %c", *str);
  }
  str++;
  return 0;
}
