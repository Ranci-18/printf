#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
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

	va_start(arguments, format);

	if (!format)
	{
		return (-1);
	}

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
					if (str == NULL)
					{
						write(1, "(null)", 0);
						len += 0;
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
			case '%':
					putchar('%');
					len++;
					break;
			default:
					putchar(format[i]);
					len++;
					break;
			}
		}
                else
                {
                        putchar(format[i]);
                        len++;
                }
        }
        va_end(arguments);
	return (len);
}
