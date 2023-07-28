#include "main.h"


int _isdigit(int c);

/**
 * _ext - our own exit built-in command
 * @arg: parameter to hold user input
 * @dynamic: dynamic reference.
 * Return: Always 0
 */

int _ext(char **arg, ref_t *dynamic)
{
	int i = 0;
	int status = 0;

	if (arg[1])
	{
		if (arg[1][0] == '-')
		{
			free_buf(arg);
			if (dynamic->ptr1)
				free_buf(dynamic->ptr1);
			if (dynamic->ptr2)
				free_buf(dynamic->ptr2);
			if (dynamic->ptr3)
				free_buf(dynamic->ptr3);
			free(dynamic);
			exit(EXIT_FAILURE);
		}
		while (arg[1][i])
		{
			if (_isdigit(arg[1][i]) == -1)
			{
				free_buf(arg);
				if (dynamic->ptr1)
					free_buf(dynamic->ptr1);
				if (dynamic->ptr2)
					free_buf(dynamic->ptr2);
				if (dynamic->ptr3)
					free_buf(dynamic->ptr3);
				free(dynamic);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		status = _atoi(arg[1]);
		if (status == -1)
			exit(2);
	}

	free_buf(arg);
	if (dynamic->ptr1)
		free_buf(dynamic->ptr1);
	if (dynamic->ptr2)
		free_buf(dynamic->ptr2);
	if (dynamic->ptr3)
		free_buf(dynamic->ptr3);
	free(dynamic);
	exit(EXIT_SUCCESS);

}

/**
 * _isdigit - checks digit.
 * @c: input to be checked.
 * Return: 0 on success, -1 on failure
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	else
		return (-1);
}
