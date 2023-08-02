#include "main.h"
#include "main.h"

/**
  * isnum - check for numbers
  * @a: character to test
  * Return: 1 if number 0 otherwise
  */
int isnum(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

/**
  * hyphens - check number of minus signs
  * @string: string to check
  * @i: where the iteration stopped
  * Return: number of hyphens
  */
int hyphens(char *string, int *i)
{
	char *str = string;
	int sum = 0;

	while (!isnum(*str) && *str != '\0')
	{
		(*i)++;
		if (*str++ == '-')
			sum++;
	}
	return (sum);
}

/**
 * _dtos - integer to string.
 * @d: integer to convert
 * Return: char pointer
 */

char *_dtos(long d)
{
	int len = 1;
	int sign = 0;
	int i = 0;
	int ent;
	long div = 10;
	char *buff;

	if (d < 0)
	{
		sign = 1;
		d = -d;
	}
	while (d / div > 0)
	{
		div *= 10;
		len++;
	}
	buff = malloc(sizeof(char) * len + sign + 1);
	if (sign)
		buff[i++] = '-';
	while (div > 1)
	{
		div /= 10;
		ent = d / div;
		buff[i++] = '0' + (ent % 10);
	}
	buff[i] = '\0';
	return (buff);
}

/**
  * _atoi - convert a string to integer
  * @s: string to convert
  * Return: integer that is converted
  */

int _atoi(char *s)
{
	int i = 0, num, mul = 1;
	unsigned int ans = 0;
	char *a = s;

	num = hyphens(a, &i);

	a += i;
	while (isnum(*++a) && *a != '\0')
		mul *= 10;

	s += i;
	while (isnum(*s) && *s != '\0')
	{
		ans += (*s++ - '0') * mul;
		mul /= 10;
	}
	if (num % 2)
		return (-((unsigned int)ans));
	return (ans);
}

/**
  * init_ref - initialize ref_t structure.
  * @ref: dynamic reference to init.
  * @command_number: command number.
  * @exit_status: exit status.
  * @argc: argument count.
  * @argv: argument vector.
  * @current_command: current command.
  * @path: path env.
  */
void init_ref(ref_t *ref, unsigned int command_number, int exit_status,
		int argc, char *file_name, char **current_command,
		char **argv, char **path)
{
	ref->command_number = command_number;
	ref->exit_status = exit_status;
	ref->argc = argc;
	ref->file_name = file_name;
	ref->current_command = current_command;
	ref->argv = argv;
	ref->path = path;
}
