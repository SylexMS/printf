#include "main.h"

/**
 * convert - convert function a clone of itoa
 * @num: number
 * @base: base
 * @flag: arg flag
 * @params: params srtuct
 *
 * Return: str
*/

char *convert(long int num, int base, int flag, params_type *params)
{
	static char *arr;
	static char buff[50];
	char sign, *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = num;
		sign = '-';
	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do {
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsd - prints unsigned int number
 * @ap: arg ptr
 * @params: params struct
 *
 * Return: bytes printed
*/

int print_usnd(va_list ap, params_type *params)
{
	unsigned long 1;

	if (params->l_mod)
		1 = (unsigned long)va_arg(ap, unsigned int);
	else if (params->h_mod)
		1 = (unsigned short int)va_arg(ap, unsigned int);
	else
		1 = (unsigned int)va_arg(ap, unsigned int);
	params->usnd = 1;
	return (print_number(convert(1, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints address
 * @ap: arg ptr
 * @params: params struct
 * Return: bytes printed
*/

int print_address(va_list ap, params_type *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
