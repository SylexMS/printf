#include "main.h"

/**
 * print_char - prints crctr
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: number char prined
*/

int print_char(va_list ap, params_type *params)
{
	unsigned int pad = 1, sum = 0, c = va_arg(ap, int);
	char pad_c = ' ';

	if (params->minus_flag)
		sum += _putchar(c);
	while (pad++ < params->width)
		sum += _putchar(pad_c);
	if (!params->minus_flag)
		sum += _putchar(c);
	return (sum);
}

/**
 * print_int - prints int
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: number char printed
*/

int print_int(va_list ap, params_type *params)
{
	long l;

	if (params->l_mod)
		l = va_arg(ap, long);
	else if (params->h_mod)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - print str
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: number char printed
*/

int print_string(va_list ap, params_type *params)
{
	unsigned int pad = 0, sum = 0, i = 0, j;
	char *str = va_arg(ap, char *), pad_c = ' ';

	(void)params;
	switch ((int)(!str))
	case 1:
		str = NULL_STR;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UNIT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_c);
	if (!params->minus_flag)
	{
		if (params->precision != UNIT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - print str
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: number char printed
*/

int print_percent(va_list ap, params_type *params)
{
	(void)params;
	(void)ap;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: number char printed
*/

int print_S(va_list ap, params_type *params)
{
	int sum = 0;
	char *hex;
	char *str = va_arg(ap, char *);

	if ((int)(!str))
		return (_puts(NULLL_STR));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}

