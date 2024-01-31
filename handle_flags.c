#include "main.h"

/**
* handle_flags - Check for flag modifiers in the format string
* and activate corresponding flags.
* @p: pointer Flag specifier character.
* @flags: Pointer to flags structure for activation.
*
*/


void handle_flags(const char **p, flags_t *flags)
{
	while (**p == '0' || **p == '-' || **p == '+' || **p == ' ')
	{
		if (**p == '0')
			flags->zero = 1;
		else if (**p == '-')
			flags->minus = 1;
		else if (**p == '+')
			flags->plus = 1;
		else if (**p == ' ')
			flags->space = 1;

		(*p)++;
	}
}
