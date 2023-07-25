#include "main.h"

char *_path(char **arg);

/**
 * _cd - our own cd command
 * @arg: parameter
 * Return: Always 0 on success, -1 on failure.
 */

int _cd(char **arg)
{
	char cwd[1024], *dir;
	int change = 0;


	if (getcwd(cwd, 1024) == NULL)
	{
		perror("getcwd");
		exit(-1);
	}

	dir = _dir(arg);
	change = chdir(dir);

	if (change == -1)
	{
		perror("chdir");
		exit(-1);
	}

	/**
	 * in need to create the _setenv function
	 * ** to implement the "-" feature.
	 */

	return (0);
}

/**
 * _path - a help function checks the path input from user.
 * @arg: parameter for user input.
 * Return: the Path.
 */

char *_path(char **arg)
{

	if (arg[1] == NULL)
		return (getenv("HOME"));
	else
		return (arg[1]);
	/**
	 * else the argv[1] == "-".
	 */
}
