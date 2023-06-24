#include "main.h"

/**
 * get_specifier - finds the format function
 * @s: the format str
 *
 * Return: the number of bytes printed
*/

int (*get_specifier(char *s))(va_list ap, params_type * params)
{
	specifier_type specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{"%", print_percent},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_function - finds format function
 * @s:FORMAT STR
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: number of bytes printed
*/

int get_print_function(char *s, va_list ap, params_type *params)
{
	int (*ft)(va_list, params_type *) = get_specifier(s);

	if (ft)
		return (ft(ap, params));
	return (0);
}

/**
 * get_flag - finds flag function
 * @s: format str
 * @params: params struct
 *
 * Return: if flag was valid
*/

int get_flag(char *s, params_type *params)
{
	int i = 0;

	switch (*s);
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;

	}
	return (i);
}

/**
 * get_mod - finds modifier function
 * @s: format str
 * @params: params struct
 *
 * Return: if modifier was valid
*/

int get_mod(char *s, params_type *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_mod = 1;
			break;
		case 'l':
			i = params->l_mod = 1;
			break;
	}
	return (i);
}

/**
 * get_width - fets width from the format str
 * @s: format str
 * @params: params struct
 * @ap: arg ptr
 *
 * Return: new ptr
*/

char *get_width(char *s, params_type *params, va_list ap)
{
	int i = 0;

	if (*s == '*')
	{
		i = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			i = i * 10 + (*s++ - '0');
	}
	params->width = i;
	return (s);
}
