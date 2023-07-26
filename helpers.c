#include "main.h"
/**
 * char_in_array - check if a char is in array
 * @ch: char to check
 * @char_arr: array to search in
 * @count: size of searched in array
 * Return: if found 1 otherwize 0
 */
int char_in_array(char ch, char char_arr[], int count)
{
	int i;

	for (i = 0; i < count; i++)

		if (char_arr[i] == ch)
			return (1);

	return (0);
}

