#include "main.h"

/**
 * _env - our own env command
 * @arg: parameter
 * @dynamic: dynamic refernce.
 * Return: always 0 on success
 */

int _env(char **arg, ref_t *dynamic)
{
	char *argVec[] = {"/bin/sh", "-c", "env", NULL};
	(void)arg;
	(void)dynamic;

	execve("/bin/sh", argVec, environ);
	return (0);
}
