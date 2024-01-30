#include "main.h"

/**
 * _printf - Formats and prints output based on a format string.
 * @format: The format string with characters and conversion specifiers.
 * Return: The total number of characters printed.
 */


int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);

	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (handle_flags(*p, &flags))
				p++;

			pfunc = handle_formats(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}
