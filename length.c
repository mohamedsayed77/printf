#include "main.h"

/**
* handle_length_modifier - Handles the length modifier in the format string.
* @p: A pointer to a pointer to the current position in the format string.
* @flags: A pointer to the flags structure.
*/

void handle_length_modifier(const char **p, flags_t *flags)
{
	if (**p == 'l' || **p == 'h')
	{
		flags->length = **p;
		(*p)++;
	}
}
