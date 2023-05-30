#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
* _printf - prints characters
* @format: character string
* Return: printed characters
*/

int _printf(char *format, ...)
{
	va_list ap;
	int len = 0, i = 0, ast_count = 0, k, str_len = 0;
	int print_count = 0, str_count = 0, check = 0;
	char form[] = "cs", *str, *print, cstore;

	va_start(ap, format);

	while (format && format[i] != 0)
	{
		if (format[i] == '%')
		{
			check = 0;
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
							check = 1;
							break;
						case 's':
							str = va_arg(ap, char *);
							while (str[str_len])
							{
								str_len++;
							}
							check = 1;
							break;
					}
				}
			}
		}
		if ((check == 0) && (format[i] == '%'))
		{
			len++;
		}
		else if (format[i] != '%')
		{
			len++;
		}
		i++;
	}
	len = len + str_len - (ast_count * 2);
	print = malloc(len * sizeof(char));
	printf("Length: %d\n", len);
	i = 0;
	while (format && format[i] != 0 && print_count <= len)
	{
		if (format[i] == '%')
		{
			check = 0;
			for (k = 0; k < 2; k++)
			{
				if (form[k] == format[i + 1])
				{
					switch (format[i + 1])
					{
						case 'c':
							i = i + 2;
							print[print_count] = cstore;
							print_count++;
							check = 1;
							break;
						case 's':
							i = i + 2;
							for (str_count = 0; str_count < str_len; str_count++)
							{
								print[print_count] = str[str_count];
								print_count++;
							}
							check = 1;
							break;
					}
				}
			}
		}
		if ((check == 0) && (format[i] == '%'))
		{
			print[print_count] = format[i];
			i++;
			print_count++;
		}
		if (format[i] != '%')
		{
			print[print_count] = format[i];
			i++;
			print_count++;
		}
	}
	write(1, print, print_count);
	free(print);
	va_end(ap);
	return (0);
}
