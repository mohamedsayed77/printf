#include "main.h"


/**
 * handle_percent - Handles printing of a percent symbol ('%').
 * @l: The va_list of arguments from _printf.
 * @f: A pointer to the struct flags that determines if
 *	a flag is passed to _printf.
 * Return: The number of characters printed.
 */


int handle_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar('%'));
}


/**
 * handle_int - Handles printing of an integer.
 * @l: The va_list of arguments from _printf.
 * @f: A pointer to the struct flags determining if
 *	a flag is passed to _printf.
 * Return: The number of characters printed.
 */


int handle_int(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int res = count_digits(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		res += _putchar(' ');

	if (f->plus == 1 && n >= 0)
		res += _putchar('+');

	if (n <= 0)
		res++;

	print_positive_integer(n);
	return (res);
}


/**
 * handle_unsigned - Handles printing of an unsigned integer.
 * @l: The va_list of arguments from _printf.
 * @f: A pointer to the struct flags determining if
 *	a flag is passed to _printf.
 * Return: The number of characters printed.
 */


int handle_unsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = converter(u, 10, 0);

	(void)f;
	return (_puts(str));
}


/**
 * print_positive_integer - Prints the digits of a positive integer.
 * @n: The positive integer to be printed.
 */


void print_positive_integer(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}

	else
		n1 = n;

	if (n1 / 10)
		print_positive_integer(n1 / 10);

	_putchar((n1 % 10) + '0');
}


/**
 * count_digits - Counts the number of digits in an integer.
 * @i: The integer to evaluate.
 * Return: The number of digits in the integer.
 */


int count_digits(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;

	else
		u = i;

	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}

