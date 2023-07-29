#include "main.h"

/**
  * cmd_not_found - print command not found error.
  * @pname: program name.
  * @command_num: command execution number.
  * @command: command to be executed.
  */
void cmd_not_found(char *pname, int command_num, char *command)
{
	print_s(pname, STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_d(command_num, STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s(command, STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s("not found\n", STDERR_FILENO);
}

/**
  * print_illegal_number - print illegal number error.
  * @args: argument of the command.
  * @pname: program name.
  */
void print_illegal_number(char **args, char *pname)
{
	print_s(pname, STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_d(get_cmd_num(), STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s(args[0], STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s("Illegal number", STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s(args[1], STDERR_FILENO);
	print_c('\n', STDERR_FILENO);
}

/**
  * file_not_found - print file not found error.
  * @pname: program name.
  * @fname: file name.
  */
void file_not_found(char *pname, char *fname)
{
	print_s(pname, STDERR_FILENO);
	print_c(':', STDERR_FILENO);
	print_c(' ', STDERR_FILENO);
	print_s("0: ", STDERR_FILENO);
	print_s("Can't open ", STDERR_FILENO);
	print_s(fname, STDERR_FILENO);
	print_c('\n', STDERR_FILENO);
}
