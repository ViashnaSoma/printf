#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
* _printf - prints characters
* format: character string
* Return: printed characters
*/

int _printf(char *format, ...)
{
	va_list ap;
	int len = 0, i = 0, ast_count = 0, k, str_len = 0, print_count = 0, str_count = 0;
	char form[] = "cs", *str, *print, cstore;
	va_start(ap, format);

	while (format && format[i] != 0)
	{
		if (format[i] == '%')
		{
			for (k = 0; k < 2; k++)
			{
			if (form[k] == format[i + 1])
				{
					ast_count++;
					switch (format[i + 1])
					{
						case 'c':
							len++;
							cstore = va_arg(ap, int);
							break;
						case 's':
							str = va_arg(ap, char *);
							while (str[str_len])
							{
								str_len++;
							}
							break;
					}
				}
			}
		}
		else
		{
			len++;
		}
		i++;
	}
	len = len + str_len - (ast_count * 2);
	print = malloc(len * sizeof(char));
	i = 0;
	while (format && format[i] != 0 && print_count <= len)
	{
		if (format[i] == '%')
		{
			for (k = 0; k < 2; k++)
			{
				if (form[k] == format[i + 1])
				{
					switch (format[i + 1])
					{
						case 'c':
							i = i + 2;
							print[print_count] = cstore;
							break;
						case 's':
							i = i + 2;
							for (str_count = 0; str_count < str_len; str_count++)
							{
								print[print_count] = str[str_count];
								print_count++;
							}
							break;
					}
				}
			}
		}
		else
		{
			print[print_count] = format[i];
			i++;
		}
		print_count++;
	}
	printf("Using printf: %s\n", print);
	write(1, print, print_count);
	free(print);
	va_end(ap);
	return (0);
}
