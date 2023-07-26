#include "main.h"
#include <stdlib.h>
/**
 * create_spec_array - create specifications array
 * Return: spec_array
 */
spec_convert *create_spec_array(void)
{
	spec_convert *spec_array = (spec_convert *)malloc(3 * sizeof(spec_convert));

	spec_array[0].spec = 'c';
	spec_array[0].according_func = handle_character;

	spec_array[1].spec = 's';
	spec_array[1].according_func = handle_string;

	spec_array[2].spec = 'd';
	spec_array[2].according_func = handle_decimal;

	return (spec_array);
}
/**
 * handle_spec - map function specifier to func handler
 * @str: the specifier after `%`
 * @value: pointer to the string value
 * Return: the number of characters printed except NULL
 */
int handle_spec(const char *str, char *value)
{
	int i, count = 0;

	spec_convert *spec_array = create_spec_array();

	for (i = 0; i < 3; i++)
	{
		if (spec_array[i].spec == *str)
		{
			count += spec_array[i].according_func(str, value);
		}
	}
	free(spec_array);
	return (count);
}
