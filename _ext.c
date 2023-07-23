#include "main.h"

/**
 * _ext - our own exit built-in command
 * @arg: parameter to hold user input
 * Return: Always 0
 */

int _ext(__attribute__((unused))char **arg)
{
	int status = 0;

	if(arg[1])
		status = atoi(arg[1]);
	
	exit(status);
}

