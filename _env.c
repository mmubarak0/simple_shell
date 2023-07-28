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

	for (i = 0; environ[i]; i++)
	{
		print_s(environ[i], STDOUT_FILENO);
		print_c('\n', STDOUT_FILENO);
	}
	set_err_code(0);

	return (0);
}
