#include "main.h"

/**
 * _setenv - our own setenv;
 * @arg: usr input
 * @dynamic: struct
 * Return: 0 on success.
 */

int _setenv(char **arg, ref_t *dynamic)
{
	int pos;
	char *new;
	(void)dynamic;

	for (pos = 0; arg[pos] != NULL; pos++)
		if (_strcmp(arg[pos], "setenv") == 0)
			break;

	if (arg[pos + 1] == NULL || arg[pos + 2] == NULL)
		return (-1);

	new = malloc(_strlen(arg[pos + 1]) * _strlen(arg[pos + 2]) + 3);

	if (new == NULL)
	{
		perror("malloc");
		return (-1);
	}

	_strcpy(new, arg[pos + 1]);
	_strcat(new, "=");
	_strcat(new, arg[pos + 2]);

	if (putenv(new) == -1)
		return (-1);
	return (0);
}
