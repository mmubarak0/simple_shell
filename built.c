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


	for (i = 0; i < sizeof(cmds); i++)
		if (_strcmp(args[0], cmds[i].command_name) == 0)
			cmds[i].function(args);
}
