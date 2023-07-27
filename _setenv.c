#include "main.h"

#define MAX_ARGS 3

/**
 * _setenv - our own setenv
 * @arg: user input
 * @dynamic: dynamic refrence.
 * Return: 0 on success, -1 on failure
 */

int _setenv(char **arg, ref_t *dynamic)
{
	char *new;
	int i, count = 0;

	(void)dynamic;
	if (arg[1] == NULL || arg[2] == NULL)
		return (-1);

	for (i = 0; arg[i]; i++)
		count++;

	if (count > MAX_ARGS)
		return (-1);

	new = malloc(_strlen(arg[1]) * _strlen(arg[2]) + 1);

	if (new == NULL)
	{
		perror("malloc");
		return (-1);
	}

	_strcpy(new, arg[1]);
	_strcat(new, "=");
	_strcat(new, arg[2]);


	if (putenv(new) == -1)
	{
		perror("putenv");
		return (-1);
	}

	free (new);
	return (0);
}
