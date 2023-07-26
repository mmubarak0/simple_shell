#include "main.h"

int _isdigit(int c);

/**
 * _ext - our own exit built-in command
 * @arg: parameter to hold user input
 * Return: Always 0
 */

int _ext(char **arg)
{
	int i = 0;
	int status = 0;

	if (arg[1])
	{
		if (arg[1][0] == '-')
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", arg[1]);
			exit(2);
		}
		while (arg[1][i])
		{
			if (_isdigit(arg[1][i]) == -1)
			{
				fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", arg[1]);
				exit(2);
			}
			i++;
		}
		status = _atoi(arg[1]);
	}
	exit(status);
}

/**
 * _isdigit - checks digit.
 * @c: input to be checked.
 * Return: 0 on success, -1 on failure
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else
		return (-1);
}
