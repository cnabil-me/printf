# Printf language c Project
## Task function

```c
int _printf(const char *format, ...);

```
- Prototype: int _printf(const char *format, ...);
- Returns: the number of characters printed (excluding the null byte used to end output to strings)
- write output to stdout, the standard output stream
## to add

- Handle the following custom conversion specifier:

S : prints the string.
Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)

- Handle the following flag characters for non-custom conversion specifiers:

+
space
`#`

- Handle the following length modifiers for non-custom conversion specifiers:

l
h
Conversion specifiers to handle: d, i, u, o, x, X

- Handle the field width for non-custom conversion specifiers.
- Handle the 0 flag character for non-custom conversion specifiers.
- Handle the - flag character for non-custom conversion specifiers.
- Handle the following custom conversion specifier:
  r : prints the reversed string
- Handle the following custom conversion specifier:

R: prints the rot13'ed string


