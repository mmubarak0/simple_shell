#include "main.h"

/**
  * process - process the input.
  * @path: path environment variable.
  */
void process(char **path)
{
	char *str = NULL, **args;
	size_t size = 1024, i;
	char buf[MAX_LENGTH];
	int found;
	pid_t child_pid;

	if (getline(&str, &size, stdin) == -1)
		exit(98);

	args = _tokenize(str, " \t");
	/* Test */
	for (i = 0; args[i]; i++)
		printf("args[%ld]: %s\n", i, args[i]);
	/**
	 * decied wether built-in, alias, executable.
	 * execute()
	 **/
	found = check_cmd(args[0], path, buf);
	/* Test */
	if (found > 0)
	{
		child_pid = fork();
		execute(child_pid, buf);
	}
}
