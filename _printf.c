#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
* _printf - prints characters
* format: character string
* Return: 0 for success, -1 for failure
*/

int _printf(const char *format, ...)
{
	int len = 0, i, ;
	char *print, form[] = "cdis";

	/* counting characters in format to allocate memory */
	while format[i] != NULL
	{
		len++;
		i++;
		print = print + format[i];
		/* determining if there is a conversion to correctly allocate memory */
		if format[i] = "%"
		{
			k = 0;
			while (form[k])
			{
				if (form[k] == format[i + 1])
				{
					break;
				} k++;
			}
			switch (format[i + 1])
			{
			case 'c':
			
	}
	len++;
	
}
