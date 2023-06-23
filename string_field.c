#include "main.h"

/**
 * get_precision - gets the precision from the format str
 * @ptr: format str
 * @params_type: params struct
 * @ap: arg
 *
 * Return: new ptr
*/

char *get_precision(char *ptr, params_type, va_list ap)
{
	int i = 0;

	if (*ptr != '.')
		return (ptr);
	ptr++;
	if (*ptr == '*')
	{
		i = va_arg(ap, int);
		ptr++;
	}
	else
	{
		while (_isdigit(*ptr))
			i = i * 10 + (*ptr++ - '0');
	}
	params->precision = i;
	return (ptr);
}
