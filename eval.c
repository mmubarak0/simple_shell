#include "main.h"

/**
  * _execute_file_command - execute file commands.
  * @ref: dynamic reference.
  */
void _execute_file_command(ref_t *ref)
{
	int i;

	printf("command = %s", ref->cmd_buf);
	for (i = 1; (ref->cmd_argv)[i]; i++)
		printf(" %s", (ref->cmd_argv)[i]);
	printf("\n");
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
