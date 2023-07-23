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
	path = _tokenize(path_buf, ":");
	if (isatty(STDIN_FILENO))
	{
		while (1)
			process(path, argv[0]);
	}
	else
		process(path, argv[0]);

	return (0);
}
