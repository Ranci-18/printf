#include "main.h"
#include <stdio.h>
/**
* print_string - prints a string
* @str: string to be printed
*
* Return: nothing
*/
void print_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		putchar(str[i]);
}
