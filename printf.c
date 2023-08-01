#include "main.h"

/**
  * id_select - iterate over the list of formats and
  * select a function to execute
  * @a: string to process
  * @args: argument list
  * @n: file descriptor.
  */
void id_select(const char *a, va_list args, int n)
{
	int i;
	id id_array[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'\0', NULL}
	};

	i = 0;
	while (id_array[i].type)
	{
		if (*a == id_array[i].type)
		{
			id_array[i].function(args, n);
			break;
		}
		i++;
	}
	if (id_array[i].type == '\0')
	{
		_putchar(*(a - 1), n);
		_putchar(*a, n);
	}
}

/**
  * _printf - function that produces output according to a format to STDOUT.
  * @format: is a character string.
  * The format string is composed of zero or more directives.
  * Return: the number of characters printed
  * (excluding the null byte used to end output to strings)
  */
int _printf(const char *format, ...)
{
	const char *a;
	int is_format;
	va_list args;

	if (format)
		a = format;
	else
		return (-1);
	va_start(args, format);
	while (*a)
	{
		is_format = (*a == '%') ? 1 : 0;
		if (is_format && *++a != '%')
			id_select(a, args, 1);
		else
		{
			_putchar(*a, 1);
		}
		a++;
	}
	va_end(args);
	return (0);
}

/**
  * _printe - function that produces output according to a format to STDERR.
  * @format: is a character string.
  * The format string is composed of zero or more directives.
  * Return: the number of characters printed
  * (excluding the null byte used to end output to strings)
  */
int _printe(const char *format, ...)
{
	const char *a;
	int is_format;
	va_list args;

	if (format)
		a = format;
	else
		return (-1);
	va_start(args, format);
	while (*a)
	{
		is_format = (*a == '%') ? 1 : 0;
		if (is_format && *++a != '%')
			id_select(a, args, 2);
		else
		{
			_putchar(*a, 2);
		}
		a++;
	}
	va_end(args);
	return (0);
}
