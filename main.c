#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{/**	
*	_printf("Character:[%c]\n", 'H');
*	_printf("My name is: %s\n", "Viashna");
*	_printf("String:[%s]\n", "I am a string !");
*/
	_printf("Unknown:[%r]\n");
	_printf("Let's print a simple sentence.\n");
	_printf("%c", 'S');
	_printf("A char inside a sentence: %c. Did it work?\n", 'F');
	_printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	_printf("%s", "This sentence is retrieved from va_args!\n");
	_printf("%%");
	_printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	_printf("css%ccs%scscscs", 'T', "Test");
	_printf(NULL);
	_printf("%c", '\0');
	_printf("%");
	_printf("%!\n");
	_printf("%K\n");
	_printf("Should print a single percent sign: %%\n");
	printf("Should print a single percent sign: %%\n");
	return (0);
}
