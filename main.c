#include "main.h"

/**
 * main - Entry Point
 * @argc: arguments count.
 * @argv: arguments string.
 * Return: 0 on Success
 */

int main(int argc, char *argv[])
{
	char *path_buf, **path = NULL;

	path_buf = getpath();
	if (path_buf)
		path = _tokenize(path_buf, ":");
	if (argc == 1)
	{
		if (isatty(STDIN_FILENO))
		{
			while (1)
			{
				process(path, argv[0], 1);
			}
			if (path)
				free_buf(path);
		}
		else
		{
			process(path, argv[0], 0);
			if (path)
				free_buf(path);
		}

	}
	else if (argc == 2)
	{
		/* execute file commands */
		process_file(path, argv[0], argv[1]);
		if (path)
			free_buf(path);
	}

	return (get_err_code());
}
