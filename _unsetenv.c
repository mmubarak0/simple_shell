#include "main.h"

/**
 * _unsetenv - delete an environment variable
 * @arg: user input
 * @dynamic: dynamic reference.
 * @pname: program name.
 * Return: 0 on success, -1 on failure.
 */

int _unsetenv(char **arg, ref_t *dynamic, char *pname)
{
	int pos;
	char *variable;

	(void)dynamic;
	(void)pname;

	for (pos = 0; arg[pos] != NULL; pos++)
		if (_strcmp(arg[pos], "unsetenv") == 0)
			break;

	variable = getenv(arg[pos + 1]);
	if (variable)
		*variable = '\0';
	else
		return (-1);

	return (0);
}
