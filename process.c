#include "main.h"

/**
  * inner_process - process the arguments.
  */
void inner_process(char *str, char **path, char *pname, int command_num)
{
	int found;
	char buf[MAX_LENGTH];
	char **args;
	int i;

	args = _tokenize(str, " \t\r\n");
	found = check_cmd(args[0], path, buf);
	free(str);
	switch (found)
	{
		case 1:
			/* call eval function */
			eval(buf, args);
			break;
		case 2:
			built(args);
			break;
		default:
			printf("%s: %d: %s: not found\n", pname, command_num, args[0]);
			fflush(stdout);
			break;
	}
	/* -> free 1024, 39 bytes, 7 bytes: 3 record*/
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}
/**
  * process - process the input.
  * @path: path environment variable.
  * @pname: shell name.
  */
void process(char **path, char *pname)
{
	char *str = NULL, **args_all, **args_semi;
	int i, semi_len;
	int command_num = 1;

	str = _readline(&command_num);
	if (!str)
	{
		for (i = 0; path[i]; i++)
			free(path[i]);
		free(path);
		exit(0);
	}
	args_all = _tokenize(str, "#");
	args_semi = _tokenize(args_all[0], ";");
	for (semi_len = 0; args_semi[semi_len]; semi_len++)
		continue;
	if (semi_len > 1)
	{
		for (i = 0; args_semi[i]; i++)
			inner_process(args_semi[i], path, pname, command_num);
	}
	else
		inner_process(args_all[0], path, pname, command_num);
}
