#include "main.h"

/**
 * handle_address - Prints the address of the input in hexadecimal format.
 * @l: The va_list arguments from _printf.
 * @f: A pointer to the flags structure, determining flag usage in _printf.
 * Return: The count of characters printed.
 */


int handle_address(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));

	str = converter(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}


/**
 * handle_hex - Prints an int in lowercase hexadecimal format.
 * @l: va_list arguments from _printf.
 * @f: Flags structure may affect flag usage.
 * Description: Converts input to lowercase hex and prints.
 * Return: Character count printed.
 */


int handle_hex(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = converter(num, 16, 1);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0x");

	count += _puts(str);
	return (count);
}

/**
 * handle_hex_upper - Prints a number in uppercase hexadecimal base.
 * @l: va_list args from _printf
 * @f: Flags struct to affect usage.
 * Description: Converts input number to string and prints it in uppercase hex.
 * Return: Character count printed.
 */


int handle_hex_upper(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = converter(num, 16, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _puts("0X");

	count += _puts(str);
	return (count);
}

/**
 * handle_binary - Prints a number in binary (base 2).
 * @l: va_list args from _printf
 * @f: Flags struct to affect usage.
 * Description: Converts input number to binary and prints it in base 2 format.
 * If '#' flag is set, includes the "0b" prefix.
 * Return: Character count printed.
 */


int handle_binary(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = converter(num, 2, 0);

	(void)f;
	return (_puts(str));
}


/**
 * handle_octal - Print a number in octal (base 8) format.
 * @l: va_list args from _printf
 * @f: Flags struct to affect usage.
 * Description: Converts input number to octal representation.
 * Prints it in base 8 format, with an optional "0" prefix when
 *  the '#' flag is set.
 * Return: Character count printed.
 */



int handle_octal(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = converter(num, 8, 0);
	int count = 0;

	if (f->hash == 1 && str[0] != '0')
		count += _putchar('0');

	count += _puts(str);
	return (count);
}

