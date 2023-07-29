#include "main.h"

/**
 * built - a function that handles the built-ins commands.
 * @args: user input tokenized as arguments.
 * @dynamic: dynamic reference.
 * @pname: program name.
 */
void built(char **args, ref_t *dynamic, char *pname)
{
	size_t i, j;

	builts_cmd cmds[] = {
		{"exit", _ext},
		{"cd", _cd},
		{"env", _env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};

	for (i = 0; cmds[i].command_name; i++)
		for (j = 0; args[j]; j++)
			if (_strcmp(args[j], cmds[i].command_name) == 0)
				cmds[i].function(args, dynamic, pname);
}
