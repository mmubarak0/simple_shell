#include "main.h"

/**
  * process - process the input.
  * @path: path environment variable.
  * @pname: shell name.
  */

void process(char **path, char *pname)
{
	char *str = NULL, **args;
	char buf[MAX_LENGTH];
	int found, i;
	int command_num = 1;

	str = _readline(&command_num);
	if (!str)
	{
		for (i = 0; path[i]; i++)
			free(path[i]);
		free(path);
		exit(0);
	}
	args = _tokenize(str, " \t\r\n");
	found = check_cmd(args[0], path, buf);
	free(str);

	/* Test */
	switch (found)
	{
		case 1:
			/* call eval function */
			eval(buf, args);
			break;
		case 2:
			built(args);
			break;
		default:
			printf("%s: %d: %s: not found\n", pname, command_num, args[0]);
			fflush(stdout);
			break;
	}
	/* -> free 1024, 39 bytes, 7 bytes: 3 record*/
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}
