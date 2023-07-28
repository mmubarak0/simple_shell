#include "main.h"

/**
  * _readline - read a line from standared input
  * @command_num: input numbers.
  * @isaty: is a tty ?
  * @dynamic: dynamic reference.
  * Return: input string.
  */
char *_readline(int *command_num, int isaty, ref_t *dynamic)
{
	char *str = NULL;
	size_t size = BUFFER_SIZE;
	ssize_t b = 1;

	while (b == 1 || (str && str[0] == '#'))
	{
		if (isaty)
		{
			write(STDOUT_FILENO, "$ ", 3);
			fflush(stdout);
		}
		b = _getline(&str, &size, STDIN_FILENO);
		(*command_num)++;
	}
	if (b == -1)
	{
		free(str);
		free_buf(dynamic->ptr3);
		free(dynamic);
		exit(get_err_code());
	}
	else if (b == 0) /* CTRL+D Handler */
	{
		free(str);
		write(STDOUT_FILENO, "\n", 2);
		free_buf(dynamic->ptr3);
		free(dynamic);
		exit(get_err_code());
	}
	return (str);
}
