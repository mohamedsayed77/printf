#include "main.h"


/**
 * _putchar - Writes the character 'c' to the standard output (stdout)
 * @c: The character to be printed
 * Return: On success, it returns 1. On error, -1 is returned,
 * and errno is set accordingly.
 *
 * Description: The _putchar function efficiently writes characters to
 * the standard output (stdout)
 * using a local buffer of size 1024 to minimize the number of
 * write system calls.
 */


int _putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - Prints a string to the console.
 * @str: A pointer to the string to be printed.
 * Return: The number of characters written.
 */

int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

