#include "main.h"

/**
 * built - a function that handles the built-ins commands.
 * @args: user input tokenized as arguments.
 * @dynamic: dynamic reference.
 */
void built(char **args, ref_t *dynamic)
{
	size_t i;

	builts_cmd cmds[] = {
		{"exit", _ext},
		{"cd", _cd},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	i = 0;
	while (cmds[i].command_name)
	{

		if (_strcmp(args[0], cmds[i].command_name) == 0)
		{
			cmds[i].function(args, dynamic);
			break;
		}
		i++;
	}

}
