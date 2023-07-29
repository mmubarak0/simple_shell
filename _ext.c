#include "main.h"


int _isdigit(int c);

/**
 * _ext - our own exit built-in command
 * @arg: parameter to hold user input
 * @dynamic: dynamic reference.
 * @pname: program name.
 * Return: Always 0
 */

int _ext(char **arg, ref_t *dynamic, char *pname)
{
	int i = 0;
	int status = 0;

	if (arg[1])
	{
		if (arg[1][0] == '-')
		{
			print_illegal_number(arg, pname);
			free_buf(arg);
			if (dynamic->ptr1)
				free_buf(dynamic->ptr1);
			if (dynamic->ptr2)
				free_buf(dynamic->ptr2);
			if (dynamic->ptr3)
				free_buf(dynamic->ptr3);
			free(dynamic);
			exit(2);
		}
		while (arg[1][i])
		{
			if (_isdigit(arg[1][i]) == -1)
			{
				print_illegal_number(arg, pname);
				free_buf(arg);
				if (dynamic->ptr1)
					free_buf(dynamic->ptr1);
				if (dynamic->ptr2)
					free_buf(dynamic->ptr2);
				if (dynamic->ptr3)
					free_buf(dynamic->ptr3);
				free(dynamic);
				exit(2);
			}
			i++;
		}
		status = _atoi(arg[1]);
	}

	free_buf(arg);
	if (dynamic->ptr1)
		free_buf(dynamic->ptr1);
	if (dynamic->ptr2)
		free_buf(dynamic->ptr2);
	if (dynamic->ptr3)
		free_buf(dynamic->ptr3);
	free(dynamic);
	if (status == 0)
		exit(get_err_code());
	exit(status);
}

/**
 * _isdigit - checks digit.
 * @c: input to be checked.
 * Return: 0 on success, -1 on failure
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	else
		return (-1);
}
