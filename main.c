#include "main.h"

/**
 * main - Entry Point
 * @argc: arguments count.
 * @argv: arguments string.
 * Return: 0 on Success
 */

int main(__attribute__((unused))int argc,
		__attribute__((unused))char *argv[])
{
	char *str = NULL, **args;
	size_t size = 1024, i;
	list_t *path;

	if (isatty(STDIN_FILENO))
	{
		path = getpath();
		while (1)
		{

			write(STDOUT_FILENO, "$ ", 3);
			if (getline(&str, &size, stdin) == -1)
				exit(98);

			args = _tokenize(str, " ");
			/* Test */
			for (i = 0; args[i]; i++)
				printf("args[%ld]: %s\n", i, args[i]);

			/**
			 * decied wether built-in, alias, executable.
			 * execute()
			 **/
			if (check_cmd(args[0], env) != -1)
				printf("hi");
		}
	}
	else
		return (98);

	return (0);
}
