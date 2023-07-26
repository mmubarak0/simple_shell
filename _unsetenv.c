#include "main.h"

/**
 * _unsetenv - delete an environment variable
 * @arg: user input
 * Return: 0 on success, -1 on failure.
 */

int _unsetenv(char **arg)
{
	char *variable;

	variable = getenv(arg[1]);
	if (variable == NULL)
	{
		perror("getenv");
		return (-1);
	}
	*variable = '\0';

	return (0);
}
