#include "main.h"

/**
  * inner_process - process the arguments.
  * @str: command to be processed.
  * @path: path array.
  * @pname: program name.
  * @command_num: command number.
  */
void inner_process(char *str, char **path, char *pname, int command_num)
{
	int found;
	char buf[MAX_LENGTH];
	char **args;

	args = _tokenize(str, " \t\r\n\0");
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
			cmd_not_found(pname, command_num, args[0]);
			fflush(stdout);
			break;
	}

}
/**
  * process - process the input.
  * @path: path environment variable.
  * @pname: shell name.
  * @isaty: is a tty ?
  */
void process(char **path, char *pname, int isaty)
{
	char *str = NULL, **args_all, **args_semi;
	int i, semi_len;
	int command_num = 0;

	str = _readline(&command_num, isaty);
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

/**
  * process_file - process the file content.
  * @path: path environment variable.
  * @pname: shell name.
  * @fname: file name.
  */
void process_file(char **path, char *pname, char *fname)
{
	char **args_all, *str = NULL;
	int i;
	int command_num = 0;

	str = read_textfile(fname, MAX_LENGTH);
	args_all = _tokenize(str, "\n");
	for (i = 0; args_all[i]; i++)
		inner_process(args_all[i], path, pname, command_num);
}
