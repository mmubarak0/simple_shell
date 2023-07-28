#include "main.h"

/**
  * check_cmd - check for command exsistance.
  * @command: command to search for.
  * @path: a list of strings contan the value of PATH.
  * @buf: the buffer to save the path of file commands
  * Return:	0 if not found
  *		1 if file command
  *		2 if built-in command.
  */
int check_cmd(char *command, char **path, char *buf)
{
	int i;
	char *builtins[] = {"env", "exit", "setenv", "unsetenv",
		"cd", "alias", NULL};

	if (!command)
		return (-1);
	if (access(command, F_OK) == 0)
	{
		_memset(buf, '\0', MAX_LENGTH);
		_strcpy(buf, command);
		return (1);
	}

	i = 0;
	while (builtins[i])
	{
		if (_strcmp(builtins[i++], command) == 0)
		{
			_memset(buf, '\0', MAX_LENGTH);
			_strcpy(buf, command);
			return (2);
		}
	}

	if (path == NULL)
		return (-1);
	i = 0;
	while (path[i])
	{
		_memset(buf, '\0', MAX_LENGTH);
		_strcpy(buf, path[i]);
		_strcat(buf, "/");
		_strcat(buf, command);
		if (access(buf, F_OK) == 0)
			return (1);
		i++;
	}
	return (0);
}
