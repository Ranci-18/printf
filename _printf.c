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
	char *str;
	int num, num_temp, base;

	if (!format || format == NULL)
	return (-1);

	va_start(arguments, format);
	for (i = 0; format[i] != '\0'; i++)
	{	
		if (format[i])
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == '\0')
				{
					return (-1);
				}
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
							if (str == NULL)
							{
								write(1, "(null)", 6);
							}
							else
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
							num = va_arg(arguments, int);
							{
								if (num < 0)
								{
									num = -num;
									putchar('-');
									len++;
								}
								if (num >= 0 && num <= 9)
								{
									putchar(num + '0');
									len++;
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
										len++;
									}
								}
							}
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
