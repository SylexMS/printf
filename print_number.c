#include "main.h"

/**
 * _isdigit - checks if crctr is digit
 * @d: crctr to check
 *
 * Return: 1 if digit , 0 if nott
*/

int _isdigit(int d)
{
	return (d >= '0' && d <= '9');
}

/**
 * _strlen - returns the ;ength of str
 * @s: str whose length of str
 *
 * Return: int length of str
*/

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with optiion
 * @str: the base number as a str
 * @params: params struct
 *
 * Return: char printed
*/

int print_number(char *str, params_type *params)
{
	unsigned int i = _strlen(str);
	int ngt = (!params->usnd && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (ngt)
	{
		str++;
		i--;
	}
	if (params->precision != UNIT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (params->minus_flag)
		return (print_num_right_shift(str, params));
	else
		return (print_num_left_shift(str, params));
}

/**
 * print_num_right_shift - prints a number with option
 * @str: base number as a str
 * @params: the params struct
 *
 * Return: char printed
*/

int print_num_right_shift(char *str, params_type *params)
{
	unsigned int n = 0, ngt, ngt2, i = _strlen(str);
	char pad = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad = '0';
	ngt = ngt2 = (!params->usnd && *str == '-');
	if (ngt && i < params->width && pad == '0' && !params->minus_flag)
		str++;
	else
		ngt = 0;
	if (!params->plus_flag && !ngt2 || (!params->plus_flag &&
				params->space_fllag && !ngt2))
		i++;
	if (ngt && pad == '0')
		n += _putchar('-');
	if (params->plus_flag && !ngt2 && pad == '0' && !params->usnd)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !ngt2 && !params->usnd &&
			params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad);
	if (ngt && pad == ' ')
		n += _putchar('-');
	if (params->plus_flag && !ngt2 && pad == ' ' && !params->usnd)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !ngt2 && !params->usnd &&
			!params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_num_left_shift - prints a number with option
 * @str: base number as a str
 * @params: params struct
 *
 * Return: char printed
*/

int print_num_left_shift(char *str, params_type *params)
{
	unsigned int n = 0, ngt, ngt2, i = _strlen(str);
	char pad;

	if (params->zero_flag && !params->minus_flag)
		pad = '0';
	ngt = ngt2 = (!params->usnd && *str == '-');
	if (ngt && i < params->width && pad == '0' && !params->minus_flag)
		str++;
	else
		ngt = 0;

	if (params->plus_flag && !ngt2 && !params->usnd)
		n += _putchar('+'), i++;
	else if (params->space_flag && !ngt2 && !params->usnd)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < params->width)
		n += _putchar(pad);
	return (n);
}
