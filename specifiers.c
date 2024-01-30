#include "main.h"


/**
 * handle_formats - Identifies the appropriate printing function
 * based on the conversion specifier provided to _printf
 * @s: The character holding the conversion specifier
 *
 * Description: This function iterates through the array of structs,
 * Once a match is found, it returns a pointer to
 * the corresponding printing function.
 *
 * Return: A pointer to the matched printing function
 */


int (*handle_formats(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', handle_int},
		{'s', handle_string},
		{'c', handle_char},
		{'d', handle_int},
		{'u', handle_unsigned},
		{'x', handle_hex},
		{'X', handle_hex_upper},
		{'b', handle_binary},
		{'o', handle_octal},
		{'R', handle_rot13},
		{'r', handle_rev},
		{'S', handle_bigS},
		{'p', handle_address},
		{'%', handle_percent}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
	if (func_arr[i].c == s)
		return (func_arr[i].f);

	return (NULL);
}
