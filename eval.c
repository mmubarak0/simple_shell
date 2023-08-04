#include "main.h"

/**
  * _execute_file_command - execute file commands.
  * @ref: dynamic reference.
  */
void _execute_file_command(ref_t *ref)
{
	pid_t child_pid;
	int status = 0;

	/* create new process */
	child_pid = fork();

	if (child_pid == 0)
	{
		if (execve(ref->cmd_buf, ref->cmd_argv, ref->env) == -1)
			perror("can't run command!");
	}
	else
	{
		waitpid(child_pid, &status, 0);
		ref->exit_status = WEXITSTATUS(status);
	}
}

/**
  * _execute_builtin_command - execute builtins commands.
  * @ref: dynamic reference.
  */
void _execute_builtin_command(ref_t *ref)
{
	int i;

	printf("command = %s", ref->cmd_buf);
	for (i = 1; (ref->cmd_argv)[i]; i++)
		printf(" %s", (ref->cmd_argv)[i]);
	printf("\n");
}
