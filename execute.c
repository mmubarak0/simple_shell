#include "main.h"

/**
  * execute - execute a command.
  * @pid: process id.
  * @command: the command to be executed.
  */
void execute(pid_t pid, char *command, char **args)
{
	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
			perror("could not run the command!");
	}
	else
	{
		/* parent process wait for child process */
		wait(NULL);
	}
}
