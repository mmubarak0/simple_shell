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
		printf("%s\n", environ[i]);
	return (0);
}
