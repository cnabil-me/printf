#include <stdio.h>
#include "main.h"
#include "_printf.c"

int main(void)
{
  _printf("Character:[%c] ab%hello\n", 'H');
  // _printf("Character:[%c] %hello\n", 'H');
}