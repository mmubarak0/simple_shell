#include "main.h"

/**
 * _ext - our own exit built-in command
 * @arg: parameter to hold user input
 * Return: Always 0
 */
int _ext(char **arg)
{
	int status = 0;

	if (arg[1])
		status = _atoi(arg[1]);

	exit(status);
}

