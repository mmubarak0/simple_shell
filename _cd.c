#include "main.h"

char *_path(char **arg);
int _set(char *name, char *value);

/**
 * _cd - our own cd command
 * @arg: parameter
 * @dynamic: struct
 * Return: Always 0 on success, -1 on failure.
 */

int _cd(char **arg, __attribute__((unused))ref_t *dynamic)
{
	char cwd[1024], *dir;
	int change = 0;


	if (getcwd(cwd, 1024) == NULL)
	{
		perror("getcwd");
		return (-1);
	}

	dir = _path(arg);
	if (dir == NULL)
		return (-1);

	change = chdir(dir);

	if (change == -1)
	{
		perror("chdir");
		return (-1);
	}


	/* -> Update PWD, OLDPWD */
	if (_set("PWD", dir) == -1)
		return (-1);

	if (_set("OLDPWD", cwd) == -1)
		return (-1);

	set_err_code(0);
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
		return (_getenv("HOME"));
	else if (_strcmp(arg[1], "-") == 0)
	{

		if (_getenv("OLDPWD") == NULL)
			return (NULL);
		else
			return (_getenv("OLDPWD"));
	}
	else
		return (arg[1]);
}


/**
 * _set - a modified version of setenv, to handle hcanging PWD, OLDPWD
 * @name: name of the variable.
 * @value: the value that should contain in the name.
 * Return: 0 on success, -1 on failure
 */

int _set(char *name, char *value)
{
	char *new;

	new = malloc(_strlen(name) + _strlen(value) + 2);
	if (new == NULL)
		return (-1);

	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);

	if (putenv(new) == -1)
		perror("putenv");
	free(new);
	return (0);
}
