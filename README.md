# Printf

> Resources :(https://cplusplus.com/reference/cstdio/printf/[https://cplusplus.com/reference/cstdio/printf/]

## What is Printf function?

```
int printf ( const char * format, ... );
```

`printf` : Print formatted data to stdout

Writes the C string pointed by _format_ to the standard output . If _format_ includes _format specifiers_ (subsequences beginning with %), the additional arguments following _format_ are formatted and inserted in the resulting string replacing their respective specifiers.

## Printf parameters

`@format` C string that contains the text to be written to stdout.

> It can optionally contain embedded _format specifiers_ that are replaced by the values specified in subsequent additional arguments and formatted as requested.

### specifiers

`format specifier` follows this prototype :

>%\[flags\]\[width\]\[.precision\]\[length\]specifier

Where the _specifier character_ at the end is the most significant component, since it defines the type and the interpretation of its corresponding argument:

| _specifier_ | Output | Example |
| --- | --- | --- |
| d _or_ i | Signed decimal integer | 392 |
| u | Unsigned decimal integer | 7235 |
| o | Unsigned octal | 610 |
| x | Unsigned hexadecimal integer | 7fa |
| X | Unsigned hexadecimal integer (uppercase) | 7FA |
| f | Decimal floating point, lowercase | 392.65 |
| F | Decimal floating point, uppercase | 392.65 |
| e | Scientific notation (mantissa/exponent), lowercase | 3.9265e+2 |
| E | Scientific notation (mantissa/exponent), uppercase | 3.9265E+2 |
| g | Use the shortest representation: %e or %f | 392.65 |
| G | Use the shortest representation: %E or %F | 392.65 |
| a | Hexadecimal floating point, lowercase | \-0xc.90fep-2 |
| A | Hexadecimal floating point, uppercase | \-0XC.90FEP-2 |
| c | Character | a |
| s | String of characters | sample |
| p | Pointer address | b8000000 |
| n | Nothing printed.The corresponding argument must be a pointer to a signed int.The number of characters written so far is stored in the pointed location. | |
| % | A % followed by another % character will write a single % to the stream. | % |

### sub_specifiers

The _format specifier_ can also contain sub-specifiers: _flags_, _width_, _.precision_ and _modifiers_ (in that order), which are optional and follow these specifications:

#### sub_specifier_flag

| _flags_ | description |
| --- | --- |
| \- | Left-justify within the given field width; Right justification is the default (see _width_ sub-specifier). |
| + | Forces to preceed the result with a plus or minus sign (+ or \-) even for positive numbers. By default, only negative numbers are preceded with a \- sign. |
| _(space)_ | If no sign is going to be written, a blank space is inserted before the value. |
| # | Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written. |
| 0 | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see _width_ sub-specifier). |

#### sub_specifier_width

| _width_ | description |
| --- | --- |
| _(number)_ | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
| \* | The _width_ is not specified in the _format_ string, but as an additional integer value argument preceding the argument that has to be formatted. |

#### sub_specifier_dot_precision

| _.precision_ | description |
| --- | --- |
| ._number_ | For integer specifiers (d, i, o, u, x, X): _precision_ specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A _precision_ of 0 means that no character is written for the value 0.For a, A, e, E, f and F specifiers: this is the number of digits to be printed **after** the decimal point (by default, this is 6).For g and G specifiers: This is the maximum number of significant digits to be printed.For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered.If the period is specified without an explicit value for _precision_, 0 is assumed.|
| .\* | The _precision_ is not specified in the _format_ string, but as an additional integer value argument preceding the argument that has to be formatted. |The _length_ sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without _length_ specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):

#### sub_specifier

|  | specifiers |
| --- | --- |---|---|---|---|---|---|
| _length_ | d i | u o x X | f F e E g G a A | c | s | p | n |
| _(none)_ | int | unsigned int | double | int | char\* | void\* | int\* |
| hh | signed char | unsigned char | | | | | signed char\* |
| h | short int | unsigned short int | | | | | short int\* |
| l | long int | unsigned long int | | [wint\_t](https://cplusplus.com/wint_t) | wchar\_t\* | | long int\* |
| ll | long long int | unsigned long long int | | | | | long long int\* |
| j | [intmax\_t](https://cplusplus.com/intmax_t) | [uintmax\_t](https://cplusplus.com/uintmax_t) | | | | | [intmax\_t](https://cplusplus.com/intmax_t)\* |
| z | [size\_t](https://cplusplus.com/size_t) | [size\_t](https://cplusplus.com/size_t) | | | | | [size\_t](https://cplusplus.com/size_t)\* |
| t | [ptrdiff\_t](https://cplusplus.com/ptrdiff_t) | [ptrdiff\_t](https://cplusplus.com/ptrdiff_t) | | | | | [ptrdiff\_t](https://cplusplus.com/ptrdiff_t)\* |
| L | | | long double | | | | |

Note regarding the `c` specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char value (or a wchar_t) before formatting it for output.

**Note:** Yellow rows indicate specifiers and sub-specifiers introduced by C99. See [`<cinttypes>`](https://cplusplus.com/%3Ccinttypes%3E) for the specifiers for extended types.

## ... _(additional arguments)_

Depending on the _format_ string, the function may expect a sequence of additional arguments, each containing a value to be used to replace a _format specifier_ in the _format_ string (or a pointer to a storage location, for n).

There should be at least as many of these arguments as the number of values specified in the _format specifiers_. Additional arguments are ignored by the function.

## Return Value

On success, the total number of characters written is returned.
If a writing error occurs, the _error indicator_ (ferror) is set and a negative number is returned. If a multibyte character encoding error occurs while writing wide characters, errno is set to EILSEQ and a negative number is returned.




