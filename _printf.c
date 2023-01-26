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
	int i, len = 0;
	char *str;
	int num;

	if (!format)
		return (-1);
	va_start(arguments, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i])
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == '\0')
					return (-1);
				i++;
				if (format[i]  == '%')
				{
					putchar('%');
					len++;
				}
				if (format[i])
				{
					switch (format[i])
					{
						case 'c':
							putchar((char)va_arg(arguments, int));
							len++;
							break;
						case 's':
							str = va_arg(arguments, char*);
							print_string(str);
							break;
						case 'd':
						case 'i':
							num = va_arg(arguments, int);
							print_int(num);
							len++;
							break;
					}
				}
			}
			else
			{
				putchar(format[i]);
				len++;
			}
		}
	}
	va_end(arguments);
	return (len);
}
