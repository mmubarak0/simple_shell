#include "main.h"

/**
  * _empty_input - check for empty inputs.
  * @str: string of input.
  * Return: 1 if empty and 0 otherwise.
  */
int _empty_input(char *str)
{
	int i;

	if (!str)
		return (1);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		i++;
	if (i == _strlen(str))
		return (1);
	return (0);
}
