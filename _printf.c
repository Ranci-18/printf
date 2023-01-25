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
	int i, j;
	int len = 0;
	char *str, *buf;

	va_start(arguments, format);
	if (!format)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		putchar(format[i]);
		len++;
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
				if (str != NULL)
					{
						for (j = 0; str[j] != '\0'; j++)
						{
							putchar(str[j]);
							len++;
						}
					}
				break;
			case 'd':
			case 'i':
				buf = malloc(strlen(format));
				len = sprintf(buf, "%i", va_arg(arguments, int));
				write(1, buf, strlen(buf));
				break;
			case '%':
				putchar('%');
				len++;
				break;
			default:
				putchar(format[i]);
				len++;
			}
		}
	}
	va_end(arguments);
	return (len);
}
