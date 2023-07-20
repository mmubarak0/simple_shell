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
	char *path_buf, **path;

	path_buf = getpath();
	if (!path_buf)
		exit(98);
	path = _tokenize2(path_buf, ":");
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{

			write(STDOUT_FILENO, "$ ", 3);
			process(path);
		}
	}
	else
		process(path);

	return (0);
}
