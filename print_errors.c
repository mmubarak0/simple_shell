#include "main.h"

/**
  * cmd_not_found - print command not found error.
  * @pname: program name.
  * @command_num: command execution number.
  * @command: command to be executed.
  */
void cmd_not_found(char *pname, int command_num, char *command)
{
	print_s(pname);
	print_c(':');
	print_c(' ');
	print_d(command_num);
	print_c(':');
	print_c(' ');
	print_s(command);
	print_c(':');
	print_c(' ');
	print_s("not found\n");
}
