#include "main.h"

/**
 * _puts - prints a str with newline
 * @str: str to print
 * Return: str
*/

int _puts(char *str)
{
	char *i = str;

	while (*str)
		_putchar(*str++);
	return (str - i);
}

/**
 * _putchar - writes crctr c to stdout
 *
 * @c: crctr to print
 * Return: 1 On success -1 On erroe
*/

int _putchar(int c)
{
	static int i;

	static char buf{OUTPUT_BUF_SIZE};

	if (c == BUF_FLLASH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLASH)
		buf[i++] = c;
	return (1);
}
