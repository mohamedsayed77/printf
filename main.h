#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
* struct flags - Flags to enable when specific characters are passed to
* _printf().
* @zero: '0' character flag.
* @minus: '-' character flag.
* @plus: '+' character flag.
* @space: ' ' character flag.
* @hash: '#' character flag.
* @length: Length modifier flag.
* @width: Width specifier.
* @precision: Precision specifier.
*/

typedef struct flags
{
	int zero;
	int minus;
	int plus;
	int space;
	int hash;
	int length;
	int width;
	int precision;
} flags_t;

/**
* struct printHandler - Associates format specifiers with
* corresponding printing functions.
* @c: Format specifier character.
* @f: Pointer to the matching printing function.
*/

typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* _printf */
int _printf(const char *format, ...);

/* handle_alpha */
int handle_string(va_list l, flags_t *f);
int handle_char(va_list l, flags_t *f);
int handle_rot13(va_list l, flags_t *f);
int handle_rev(va_list l, flags_t *f);
int handle_bigS(va_list l, flags_t *f);

/* converter */
char *converter(unsigned long int num, int base, int lowercase);

/* handle_numbers */
int handle_int(va_list l, flags_t *f);
void print_positive_integer(int n);
int handle_unsigned(va_list l, flags_t *f);
int count_digits(int i);

/* handle_bases */
int handle_hex(va_list l, flags_t *f);
int handle_hex_upper(va_list l, flags_t *f);
int handle_binary(va_list l, flags_t *f);
int handle_octal(va_list l, flags_t *f);

/* handle_formats */
int (*handle_formats(char s))(va_list, flags_t *);

/* handle_flag */
void handle_flags(const char **p, flags_t *flags);

/* handle_width */
void handle_width(const char **p, va_list args, flags_t *flags);

/* handle_precision */
void handle_precision(const char **p, va_list args, flags_t *flags);

/* handle_length_modifier */
void handle_length_modifier(const char **p, flags_t *flags);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* handle_address */
int handle_address(va_list l, flags_t *f);

/* handle_percent */
int handle_percent(va_list l, flags_t *f);

#endif
