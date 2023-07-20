#include "main.h"

/**
  * check_cmd - check for command exsistance.
  * @command: command to search for.
  * @path: a list of strings contan the value of PATH.
  * Return:	0 if not found
  *		1 if built-in command.
  *		2 if file command
  */
int check_cmd(char *command, char **path)
{
	int i;
	char buf[MAX_LENGTH];
	char *builtins[] = {"env", NULL};

	if (access(command, F_OK) == 0)
		return (1);

	i = 0;
	while (builtins[i])
		if (_strcmp(builtins[i++], command) == 0)
			return (0);

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
