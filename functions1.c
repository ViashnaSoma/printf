#include "main.h"
/**
 * print_unsigned - function that prints an unsigned number
 * @types: arguments
 * @buffer: array to handle print
 * @flags:  active flags
 * @width: calcuate width
 * @precision: P specification
 * @size: specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);
number = convert_size_unsgnd(number, size);
if (number == 0)
buffer[a] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (number > 0)
{
buffer[a--] = (number % 10) + '0';
number /= 10;
}
a++;
return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
/**
 * print_octal - function that prints an unsigned number in octal
 * @types: arguments
 * @buffer: array to handle print
 * @flags:  active flags
 * @width: calcuate width
 * @precision: spiecification
 * @size: specifier
 * Return: number of chars rinted
 */
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);
unsigned long int init_num = number;
UNUSED(width);
number = convert_size_unsgnd(number, size);
if (number == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (number > 0)
{
buffer[a--] = (number % 8) + '0';
number /= 8;
}
if (flags & F_HASH && init_num != 0)
buffer[a--] = '0';
a++;
return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
/**
 * print_hexadecimal - a function that prints an unsigned number
 * @types: arguments
 * @buffer: array to handle print
 * @flags:  active flags
 * @width: calcuate width
 * @precision: spiecification
 * @size: specifier
 * Return: number of chars rinted
 */
int print_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hexa(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}
/**
 * print_hexa_upper - a function that prints number in upper decimal
 * @types: arguments
 * @map_to: values to map
 * @buffer: array to handle print
 * @flags:  active flags
 * @flag_ch: active flags
 * @width: calcuate width
 * @precision: spiecification
 * @size: specifier
 * Return: number of chars rinted
 */
int print_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int number = va_arg(types, unsigned long int);
unsigned long int init_num = number;
UNUSED(width);
number = convert_size_unsgnd(number, size);
if (number == 0)
buffer[a--] = '0';
buffer[BUFF_SIZE - 1] = '\0';
while (number > 0)
{
buffer[a--] = map_to[number % 16];
number /= 16;
}
if (flags & F_HASH && init_num != 0)
{
buffer[a--] = flag_ch;
buffer[a--] = '0';
}
a++;
return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
