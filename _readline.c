#include "main.h"

/**
  * _readline - read a line from standared input
  * @command_num: input numbers.
  * Return: input string.
  */
char *_readline(int *command_num)
{
	char *str = NULL;
	size_t size = 1024;
	ssize_t b = 1;

	while (b == 1)
	{
		write(STDOUT_FILENO, "$ ", 3);
		fflush(stdout);
		b = _getline(&str, &size, STDIN_FILENO);
		(*command_num)++;
	}
	if (b == -1)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
	else if (b == 0)
	{
		free(str);
		write(STDOUT_FILENO, "\n", 2);
		return (NULL);
	}
	return (str);
}
