#include "main.h"

/**
  * _readline - read input.
  * @ref: dynamic reference.
  */
void _readline(ref_t *ref)
{
	char *str = NULL;
	size_t size = BUFFER_SIZE;
	ssize_t n = 1;
	int i;

	do {
		if (isatty(STDIN_FILENO))
		{
			_printf("\033[0;32msimp\033[0m@0xPC:\033[0;33m%s\033[0m$ ", _getenv("PWD"));
			fflush(stdout);
		}
		n = _getline(&str, &size, STDIN_FILENO);
		if (n == -1)
			/* free memory before exit */
			exit(EXIT0x1);
		if (n == 0)
		{
			/* free memory before exit */
			printf("\n");
			fflush(stdout);
			exit(EXIT0x2);
		}
	} while (_empty_input(str));
	ref->current_command = _tokenize(str, "\n");
	for (i = 0; (ref->current_command)[i]; i++)
		;
	ref->command_number += i;
}

/**
  * _process - process input.
  * @ref: dynamic reference.
  */
void _process(ref_t *ref)
{
	int i;

	i = 0;
	while ((ref->current_command)[i])
	{
		ref->cmd_argv = _tokenize((
					_tokenize((ref->current_command)[i], "#"))[0], " \t\0"
				);
		if (!(ref->cmd_argv))
		{
			i++;
			continue;
		}
		switch (_check_command((ref->cmd_argv)[0], ref))
		{
			case 1:
				_execute_file_command(ref);
				break;
			case 2:
				_execute_builtin_command(ref);
				break;
			default:
				_printe("%s: %d: %s: not found\n", (ref->argv)[0]
						, ref->command_number, (ref->cmd_argv)[0]);
				break;
		}
		i++;
	}
}

/**
  * _check_command - check for command exsistance.
  * @command: command to search for.
  * @ref: dynamic reference.
  * Return:	< 0 if not found
  *		1 if file command
  *		2 if built-in command.
  */
int _check_command(char *command, ref_t *ref)
{
	int i;
	char *builtins[] = {"env", "exit", "setenv", "unsetenv",
		"cd", "alias", NULL};

	if (!command)
		return (-1);
	if (access(command, F_OK) == 0)
	{
		_memset(ref->cmd_buf, '\0', MAX_LENGTH);
		_strcpy(ref->cmd_buf, command);
		return (1);
	}

	i = 0;
	while (builtins[i])
	{
		if (_strcmp(builtins[i++], command) == 0)
		{
			_memset(ref->cmd_buf, '\0', MAX_LENGTH);
			_strcpy(ref->cmd_buf, command);
			return (2);
		}
	}

	if (ref->path == NULL)
		return (-1);
	i = 0;
	while ((ref->path)[i])
	{
		_memset(ref->cmd_buf, '\0', MAX_LENGTH);
		_strcpy(ref->cmd_buf, (ref->path)[i]);
		_strcat(ref->cmd_buf, "/");
		_strcat(ref->cmd_buf, command);
		if (access(ref->cmd_buf, F_OK) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
  * _free_ref - free dynamic reference.
  * @ref: dynamic reference.
  */
void _free_ref(ref_t *ref)
{
	_buffer_free(ref->path);
	_buffer_free(ref->current_command);
}
