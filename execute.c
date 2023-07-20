#include "main.h"

/**
  * execute - execute a command.
  * @pid: process id.
  * @command: the command to be executed.
  */
void execute(pid_t pid, char *command)
{
	char *argVec[] = {NULL, NULL};
	char *envVec[] = {NULL};

	if (pid == 0)
	{
		argVec[0] = command;
		if (execve(command, argVec, envVec) == -1)
			perror("could not run the command!");
		printf("something went wrong!");
	}
	else
	{
		/* parent process */
		wait(NULL);
	}
}
