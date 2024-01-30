#include "main.h"


/**
 * handle_bigS - Handles 'S' specifier to print a string,
 *  converting non-printable
 * characters (0 <= ASCII value < 32 or >= 127) to '\xHH' format.
 *
 * @l: The va_list arguments from _printf.
 * @f: A pointer to the struct flags for potential flag usage.
 *
 * Return: The number of characters printed.
 */


int handle_bigS(va_list l, flags_t *f)
{
	int i, count = 0;
	char *res;
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{

		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = converter(s[i], 16, 0);

			if (!res[1])
				count += _putchar('0');

			count += _puts(res);
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
}


/**
 * handle_rev - Handles the 'r' specifier to print a string in reverse.
 *
 * @l: The va_list argument from _printf.
 * @f: A pointer to the struct flags for potential flag usage.
 *
 * Return: The length of the printed string.
 */


int handle_rev(va_list l, flags_t *f)
{
	int i = 0, j;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}


/**
 * handle_rot13 - Handles the 'R' specifier to print
 * a string using ROT13 encryption.
 *
 * @l: The va_list argument from _printf.
 * @f: A pointer to the struct flags for potential flag usage.
 *
 * Return: The length of the printed string.
 */


int handle_rot13(va_list l, flags_t *f)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);

	(void)f;

	for (j = 0; s[j]; j++)
	{
		if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
			_putchar(s[j]);

		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (s[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}


/**
 * handle_string - Handles the printing of a string.
 * @l: The va_list arguments from _printf.
 * @f: A pointer to the struct flags that determines
 * if a flag is passed to _printf.
 * Return: The number of characters printed.
 */


int handle_string(va_list l, flags_t *f)
{
	char *s = va_arg(l, char *);

	(void)f;

	if (!s)
		s = "(null)";

	return (_puts(s));
}


/**
 * handle_char - Handles the printing of a character.
 * @l: The va_list arguments from _printf.
 * @f: A pointer to the struct flags that determines
 * if a flag is passed to _printf.
 * Return: The number of characters printed.
 */


int handle_char(va_list l, flags_t *f)
{
	(void)f;
	_putchar(va_arg(l, int));
	return (1);
}
