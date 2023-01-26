#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
* print_string - prints string)
* @str: string to be printed
*
* Return: nothing
*/
void print_string(char *str)
{
	int i, len;

	if (str == NULL)
		write(1, "(null)", 6);
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			putchar(str[i]);
			len++;
		}
	}
}

/**
* print_int - prints an integer
* @num: integer to be printed
*
* Return: void
*/
void print_int(int num)
{
	int base, num_temp;

	if (num < 0)
	{
		num = -num;
		putchar('-');
	}
	if (num >= 0 && num <= 9)
	{
		putchar(num + '0');
	}
	if (num > 9)
	{
		base = 10;
		while (num / base > 9)
			base *= 10;
		while (base > 0)
		{
			num_temp = num / base;
			num = num % base;
			putchar(num_temp + '0');
			base = base / 10;
		}
	}
}
