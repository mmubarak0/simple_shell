#include "main.h"

/**
 * _env - our own env command
 * @arg: parameter
 * @dynamic: dynamic refernce.
 * Return: always 0 on success
 */

int _env(char **arg, ref_t *dynamic)
{
	int i, j, len = 0;
	
	(void)arg;
	(void)dynamic;


	for (len = 0; environ[len] != NULL; len++)
		continue;

	if (len <= 3)
		for (j = len - 1; j >= 0; j--)
		{
			print_s(environ[j], STDOUT_FILENO);
			if (j > 0)
				print_c('\n', STDOUT_FILENO);
		}
	else
		for (i = 0; environ[i]; i++)
		{
			print_s(environ[i], STDOUT_FILENO);
			print_c('\n', STDOUT_FILENO);
		}
	exit(0);
}
