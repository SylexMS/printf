#include "main.h"

/**
 * print_from_to_start - prints a range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @ex: except address
 *
 * Return: numbers of bytes printed
*/

int print_from_to_start(char *start, char *stop, char *ex)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != ex)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - prints str in reverse
 * @ap: str
 * @params: the params struct
 * Return: number of bytes printed
*/

int print_rev(va_list ap, params_type *params)
{
	int length, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (length = 0; *str; str++)
			length++;
		str--;
		for (; length > 0; length--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints str in rot13
 * @ap: str
 * @params: params struct
 *
 * Return: number bytes printed
*/

int print_rot13(va_list ap, params_type *params)
{
	int i, index, count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *c = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (c[i])
	{
		if ((c[i] >= 'A' && c[i] <= 'z') || (c[i] >= 'a' && c[i] <= 'z'))
		{
			index = c[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(c[i]);
		i++;
	}
	return (count);
}
