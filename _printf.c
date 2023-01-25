#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
* _printf - prints anything
* @format: character string containing directives
*
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list arguments;
	int i;
	int len = 0;
	char *str;

	va_start(arguments, format);
	if (!format)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				putchar((char)va_arg(arguments, int));
				len++;
				break;
			case 's':
				str = va_arg(arguments, char*);
<<<<<<< HEAD
					if (str)
					{
						print_string(str);
						len++;
					}
					break;
=======
				if (str == NULL)
					write(1, "(null)", 0);
				else
				{
					print_string(str);
					len++;
				}
				break;
>>>>>>> 3c62a75912b293f325d9fc2b861a84fc1c798502
			case '%':
				putchar('%');
				len++;
				break;
			}
		}
<<<<<<< HEAD
                else
=======
		else
>>>>>>> 3c62a75912b293f325d9fc2b861a84fc1c798502
		{
			putchar(format[i]);
			len++;
		}
	}
	va_end(arguments);
	return (len);
}
