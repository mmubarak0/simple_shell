#include "main.h"

/**
 * _env - our own env command
 * @arg: parameter
 * @dynamic: dynamic refernce.
 * Return: always 0 on success
 */

int _env(char **arg, ref_t *dynamic)
{
	int i;

	(void)arg;
	(void)dynamic;


	if (environ == NULL)
		return (-1);

	for (i = 0; copy[i]; i++)
	{
		write(STDOUT_FILENO, copy[i], _strlen(copy[i]));
		write(STDOUT_FILENO, "\n", 2);
	}

	return (0);
}
