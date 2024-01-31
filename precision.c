#include "main.h"

/**
* handle_precision - Handles the precision specifier in the format string.
* @p: A pointer to a pointer to the current position in the format string.
* @args: The variable arguments list for fetching precision values.
* @flags: A pointer to the flags structure for storing the precision value.
*
*/

void handle_precision(const char **p, va_list args, flags_t *flags)
{
	if (**p == '.')
	{
		(*p)++;
		if (**p >= '0' && **p <= '9')
		{
			flags->precision = atoi(*p);
			while (**p >= '0' && **p <= '9')
			(*p)++;
		}
		else if (**p == '*')
		{
			flags->precision = va_arg(args, int);
			(*p)++;
		}
	}
}
