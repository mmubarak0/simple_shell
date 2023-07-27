#include "main.h"

/**
 * print_c - print a character.
 * @c: character to print
 * Return: length of the variable or -1
 */
int print_c(char c, int file_no)
{
	return (_putchar(c, file_no));
}

/**
 * print_s - print a string
 * @s: string to be printed
 * Return: length of the variable or -1
 */
int print_s(char *s, int file_no)
{
	int i = 0;

	if (s == NULL)
		return (-1);
	while (s[i])
	{
		_putchar(s[i], file_no);
		i++;
	}
	return (i);
}

/**
 * print_d - print an integer
 * @d: number to be printed
 * Return: length of the variable or -1
 */
int print_d(long d, int file_no)
{
	char *dtos;
	int i = 0;

	dtos = _dtos(d);
	while (dtos[i])
	{
		_putchar(dtos[i], file_no);
		i++;
	}
	free(dtos);
	return (i);
}
