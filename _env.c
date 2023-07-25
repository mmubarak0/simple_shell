#include "main.h"

/**
 * _env - our own env command
 * @arg: parameter
 * Return: always 0 on success
 */

int _env(__attribute__((unused))char **arg)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		print_s(environ[i]);
		print_c('\n');
	}
	return (0);
}
