#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/**/
int _printf(const char *format, ...)
{
	va_list arguments;
	int i;
	int len = 0;
	char *str;

	va_start(arguments, format);

	if (!format)
	{
		return (-1);
	}

	len = strlen(format);
	str = malloc(len + 1);
	if (!str)
	{
		va_end(arguments);
		return (-1);
	}
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					putchar((char)va_arg(arguments, int));
					break;
				case 's':
					char *str = va_arg(arguments, char*);
					for (int j = 0; str[j]; j++)
					putchar(str[j]);
					break;
				case 'd':
				case 'i':
				case '%':
					putchar('%');
					break;
			}
		}
		else
		{
		str[i] = format[i];
		}
	}
        str[i] = '\0';

	write(1, str, len);
	va_end(arguments);
	free(str);
	return (len);
}

