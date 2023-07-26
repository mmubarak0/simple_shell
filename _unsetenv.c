#include "main.h"

/**
 * _unsetenv - delete an environment variable
 * @arg: user input
 * @dynamic: dynamic reference.
 * Return: 0 on success, -1 on failure.
 */

int _unsetenv(char **arg, ref_t *dynamic)
{
	char *variable;

	(void)dynamic;
	variable = getenv(arg[1]);
	if (variable == NULL)
	{
		perror("getenv");
		return (-1);
	}
	*variable = '\0';

	return (0);
}
