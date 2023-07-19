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

	if (access(command, F_OK) == 0)
		return (1);
	/*
	*else
	*	return (0);  check for built in command
	*/

	i = 0;
	while (path[i])
	{
		memset(buf, '\0', MAX_LENGTH);
		strcpy(buf, path[i]);
		strcat(buf, "/");
		strcat(buf, command);
		if (access(buf, F_OK) == 0)
			return (1);
		i++;
	}
	return (0);
}
