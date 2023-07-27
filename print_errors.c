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
