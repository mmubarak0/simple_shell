#include "main.h"

/**
  * inner_process - process the arguments.
  * @str: command to be processed.
  * @path: path array.
  * @pname: program name.
  * @command_num: command number.
  * @dynamic: dynamic reference.
  */
void inner_process(char *str, char **path, char *pname,
		int command_num, ref_t *dynamic)
{
	int found;
	char buf[MAX_LENGTH];
	char **args;

	args = _tokenize(str, " \t\r\n\0");
	found = check_cmd(args[0], path, buf);
	switch (found)
	{
		case 1:
			/* call eval function */
			eval(buf, args);
			if (dynamic->ptr1)
				free_buf(dynamic->ptr1);
			if (dynamic->ptr2)
				free_buf(dynamic->ptr2);
			free(dynamic);
			if (args)
				free_buf(args);
			break;
		case 2:
			built(args, dynamic);
			if (args)
				free_buf(args);
			break;
		default:
			cmd_not_found(pname, command_num, args[0]);
			fflush(stderr);
			if (dynamic->ptr1)
				free_buf(dynamic->ptr1);
			if (dynamic->ptr2)
				free_buf(dynamic->ptr2);
			free(dynamic);
			if (args)
				free_buf(args);
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
	ref_t *dynamic_ref = malloc(sizeof(ref_t));

	dynamic_ref->ptr3 = path;
	str = _readline(&command_num, isaty, dynamic_ref);
	args_all = _tokenize(str, "#");
	args_semi = _tokenize(args_all[0], ";");
	dynamic_ref->ptr1 = args_all;
	dynamic_ref->ptr2 = args_semi;
	free(str);
	for (semi_len = 0; args_semi[semi_len]; semi_len++)
		continue;
	if (semi_len > 1)
	{
		for (i = 0; args_semi[i]; i++)
			inner_process(args_semi[i], path, pname, command_num, dynamic_ref);
	}
	else
	{
		inner_process(args_all[0], path, pname, command_num, dynamic_ref);
	}
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
	ref_t *dynamic_ref = malloc(sizeof(ref_t));

	str = read_textfile(fname, MAX_LENGTH);
	args_all = _tokenize(str, "\n");
	for (i = 0; args_all[i]; i++)
		inner_process(args_all[i], path, pname, command_num, dynamic_ref);
}
