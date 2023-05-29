#include "main.h"
/**
 * print_char - function that prints a char
 * @types: arguments
 * @buffer: handle print
 * @flags: calculates the active flags
 * @width: width of flag
 * @precision: specification
 * @size: specifier
 * Return: Chars printed
 */
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size)
{
/* getting the next argument from variadic arguemts list as an integer 
 */
char c = va_arg(types, int);
return handle_write_char(c, buffer, flags, width, precision, size);
/**
 * print_string - function that prints a string
 * @types: arguments
 * @buffer: handle print
 * @flags: calculates the active flags
 * @width: width of flag
 * @precision: specification
 * @size: specifier
 * Return: chars printed
 */
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size)
{
int len = 0;
int a;
char *str = va_arg(types,char*);
void (buffer);
void(flags);
void(width);
void(precision);
void(size);
/*checks if string is NULL*/
if (!str)
{
/*assign located copy of NULL to str*/
str = strdup("(null)");
if (precision >= 6)
str = "  ";
}
while (str[len] != '\0')
len++;
if (precision >= 0 && precision < len)
/*length of the string is based on the precision value*/
len = precision;
if (width > len)
{
if (flags & F_MINUS)
{
/*left-justify string with width*/
write(1, &str[0],len);
for (a = width - len; a > 0; a--)
write(1, "", 1);
return (width);
}
else
{
/*rigth-justify*/
for (a = width - len; a > 0; a--)
write(1, "", 1);
write(1, &str[0],len);
return (width);
}
}
/*width adjustment is nt needed*/
return (write(1, str, len));
}
/**
 * print percent - funtion that prints percent sign
 * @types: arguemts
 * @buffer: handle print
 * @flags: active flags available to print
 * @width: calculate width
 * @precision: specifications
 * @size: specifier
 * Return: Number of chars to be printed
 */
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size)
{
void(types);
void(buffer);
void(flags);
void(width);
void(precision);
void(size);
return (write(1, "%%", 1));
}
/**
 * print_int - function that prints int
 * @@types: arguemts
 * @buffer: handle print
 * @flags: active flags available to print
 * @width: calculate width
 * @precision: specifications
 * @size: specifier
 * Return: Number of chars to be printed
 */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int j = BUFF_SIZE -2;
int is_negative = 0;
long int a = va_arg(types, long int);
unsigned long int number;
a = convert_size_number(a, size);
if (a == 0)
buffer[j--] = '0';
buffer[BUFF_SIZE -1] = '\0';
number = (unsigned long int)a;
if (a < 0)
{
number = (unsigned long int)((-1)* a);
is_negative = 1;
}
while (number > 0)
{
buffer[j--] = (number % 10) + '0';
number /= 10;
}
j++;
return (write_number(is_negative, j,buffer, flags, width, precision, size))
/**
 * print_binary - function that prints unsigned number
 * @@types: arguemts
 * @buffer: handle print
 * @flags: active flags available to print
 * @width: calculate width
 * @precision: specifications
 * @size: specifier
 * Return: Number of chars to be printed
 */
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size)
{
unsigned int a, b, c, sum;
unsigned int i[32];
int count;
void(buffer);
void(flags);
void(width);
void(precision);
void(size);
a = va_arg(types, unsigned int);
b = 2147483648; 
i[0] = a / b;
for (c = 1; c < 32; c++)
{
b /= 2;
i[c] = (a / b) % 2;
}
for (c = 0; sum = 0, count = 0; c < 32; c++)
{
sum += i[c];
if (sum || c == 31)
{
char z = '0' + i[c];
write(1, &z, 1);
count++;
}
}
return (count);
}


