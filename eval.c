#include "main.h"

/**
  * eval - evaluates commands.
  * @command: command to be executed.
  * @args: arguments vector.
  */
void eval(char *command, char **args)
{
	pid_t child_pid;
	char *c2;
	int i;

	i = 0;
	while (args[i])
	{
		if (_strchr(args[i], '#') != NULL)
		{
			args[i] = NULL;
			break;
		}
		c2 = _strchr(args[i], ';');
		if (c2 != NULL)
			printf("%s\n", c2);
		i++;
	}
	child_pid = fork();
	execute(child_pid, command, args);
}
