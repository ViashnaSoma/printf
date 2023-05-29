#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
* _printf - prints characters
* format: character string
* Return: printed characters
*/

int _printf(const char *format, ...)
{
	va_list ap;
	int len = 0, i = 0, ast_count = 0, str_len, k, s, print_count = 0;
	char *print, form[] = "cs", *str;
	char ch;

	va_start(ap, format);
	/* counting characters in format to allocate memory */
	while (format && format[i])
	{
		/* determining if there is a conversion to correctly allocate memory */
		if (format[i] == '%')
		{
			/*ast_count used to keep count of number of conversions to correctly allocate to corresponding arguments*/
			ast_count++;
			k = 0;
			while (form[k])
			{
				if (form[k] == format[i + 1])
				{
					break;
				} 
				k++;
			}
			/*allocates number of characters based on length of what is stored in conversion variable*/
			switch (format[i + 1])
			{
			case 'c':
				len = len + 1;
			case 's':
				/*needs to go to next argument and count number of characters and add to len*/
				str = va_arg(ap, char *);
				while (str)
				{
					str_len++;
					len++;
				}
			} /*switch bracket*/
		} /*if bracket*/
		else
		{
			len++;
		}
		i++;	
	}
	/*len increased to account for the null byte at the end of string*/
	len++;
	i = 0;
	/*allocate memory*/
	print = malloc(len * sizeof(char));
	/*go through format and add all characters to string print*/
	while (format && format[i])
	{
		if (format[i] == '%')
			{
				k = 0;
				while (form[k])
				{
					if (form[k] == format[i + 1])
					{
						break;
					} 
					k++;
				}
				/*allocates characters based on conversion type*/
				switch (format[i + 1])
				{
				case 'c':
					ch = va_arg(ap, *char);
					print[print_count] = ch;	
				case 's':
					str = va_arg(ap, char *);
					for (s = 0; s < str_len; s++)
					{
						print[print_count] = ch;
						print++;
					}
				} /*switch bracket*/
			} /*if bracket*/
			else
			{
				print[print_count] = format [i];
			}
		print_count++;
	}
	/*prints to stdout with num characters = len*/
	write (1, print, len);
	/*free memory after printing*/
	free(print);
	va_end(ap);
	return (0);
}
