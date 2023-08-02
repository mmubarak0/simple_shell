#include "main.h"

/**
  * main - Simple Shell:
  *		a simple unix like shell but functional and can
  *	handle file commands, builtins commands,
  *	handle ';', '||', '&&' and variable substitution.
  *	have `setenv`, `unsetenv`, `history` and `alias` commands.
  *
  * @argc: argument counter.
  * @argv: argument vector.
  *
  * Return: on Success (0).
  */
int main(int argc, char **argv)
{
	char **path = NULL;
	ref_t *ref = malloc(sizeof(ref_t));

	path = _tokenize(_getenv("PATH"), ":");
	/* ref_t *, cmd_num, ex_s, ac, fname, c_cmd, av, path */
	init_ref(ref, 0, 0, argc, NULL, NULL, argv, path);

	/* read and process commands */
	if (argc == 1)
	{
		while (1)
		{
			_readline(ref);
			_process(ref);
		}
	}
	else
	{
		ref->file_name = argv[1];
		/* process a file */
	}

	/* free ref */
	_free_ref(ref);

	return (EXIT_SUCCESS);
}
