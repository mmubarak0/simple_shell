#include "main.h"

int _set(char *name, char *value, ref_t *dynamic);

/**
 * _cd - our own cd command
 * @arg: parameter
 * @dynamic: struct
 * Return: Always 0 on success, -1 on failure.
 */

int _cd(char **arg, ref_t *dynamic)
{
	int change;
	char *current = NULL;


	current = getcwd(current, 1024);

	if (arg[1] == NULL)
	{
		change = chdir(_getenv("HOME"));
		if (change == -1)
			return (-1);

		_set("OLDPWD", current, dynamic);
		current = getcwd(current, 1024);
		_set("PWD", current, dynamic);
	}

	if (arg[1])
	{
		if (_strcmp(arg[1], "-") == 0)
		{
			if (_getenv("OLDPWD") == NULL)
			{
				change = chdir(_getenv("HOME"));
				if (change == -1)
					return (-1);

				_set("OLDPWD", current, dynamic);
				current = getcwd(current, 1024);
				_set("PWD", current, dynamic);
			}
			else
			{
				change = chdir(_getenv("OLDPWD"));
				if (change == -1)
					return (-1);

				_set("OLDPWD", current, dynamic);
				current = getcwd(current, 1024);
				_set("PWD", current, dynamic);
			}
		}
		else
		{
			change = chdir(arg[1]);
			if (change == -1)
				return (-1);

			_set("OLDPWD", current, dynamic);
			current = getcwd(current, 1024);
			_set("PWD", current, dynamic);
		}

	}

	free(current);
	free(dynamic->ptr4);
	set_err_code(0);
	return (0);

}

/**
 * _set - a modified version of setenv, to handle hcanging PWD, OLDPWD
 * @name: name of the variable.
 * @value: the value that should contain in the name.
 * Return: 0 on success, -1 on failure
 **/

int _set(char *name, char *value, ref_t *dynamic)
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

	dynamic->ptr4 = new;
	free(name);
	free(value);
	return (0);
}
