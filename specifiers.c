#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * @n: 1 STDOUT, 2 STDERR.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c, int n)
{
	return (write(n, &c, 1));
}

/**
 * print_c - print a character.
 * @args: character to print
 * @n: 1 STDOUT, 2 STDERR.
 * Return: length of the variable or -1
 */
int print_c(va_list args, int n)
{
	char c;

	c = va_arg(args, int);
	return (_putchar(c, n));
}

/**
 * print_s - print a string
 * @args: string to be printed
 * @n: 1 STDOUT, 2 STDERR.
 * Return: length of the variable or -1
 */
int print_s(va_list args, int n)
{
	char *s;
	int i = 0;

	s = va_arg(args, char *);
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		_putchar(s[i], n);
		i++;
	}
	return (i);
}

/**
 * print_d - print an integer
 * @args: number to be printed
 * @n: 1 STDOUT, 2 STDERR.
 * Return: length of the variable or -1
 */
int print_d(va_list args, int n)
{
	long d;
	char *dtos;
	int i = 0;

	d = va_arg(args, int);
	dtos = _dtos(d);
	while (dtos[i])
	{
		_putchar(dtos[i], n);
		i++;
	}
	free(dtos);
	return (i);
}
