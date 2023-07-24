#include "main.h"

/**
  * process - process the input.
  * @path: path environment variable.
  * @pname: shell name.
  */

void process(char **path, char *pname)
{
	char *str = NULL, **args;
	size_t size = 1024;
	char buf[MAX_LENGTH];
	int found, i;
	int command_num = 1;
	ssize_t b = 1;
	pid_t child_pid;

	while (b == 1)
	{
		write(STDOUT_FILENO, "$ ", 3);
		fflush(stdout);
		b = _getline(&str, &size, STDIN_FILENO);
		command_num++;
	}
	if (b == -1)
		exit(EXIT_FAILURE);
	else if (b == 0)
	{
		write(STDOUT_FILENO, "\n", 2);
		exit(getpid());
	}
	args = _tokenize(str, " \t\r\n");
	found = check_cmd(args[0], path, buf);

	/* Test */
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
		default:
			printf("%s: %d: %s: not found\n", pname, command_num, args[0]);
			fflush(stdout);
			break;
	}
	/* -> free 1024, 39 bytes, 7 bytes: 3 record*/	
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	free(str);
}
