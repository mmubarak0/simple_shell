#include "main.h"

/**
  * print_strings - prints strings, followed by a new line.
  * -- Your are allowed to use printf
  * -- if separator is NULL don't print it
  * -- if one of strings is NULL print '(nil)' instead
  * -- print a new line at the end of your function
  * @separator: string to be printed between the strings.
  * @n: number of strings passed to the function.
  */
void print_strings(char *separator, unsigned int n, ...)
{
	unsigned int i;
	unsigned int d = n - 1;
	char *a;
	va_list args;

	/* Your code goes here */
	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		a = va_arg(args, char *);
		if (a != NULL)
			write(STDOUT_FILENO, a, _strlen(a));
		else
			write(STDOUT_FILENO, "(nil)", _strlen("(nil)"));

		if (separator != NULL && i != d)
			write(STDOUT_FILENO, separator, _strlen(separator));
	}
	write(STDOUT_FILENO, "\n", 2);

	va_end(args);
}
