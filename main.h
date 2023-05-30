#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1		

/**
 * struct fmt - Struct op
 * @fmt: format
 * @fn: function associated
 */
struct fmt
{
        char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
#endif
