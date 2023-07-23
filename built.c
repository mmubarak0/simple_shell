#include "main.h"

/**
 * built - a function that handles the built-ins commands.
 * @args: user input tokenized as arguments.
 */
void built(char **args)
{
	size_t i;

	builts_cmd cmds[] = {
		{"exit", _ext},
		{NULL, NULL}
	};

	i = 0;
	while (cmds[i].command_name)
	{
		if (_strcmp(args[0], cmds[i].command_name) == 0)
		{
			cmds[i].function(args);
			break;
		}
		i++;
	}
}
