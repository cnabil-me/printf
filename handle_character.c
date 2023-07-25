#include "_putchar.c"
/**
 * handle_character - print character and return the print count
 */

int handle_character(char ch)
{
  int i;
  char except[] = {'\0'};

  for (i = 0; i < sizeof(except); i++)

    if (ch == except[i])
      return (0);

  _putchar(ch);
  return (1);
}