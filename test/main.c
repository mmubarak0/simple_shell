#include "main.h"
#include "findcmd.h"

/**
 * main - Entry Point
 * @argc: arguments count.
 * @argv: arguments string.
 * @env: environment variables.
 * Return: 0 on Success
 */

int main(__attribute__((unused))int argc,
		__attribute__((unused))char *argv[], __attribute__((unused))char **env)
{
	char *str = NULL, **args;
	size_t size = 1024;

	if (isatty(STDIN_FILENO))
		while (1)
		{

			write(STDOUT_FILENO, "$ ", 3);
			if (getline(&str, &size, stdin) == -1)
				exit(98);

			args = tokenize(str, " ", size);

			/**
			 * decied wether built-in, alias, executable.
			 * execute()
			 **/
			if (check_cmd(args[0], env) != -1)
				printf("hi");
		}

	else
		return (98);

	return (0);
}
