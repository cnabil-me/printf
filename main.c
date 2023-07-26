#include "main.h"
/**
 * main -  the entry point
 * Return:  Always 0
*/
int main(void)
{

	printf("\nCounter of string is : %d \n", _printf("%s123", "cnabil"));
	printf("\nCounter of %% is : %d \n", _printf("%%"));
	printf("\nCounter of char is : %d \n", _printf("%cello", "H"));

	return (0);
}
