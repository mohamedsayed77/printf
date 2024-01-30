#include "main.h"


/**
 * converter - Converts an unsigned long 'num'
 * to a string in the specified 'base'.
 * @num: The number to be converted.
 *
 * @base: Desired base (e.g., 10 for decimal, 16 for hexadecimal).
 *
 * @lowercase: 1 for lowercase letters in bases > 10, 0 for uppercase.
 *
 * Return: String with the converted 'num' in the given 'base'.
 */


char *converter(unsigned long int num, int base, int lowercase)
{
	static char *baseChars;
	static char buffer[50];
	char *ptr;

	baseChars = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = baseChars[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

