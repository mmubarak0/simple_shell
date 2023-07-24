#include "main.h"

/**
  * eval - evaluates commands.
  * @command: command to be executed.
  * @args: arguments vector.
  */
void eval(char *command, char **args)
{
	pid_t child_pid;

	child_pid = fork();
	execute(child_pid, command, args);
}
