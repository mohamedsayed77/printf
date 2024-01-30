#include "main.h"

/**
 * handle_flags - Check for flag modifiers in the format string
 * and activate corresponding flags.
 * @s: Flag specifier character.
 * @f: Pointer to flags structure for activation.
 *
 * Return: 1 if a flag is found and activated, else 0.
 */


int handle_flags(char s, flags_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;

		case ' ':
			f->space = 1;
			i = 1;
			break;

		case '#':
			f->hash = 1;
			i = 1;
			break;
	}
	return (i);
}

