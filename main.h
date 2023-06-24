#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLASH -1

#define NULL_STR "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - struct prmters
 * @unsd: flag if unsigned value
 *
 * @plus_flag: on if plus flag specified
 * @space_flag: space
 * @hashtag_flag: #
 * @zero_flag: 0
 * @minus_flag: -
 *
 * @width: field width 
 * @precision: field precision
 *
 * @h_mod: H
 * @l_mod: L
*/

typedef struct parameters
{
	unsigned int usnd		: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_mod		: 1;
	unsigned int l_mod		: 1;
} params_type;

/**
 * struct specifier - struct token
 *
 * @specifier: format
 * @ft: function associated
*/

typedef struct specifier
{
	char *specifier;
	int (*ft)(va_list, params_type *);
} specifier_type

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int print_char(va_list ap, params_type *params);
int print_int(va_list ap, params_type *params);
int print_string(va_list ap, params_type *params);
int print_percent(va_list ap, params_type *params);
int print_S(va_list ap, params_type *params);

/* number.c module */
char *convert(long int num, int base, int flag, params_type *params);
int print_unsd(va_list ap, params_type *params);
int print_address(va_list ap, params_type *params);

/* specifier.c module */
int (*get_specifier(char *s))(va_list ap, params_type *params);
int get_print_function(char *s, va_list ap, params_type *params);
int get_flag(char *s, params_type *params);
int get_mod(char *s, params_type *params);
char *get_width(char *s, params_type *params, va_list ap);

/* convert_number.c module */
int print_hex(va_list ap, params_type *params);
int print_HEX(va_list ap, params_type *params);
int print_binary(va_list ap, params_type *params);
int print_octal(va_list ap, params_type *params);

/* simple_printers.c module */
int print_from_to_start(char *start, char *stop, char *ex);
int print_rev(va_list ap, params_type *params);
int print_rot13(va_list ap, params_type *params);

/* print_number.c module */
int _isdigit(int d);
int _strlen(char *s);
int print_number(char *str, params_type *params);
int print_num_right_shift(char *str, params_type *params);
int print_num_left_shift(char *str, params_type *params);

/* params.c module */
void init_params(params_type *params, va_list ap);

/* string_field.c module */
char *get_precision(char *ptr, params_type, va_list ap);

/* _printf.c module */
int _printf(const char *format, ...);

#endif
