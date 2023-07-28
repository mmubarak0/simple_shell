#include "main.h"

/**
  * execute - execute a command.
  * @pid: process id.
  * @command: the command to be executed.
  * @args: argument vector.
  */
void execute(pid_t pid, char *command, char **args)
{
	int status;

	if (pid == 0)
	{
		if (execve(command, args, environ) == -1)
			perror("can't run command");
	}
	else
	{
		/* parent process wait for child process */
		waitpid(pid, &status, 0);
		set_err_code(status % 10);
	}
}
