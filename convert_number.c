#include "main.h"

/**
 * print_hex - prints unsigned hex numb in lowercase
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: bytes printed
*/

int print_hex(va_list ap, params_type *params)
{
	unsigned long l;
	int s = 0;
	char *str;

	if (params->l.mod)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h.mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LLOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->usnd = 1;
	return (s += print_number(str, params));
}

/**
 * print_HEX - prints unsigned hex number in uppercase
 * @ap: arg ptr
 * @params: params struct
 * Return: bytes printed
*/

int print_HEX(va_list ap, params_type *params)
{
	unsigned long l;
	int s = 0;
	char *str;

	if (params->l.mod)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h.mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);

	str = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->usnd = 1;
	return (s += print_number(str, params));
}

/**
 * print_binary - prints usnd binary number
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: bytes printed
*/

int print_binary(va_list ap, params_type *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, CONVERT_UNSIGNED, params);
	int s = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	param->usnd = 1;
	return (s += print_number(str, params));
}

/**
 * print_octal - prints usnd octal numbers
 * @ap: arg ptr
 * @params:params struct
 *
 * Return: bytes printed
*/

int print_octal(va_list ap, params_type *params)
{
	unsigned long l;
	char *str;
	int s = 0;

	if (params->l_mod)
		l = (unsigned long)va_arg(ap. unsigned long);
	else if (params->h_mod)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	str = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--str = '0';
	params->usnd = 1;
	return (s += print_number(str, params));
}
