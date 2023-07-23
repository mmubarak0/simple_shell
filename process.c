#include "main.h"

/**
  * process - process the input.
  * @path: path environment variable.
  */

void process(char **path)
{
	char *str = NULL, **args;
	size_t size = 1024;
	char buf[MAX_LENGTH];
	int found;
	pid_t child_pid;

	if (_getline(&str, &size, STDIN_FILENO) == -1)
		exit(98);

	args = _tokenize(str, " \t\r\n");

	found = check_cmd(args[0], path, buf);

	/* Test */
	if (found > 0)
	{
		switch (found)
		{
			case 1:
				/* call eval function */
				child_pid = fork();
				execute(child_pid, buf, args);
				break;
			case 2:
				built(args);
				break;
		}
	}
}
