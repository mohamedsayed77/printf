#include "main.h"

/**
* handle_width - Handles the width specifier in the format string.
* @p: A pointer to a pointer to the current position in the format string.
* @args: The variable arguments list for fetching width values.
* @flags: A pointer to the flags structure for storing the width value.
*/

void handle_width(const char **p, va_list args, flags_t *flags)
{
	if (**p >= '1' && **p <= '9')
	{
		flags->width = atoi(*p);
		while (**p >= '0' && **p <= '9')
			(*p)++;
	}
	else if (**p == '*')
	{
		flags->width = va_arg(args, int);
		(*p)++;
	}
}
